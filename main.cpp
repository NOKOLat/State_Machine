#include <iostream>
#include <thread>
#include <chrono>

#define PC_DEBUG

#include "Safety/SafetyManager.hpp"
#include "Safety/HeadersofState.hpp"
#include "Debug/CsvLogger.hpp"

int main() {
    SafetyManager sm;
    CsvLogger logger;

    // ==========================
    // 初期化
    // ==========================

    if (!logger.open("log.csv")) {
        std::cerr << "Failed to open log file\n";
        return -1;
    }

    logger.writeHeader();

    // ==========================
    // テストループ
    // ==========================
    for (int i = 0; i < 50; ++i) {

        // ---- 疑似入力 ----
        if (i == 5) {
            sm.ctx().armRequest = true;
        }

        if(i == 15) {
            sm.ctx().armRequest = false;
        }

        if (i == 25) {
            sm.ctx().errorFlag = true;
        }

        // ---- 更新 ----
        sm.update();

        // ---- ログ保存 ----
        logger.log(sm.getState(), sm.ctx());

        // ---- 時間更新（100ms周期）----
        logger.tick(100);

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    logger.close();

    std::cout << "Log saved to log.csv\n";
    return 0;
}