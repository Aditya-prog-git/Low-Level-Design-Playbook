🚀 Low Level Design Practice – Design Patterns in C++
<p align="center"> <img src="https://img.shields.io/badge/Language-C%2B%2B-blue" /> <img src="https://img.shields.io/badge/Domain-Low%20Level%20Design-purple" /> <img src="https://img.shields.io/badge/Patterns-Strategy%20|%20Factory%20|%20Singleton%20|%20Observer-green" /> <img src="https://img.shields.io/badge/Target-Fresher%20%26%20Junior%20Engineers-success" /> </p>
🌍 Overview

This repository contains Low Level Design (LLD) implementations written in C++, focusing on core object-oriented design patterns that are commonly evaluated in on-campus, fresher, and junior backend interviews.

The emphasis is not on frameworks, but on:

Clean object-oriented design

Pattern-driven problem solving

Interview-explainable architecture

Avoiding premature over-engineering

All implementations are console-based, intentionally minimal, and designed to clearly highlight why a pattern is used, not just how it is coded.

🎯 Goals of This Repository

Build strong intuition for when to apply a design pattern

Learn to identify change-prone areas in a system

Practice extensible and maintainable design

Prepare for LLD rounds and whiteboard interviews

Create a reusable personal reference for system design fundamentals

🧩 Design Patterns Covered
Pattern	Core Idea
Strategy	Encapsulate interchangeable behavior
Factory	Centralize and abstract object creation
Singleton	Maintain a single shared instance
Observer	Enable event-driven communication

These four patterns alone cover a majority of fresher-level LLD interview scenarios.

🗂️ Repository Structure
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


Each folder is self-contained and can be explored independently.

🧪 Pattern-Wise Implementations
🔹 Strategy Pattern

Location: strategy/

Use Cases Implemented:

Payment methods (UPI / Card)

Sorting algorithms (runtime selection)

Why Strategy?
Applied when business logic varies, but the overall workflow remains constant.

🔹 Factory Pattern

Location: factory/

Use Cases Implemented:

Centralized object creation

Input-based object selection

Why Factory?
Prevents object creation logic from spreading across the codebase.

🔹 Singleton Pattern

Location: singleton/

Use Cases Implemented:

Shared resource management

Why Singleton?
Used when a single source of truth is required (configuration, cache, DB manager).

🔹 Observer Pattern

Location: observer/

Use Cases Implemented:

Event notification system

Publisher-subscriber relationship

Why Observer?
Ideal for event-driven architectures where components should remain loosely coupled.

🏗️ Real-World LLD Implementations
1️⃣ Vending Machine

File: real_world_examples/VendingMachine.cpp
Patterns Used: Factory, Strategy, Singleton

Key Design Decisions:

Product creation via Factory

Pricing logic via Strategy

Inventory handled as a singleton

2️⃣ Parking Lot System

File: real_world_examples/ParkingLot.cpp
Patterns Used: Factory, Strategy, Singleton

Key Design Decisions:

Vehicle-based slot allocation

Flexible pricing models

Centralized parking state management

3️⃣ ATM System

File: real_world_examples/ATM_Automatic_Teller_Machine.cpp
Patterns Used: Strategy, Singleton

Key Design Decisions:

Transaction rules encapsulated as strategies

Account data managed centrally

🔜 Upcoming Implementations

Pub/Sub System

Observer + Singleton

Ride Booking System (Uber-Lite)

Strategy + Factory + Singleton + Observer

🧠 Interview Readiness

This repository prepares you to confidently:

Justify pattern selection

Explain design trade-offs

Identify extension points

Walk through LLD solutions step-by-step

Example explanation:

“I used Strategy here because pricing rules are expected to change frequently, and this allows new rules to be added without modifying the core business flow.”

▶️ How to Run

Navigate to any folder

Compile the .cpp file using a C++ compiler

g++ filename.cpp -o output


Run the executable

./output


No external dependencies required.

🔮 Future Enhancements

Introduce State Pattern (ATM, Elevator)

Add Adapter Pattern examples

Improve CLI interaction flows

Add basic unit testing

Document class diagrams

👤 Author

Aditya
Computer Science Engineering
Focused on Backend Development, Low Level Design & Scalable Systems

“Design patterns are not about complexity — they are about controlling change.”

⭐ If you found this repository useful, consider giving it a star.
