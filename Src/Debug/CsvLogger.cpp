#include "Debug/CsvLogger.hpp"

bool CsvLogger::open(const std::string& filename) {
    file.open(filename);
    return file.is_open();
}

void CsvLogger::writeHeader() {
    file << "time_ms,state,arm,error,throttle\n";
}

static const char* stateToStr(StateId id) {
    switch (id) {
        case StateId::Idle: return "Idle";
        case StateId::Armed: return "Armed";
        case StateId::Error: return "Error";
        default: return "Unknown";
    }
}

void CsvLogger::log(StateId state, const SystemContext& ctx) {
    if (!file.is_open()) return;

    file << time_ms << ","
         << stateToStr(state) << ","
         << ctx.armRequest << ","
         << ctx.errorFlag << ","
         << ctx.control.throttle
         << "\n";
}

void CsvLogger::close() {
    if (file.is_open()) file.close();
}