

/*
===========================================================
 ATM SYSTEM – LOW LEVEL DESIGN
===========================================================

OVERVIEW:
This design models a basic Automated Teller Machine (ATM)
used for common banking operations.

The focus is on:
- User interaction flow
- State transitions
- Separation of responsibilities
- Safe handling of money & failures

The ATM is treated as a state-driven system where
each user action moves the machine from one state
to another.

-----------------------------------------------------------
CORE FUNCTIONALITIES:
The ATM supports:
- Card insertion and validation
- PIN authentication
- Account selection
- Cash withdrawal
- Balance inquiry
- Receipt printing
- Card ejection

-----------------------------------------------------------
USER FLOW (HIGH LEVEL):
1. User inserts card
2. ATM validates card
3. User enters PIN
4. ATM authenticates user
5. User selects an operation
6. Transaction is processed
7. Receipt is printed (optional)
8. Card is ejected

-----------------------------------------------------------
KEY DESIGN IDEAS:
- ATM controls the interaction flow
- Bank systems handle actual account data
- ATM does NOT store user balances
- Transactions must be atomic (all-or-nothing)
- Failures must leave the system in a safe state

-----------------------------------------------------------
FAILURE SCENARIOS HANDLED:
- Wrong PIN attempts
- Insufficient account balance
- ATM out of cash
- Network failure
- User timeout or cancellation
- Card retention for security reasons

-----------------------------------------------------------
DESIGN GOAL:
Create a clean, extensible design that:
- Avoids complex conditional logic
- Clearly separates concerns
- Models real-world ATM behavior
- Is easy to extend with new features

===========================================================
*/


#include<iostream>

using namespace std;

