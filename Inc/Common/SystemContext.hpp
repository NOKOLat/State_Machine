#ifndef SYSTEMCONTEXT_HPP
#define SYSTEMCONTEXT_HPP

#include "DataTypes.hpp"

struct SystemContext {
    SensorData sensor;
    ControlData control;

    bool armRequest = false;
    bool errorFlag = false;
};

#endif /* SYSTEMCONTEXT_HPP */