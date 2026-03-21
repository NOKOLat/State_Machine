# ファイル構造

```text
Core/
├── Inc/
│   ├── Safety/
│   │   ├── SafetyManager.hpp     ← 中核（FSM統合）
│   │   ├── State.hpp             ← 抽象State
│   │   ├── States.hpp            ← 各状態まとめ
│   │   └── StateId.hpp           ← 状態ID定義
│   │
│   ├── Common/
│   │   ├── FlightData.hpp
│   │   ├── ControlData.hpp
│   │   └── SystemContext.hpp     ← 状態間共有データ
│   │
│   └── Debug/
│       └── Log.hpp               ← ログ（PC/STM32切替）
│
├── Src/
│   └── Safety/
│       └── SafetyManager.cpp     ← 実装
```