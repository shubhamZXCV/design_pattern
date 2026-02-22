// strategy (behaviorial design pattern)

#include<iostream>

using namespace std;

// strategy interface

class PaymentStrategy{
public:
    virtual void pay()=0;
    virtual ~PaymentStrategy(){};
};

// concrete stragies

class CreditCardPayment : public PaymentStrategy{
public:
    void pay() override{
        cout << "paid using credit card" << endl;
        return;
    }
};

class UPIPayment : public PaymentStrategy{
public:
    void pay() override{
        cout << "paid using upi" << endl;
        return;
    }
};

class PayPalPayment: public PaymentStrategy{
    public:
        void pay() override{
            cout << "paid using paypal" << endl;
            return;
        }
};

// context

class PaymentProcessor{
private:
    PaymentStrategy * strategy;
public:
    void setStrategy(PaymentStrategy * strategy){
        this->strategy = strategy;
    }

    void pay(){
        strategy->pay();
    }
};

int main(){
    CreditCardPayment* strategy = new CreditCardPayment();
    PaymentProcessor* processor  = new PaymentProcessor();

    processor->setStrategy(strategy);
    processor->pay();

    return 0;
}