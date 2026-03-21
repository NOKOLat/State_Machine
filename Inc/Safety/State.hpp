#pragma once
#include <memory>
#include "StateId.hpp"

class SafetyManager;

class State {
public:
    virtual ~State() = default;

    virtual StateId getId() const = 0;

    virtual std::unique_ptr<State> update(SafetyManager& sm) = 0;

    virtual void onEnter(SafetyManager& sm) {}
    virtual void onExit(SafetyManager& sm) {}
};