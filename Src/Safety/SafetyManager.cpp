#include "Safety/SafetyManager.hpp"
#include "Safety/HeadersofState.hpp"

void SafetyManager::forceTransition(StateId id) {
    if (currentState && currentState->getId() == id) return;

    currentState->onExit(*this);

    switch (id) {
        case StateId::Idle:
            currentState = std::make_unique<IdleState>();
            break;
        case StateId::Armed:
            currentState = std::make_unique<ArmedState>();
            break;
        case StateId::Error:
        default:
            currentState = std::make_unique<ErrorState>();
            break;
    }

    currentState->onEnter(*this);
}