

// factory [creational] -> Vehicle factory
#include<iostream>

using namespace std;


// product interface

class Vehicle{
private:
public:
    virtual void drive()=0;
    virtual ~Vehicle(){};
};

// concrete product

class Car : public Vehicle{
public:
    void drive() override{
        cout << "i am driving a car" << endl;
    }
};

class Bike : public Vehicle{
public:
    void drive() override{
        cout << "i am driving a bike" << endl;
    }
};

// factory

class VehicleFactory{
private:
public:
    static Vehicle* createVehicle(string name){
        if(name == "car"){
            return new Car();
        }else if(name == "bike"){
            return new Bike();
        }else{
            return nullptr;
        }
    }
};

int main(){
    Vehicle* car = VehicleFactory::createVehicle("car");
    Vehicle* bike = VehicleFactory::createVehicle("bike");

    if(car) car->drive();
    if(bike) bike->drive();

    delete car;
    delete bike;

    return 0;
}