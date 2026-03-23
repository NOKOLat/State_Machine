# ファイル構造

```text
.
├── Inc
│   ├── Common
│   │   ├── DataTypes.hpp
│   │   └── SystemContext.hpp
│   ├── Debug
│   │   ├── CsvLogger.hpp
│   │   └── Log.hpp
│   └── Safety
│       ├── HeadersofState.hpp
│       ├── SafetyManager.hpp
│       ├── State.hpp
│       └── StateId.hpp
├── Src
│   ├── Debug
│   │   └── CsvLogger.cpp
│   └── Safety
│       └── SaetyManager.cpp
├── .gitignore
├── main.cpp
└── Readme.md
```

# 実行方法
## log.csv を生成するコマンド

このディレクトリ内のすべての`.cpp`ファイルを実行の対象に設定する。

```bash
g++ main.cpp Src/Safety/SafetyManager.cpp Src/Debug/CsvLogger.cpp \
-I Inc -std=c++17 -o test && ./test
```

このコマンドによって、

1. ターミナルに状態のログが出力される
2. プロジェクトルートに`log.csv`が生成される
