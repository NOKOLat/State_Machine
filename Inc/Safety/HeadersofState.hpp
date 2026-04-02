#ifndef HEADERS_OF_STATE_HPP
#define HEADERS_OF_STATE_HPP
#include "State.hpp"
#include "SafetyManager.hpp"
#include "Debug/Log.hpp"

// 前方宣言
class IdleState;
class ArmedState;
class ErrorState;

// Factory function declarations
inline std::unique_ptr<State> createIdleState();
inline std::unique_ptr<State> createArmedState();
inline std::unique_ptr<State> createErrorState();

// ==============================
// Idle
// ==============================
class IdleState : public State {
public:
    StateId getId() const override { return StateId::Idle; }

    void onEnter(SafetyManager& sm) override {

        LOG("Enter Idle");
        sm.ctx().control.throttle = 0;
    }

    std::unique_ptr<State> update(SafetyManager& sm) override {

        if (sm.ctx().armRequest) {
            return createArmedState();
        }

        return nullptr; //状態遷移不要
    }
};

// ==============================
// Armed
// ==============================
class ArmedState : public State {
public:
    StateId getId() const override { return StateId::Armed; }

    void onEnter(SafetyManager& sm) override {

        LOG("Motors ON");
    }

    void onExit(SafetyManager& sm) override {

        LOG("Motors OFF");
    }

    std::unique_ptr<State> update(SafetyManager& sm) override {
        if(!sm.ctx().armRequest) {
            return createIdleState();
        }
        if (sm.ctx().errorFlag) {
            return createErrorState();
        }
        return nullptr; //状態遷移不要
    }
};

// ==============================
// Error
// ==============================
class ErrorState : public State {
public:
    StateId getId() const override { return StateId::Error; }

    void onEnter(SafetyManager& sm) override {
        LOG("FAILSAFE");
        sm.ctx().control.throttle = 0;
    }

    std::unique_ptr<State> update(SafetyManager&) override {

        return nullptr; //ErrorState からは状態遷移しない
    }
};

// ==============================
// Factory functions
// ==============================
inline std::unique_ptr<State> createIdleState() {
    return std::make_unique<IdleState>();
}

inline std::unique_ptr<State> createArmedState() {
    return std::make_unique<ArmedState>();
}

inline std::unique_ptr<State> createErrorState() {
    return std::make_unique<ErrorState>();
}

#endif /* HEADERS_OF_STATE_HPP */