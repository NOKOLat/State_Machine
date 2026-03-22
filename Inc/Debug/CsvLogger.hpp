#ifndef CSVLOGGER_HPP
#define CSVLOGGER_HPP
#include <fstream>
#include <string>
#include <cstdint>

#include "../Safety/StateId.hpp"
#include "../Common/SystemContext.hpp"

class CsvLogger {
private:
    std::ofstream file;
    uint32_t time_ms = 0;

public:
    bool open(const std::string& filename);

    void writeHeader();

    void log(StateId state, const SystemContext& ctx);

    void close();

    void tick(uint32_t dt_ms) { time_ms += dt_ms; }
};
#endif /* CSVLOGGER_HPP */