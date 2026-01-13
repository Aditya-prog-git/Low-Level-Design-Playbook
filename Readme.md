# 🚀 Low Level Design Practice – Design Patterns in C++

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue" />
  <img src="https://img.shields.io/badge/Domain-Low%20Level%20Design-purple" />
  <img src="https://img.shields.io/badge/Patterns-Strategy%20%7C%20Factory%20%7C%20Singleton%20%7C%20Observer-green" />
  <img src="https://img.shields.io/badge/Target-Fresher%20%26%20Junior%20Engineers-success" />
</p>

---

## 🌍 Overview

This repository contains **Low Level Design (LLD)** implementations written in **C++**, focusing on **core object-oriented design patterns** commonly evaluated in **on-campus, fresher, and junior backend interviews**.

The emphasis is **not on frameworks**, but on:

- ✅ Clean object-oriented design  
- ✅ Pattern-driven problem solving  
- ✅ Interview-explainable architecture  
- ✅ Avoiding premature over-engineering  

All implementations are **console-based**, intentionally minimal, and designed to clearly highlight **why a pattern is used**, not just *how* it is coded.

---

## 🎯 Goals of This Repository

- Build strong intuition for **when to apply a design pattern**
- Learn to identify **change-prone areas** in a system
- Practice **extensible and maintainable design**
- Prepare for **LLD rounds and whiteboard interviews**
- Create a reusable personal reference for system design fundamentals

---

## 🧩 Design Patterns Covered

| Pattern | Core Idea |
|-------|-----------|
| **Strategy** | Encapsulate interchangeable behavior |
| **Factory** | Centralize and abstract object creation |
| **Singleton** | Maintain a single shared instance |
| **Observer** | Enable event-driven communication |

> 💡 These four patterns alone cover a **majority of fresher-level LLD interview scenarios**.

---

## 🗂️ Repository Structure

```text
.
├── factory/
│   ├── factory_basic_pattern.cpp
│   └── factoryDesignPattern.pdf
│
├── observer/
│   ├── observer_basic_pattern.cpp
│   └── real_world_example.pdf
│
├── singleton/
│   └── singleton_basic_pattern.cpp
│
├── strategy/
│   ├── strategy_basic_pattern.cpp
│   ├── strategy_payment.cpp
│   ├── strategy_sorting.cpp
│   ├── strategy_payment.exe
│   └── sorting.exe
│
├── real_world_examples/
│   ├── ATM_Automatic_Teller_Machine.cpp
│   ├── ParkingLot.cpp
│   ├── VendingMachine.cpp
│   ├── PubSubSystem.cpp        // (upcoming)
│   └── RideBookingSystem.cpp   // (upcoming)
│
├── .gitignore
└── README.md
