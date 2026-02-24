// chain of responsibilities (behaviourial)

// handler base class

#include <iostream>
using namespace std;

class DispenseHandler {
protected:
    DispenseHandler* next;

public:
    DispenseHandler() : next(nullptr) {}

    void setNext(DispenseHandler* nextHandler) {
        next = nextHandler;
    }

    virtual void dispense(int amount) = 0;
};

// concrete handlers

class Rupee2000Handler : public DispenseHandler {
public:
    void dispense(int amount) override {
        if (amount >= 2000) {
            int notes = amount / 2000;
            cout << "Dispensing " << notes << " x 2000\n";
            amount %= 2000;
        }
        if (amount > 0 && next)
            next->dispense(amount);
    }
};

class Rupee500Handler : public DispenseHandler {
public:
    void dispense(int amount) override {
        if (amount >= 500) {
            int notes = amount / 500;
            cout << "Dispensing " << notes << " x 500\n";
            amount %= 500;
        }
        if (amount > 0 && next)
            next->dispense(amount);
    }
};

class Rupee100Handler : public DispenseHandler {
public:
    void dispense(int amount) override {
        if (amount >= 100) {
            int notes = amount / 100;
            cout << "Dispensing " << notes << " x 100\n";
        }
    }
};

// client code
int main() {

    DispenseHandler* h2000 = new Rupee2000Handler();
    DispenseHandler* h500  = new Rupee500Handler();
    DispenseHandler* h100  = new Rupee100Handler();

    // Creating chain
    h2000->setNext(h500);
    h500->setNext(h100);

    int amount = 3700;
    cout << "Requesting: " << amount << endl;

    h2000->dispense(amount);

    return 0;
}