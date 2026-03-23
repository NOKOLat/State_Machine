# ファイル構造

```text
Core/
├── Inc/
│   ├── Safety/
│   │   ├── SafetyManager.hpp
│   │   ├── State.hpp
│   │   ├── States.hpp
│   │   └── StateId.hpp
│   │
│   ├── Common/
│   │   ├── FlightData.hpp
│   │   ├── ControlData.hpp
│   │   └── SystemContext.hpp
│   │
│   └── Debug/
│       ├── Log.hpp
│       └── CsvLogger.hpp   ← ★追加
│
├── Src/
│   └── Debug/
│       └── CsvLogger.cpp   ← ★追加
│
└── main.cpp
```

# 実行方法
## log.csv を生成するコマンド

このディレクトリ内のすべての`.cpp`ファイルを実行の対象に設定する。

```bash
g++ main.cpp Src/Safety/SafetyManager.cpp Src/Debug/CsvLogger.cpp \
-I Inc -std=c++17 -o test
```

このコマンドによって、

1. ターミナルに状態のログが出力される
2. プロジェクトルートに`log.csv`が生成される
