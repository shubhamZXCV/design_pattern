// observer [behaviourial pattern] -> stock price notification system

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// observer interface
class Observer{
private:
public:
    virtual void update(float price) = 0;
    virtual ~Observer(){};
};

// subject interface
class Subject{
private:
public:
    virtual void attach(Observer* obs)=0;
    virtual void detach(Observer* obs)=0;
    virtual void notify(float price)=0;
    virtual ~Subject(){}
};

// concrete subject -> stock
class Stock : public Subject{
private:
    vector<Observer*>observers;
    float price;
public:
    void attach(Observer* obs) override{
        observers.push_back(obs);
    }
    void detach(Observer* obs) override{
        observers.erase(remove(observers.begin(),observers.end(),obs),observers.end());
    }

    void notify(float newPrice) override{
        for(auto & obs : observers){
            obs->update(newPrice);
        }
    }

    void setPrice(float newPrice){
        this->price = newPrice;
        notify(newPrice);
    }

};

class Investor: public Observer{
private:
    string name;
public:
    Investor(string n) : name(n) {} 
    void update(float price)override{
        cout << "Investor " << name 
             << " notified. New stock price: " 
             << price << endl;
    }
};



int main(){
    Observer * inv1 = new Investor("jhunjhunwala");
    Observer* inv2 = new Investor("warren buffet");

    Stock* stock1 = new Stock();
    stock1->attach(inv1);
    stock1->attach(inv2);

    stock1->setPrice(100.00);

    stock1->detach(inv2);

    stock1->setPrice(200.00);
    return 0;
}