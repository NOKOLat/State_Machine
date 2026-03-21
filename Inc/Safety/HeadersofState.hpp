#ifndef HEADERS_OF_STATE_HPP
#define HEADERS_OF_STATE_HPP
#include "State.hpp"
#include "SafetyManager.hpp"
#include "Debug/Log.hpp"

// 前方宣言
class IdleState;
class ArmedState;
class ErrorState;

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
            return std::make_unique<ArmedState>();
        }
        return nullptr;
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
        if (sm.ctx().errorFlag) {
            return std::make_unique<ErrorState>();
        }
        return nullptr;
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
        return nullptr;
    }
};

#endif /* HEADERS_OF_STATE_HPP */