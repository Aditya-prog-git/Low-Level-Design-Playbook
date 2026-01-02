#include<iostream>
using namespace std;

/*
=====================================================
STRATEGY PATTERN – PAYMENT METHOD EXAMPLE
=====================================================

Problem:
- An application supports multiple payment methods
- User can choose payment method at runtime
- We want to avoid if-else / switch statements

Solution:
- Use Strategy Pattern
*/

/*
-----------------------------------------------------
STRATEGY INTERFACE
-----------------------------------------------------
- Declares common behavior for all payment methods
- Any payment method must implement `pay()`
*/
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;   // common payment operation
    virtual ~PaymentStrategy() {}        // virtual destructor
};

/*
-----------------------------------------------------
CONCRETE STRATEGIES
-----------------------------------------------------
- Each class represents ONE payment method
- Each class implements its own payment logic
*/

// Credit Card Payment Strategy
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card" << endl;
    }
};

// UPI Payment Strategy
class UpiPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using UPI" << endl;
    }
};

// PayPal Payment Strategy
class PaypalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using PayPal" << endl;
    }
};

/*
-----------------------------------------------------
CONTEXT CLASS
-----------------------------------------------------
- Uses a PaymentStrategy to perform payment
- Does NOT know which payment method is used
- Payment method can be changed at runtime
*/
class PaymentContext {
private:
    PaymentStrategy* strategy;   // pointer to strategy interface

public:
    // Constructor injects the initial payment strategy
    PaymentContext(PaymentStrategy* strategy) {
        this->strategy = strategy;
    }

    // Allows changing payment method at runtime
    void setPaymentMethod(PaymentStrategy* strategy) {
        this->strategy = strategy;
    }

    // Executes the selected payment strategy
    void checkout(int amount) {
        strategy->pay(amount);
    }
};

/*
-----------------------------------------------------
MAIN FUNCTION (CLIENT CODE)
-----------------------------------------------------
*/
int main() {

    // Initial payment using Credit Card
    PaymentContext payment(new CreditCardPayment());
    payment.checkout(1000);

    // Switch payment method to UPI
    payment.setPaymentMethod(new UpiPayment());
    payment.checkout(500);

    // Switch payment method to PayPal
    payment.setPaymentMethod(new PaypalPayment());
    payment.checkout(200);

    return 0;
}