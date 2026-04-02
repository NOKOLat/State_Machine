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
## 1. ビルド

```bash
make
```

## 2. 実行
```bash
make run
```

## 3. ビルド成果物削除
```bash
make clean
```