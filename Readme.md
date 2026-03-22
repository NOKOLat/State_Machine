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