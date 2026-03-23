#ifndef SAFETY_MANAGER_HPP
#define SAFETY_MANAGER_HPP
#include <memory>
#include "State.hpp"
// #include "StateId.hpp" 
// #include "HeadersofState.hpp"
#include "Common/SystemContext.hpp"

class SafetyManager {
private:
    std::unique_ptr<State> currentState;
    SystemContext context;

public:

    SafetyManager(){

        // 初期状態はIdle
        currentState = std::make_unique<IdleState>();
        currentState->onEnter(*this);
    }

    // ==========================
    // 初期化
    // ==========================
    void init(std::unique_ptr<State> initState) {
        currentState = std::move(initState);
        if (currentState) currentState->onEnter(*this);
    }

    // ==========================
    // 状態更新
    // ==========================
    void changeState(std::unique_ptr<State> newState) {

        if(!newState) {
            return;
        }
        else {

            if (currentState){

                currentState->onExit(*this);
            }

            currentState = std::move(newState);
            printf("State changed to %d\n", static_cast<int>(currentState->getId()));
            currentState->onEnter(*this);
        }

    }

    // ==========================
    // 更新（周期実行）
    // ==========================
    void update() {
        if (!currentState) return;

        // セーフティ監視（全状態共通）
        checkSafety();

        // 状態更新
        std::unique_ptr<State> next = currentState->update(*this);

        // if (next) {
            changeState(std::move(next));
            // currentState->onExit(*this);
            // currentState = std::move(next);
            // currentState->onEnter(*this);
        // }
    }

    // ==========================
    // セーフティチェック
    // ==========================
    void checkSafety() {
        if (context.errorFlag) {
            forceTransition(StateId::Error);
        }
    }

    // ==========================
    // 強制遷移（フェイルセーフ）
    // ==========================
    void forceTransition(StateId id);

    // ==========================
    // Contextアクセス
    // ==========================
    SystemContext& ctx() { return context; }

    StateId getState() const {
        return currentState ? currentState->getId() : StateId::Error;
    }
};

#endif /* SAFETY_MANAGER_HPP */