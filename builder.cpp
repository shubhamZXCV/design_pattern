// builder (creational pattern)

#include<iostream>

using namespace std;

// product class

class House {
private:
    string walls;
    string roof;
    bool garage;
    bool swimmingPool;

public:
    void setWalls(string w) { walls = w; }
    void setRoof(string r) { roof = r; }
    void setGarage(bool g) { garage = g; }
    void setSwimmingPool(bool s) { swimmingPool = s; }

    void show() {
        cout << "House with:\n";
        cout << "Walls: " << walls << endl;
        cout << "Roof: " << roof << endl;
        cout << "Garage: " << (garage ? "Yes" : "No") << endl;
        cout << "Swimming Pool: " << (swimmingPool ? "Yes" : "No") << endl;
    }
};

// builder interface

class HouseBuilder {
public:
    virtual HouseBuilder& setWalls(string walls) = 0;
    virtual HouseBuilder& setRoof(string roof) = 0;
    virtual HouseBuilder& setGarage(bool garage) = 0;
    virtual HouseBuilder& setSwimmingPool(bool pool) = 0;
    virtual House build() = 0;
    virtual ~HouseBuilder() = default;
};

// concrete builder

class ConcreteHouseBuilder : public HouseBuilder {
private:
    House house;

public:
    HouseBuilder& setWalls(string walls) override {
        house.setWalls(walls);
        return *this;
    }

    HouseBuilder& setRoof(string roof) override {
        house.setRoof(roof);
        return *this;
    }

    HouseBuilder& setGarage(bool garage) override {
        house.setGarage(garage);
        return *this;
    }

    HouseBuilder& setSwimmingPool(bool pool) override {
        house.setSwimmingPool(pool);
        return *this;
    }

    House build() override {
        return house;
    }
};



int main(){
ConcreteHouseBuilder builder;

    House house = builder
                    .setWalls("Brick")
                    .setRoof("Concrete")
                    .setGarage(true)
                    .setSwimmingPool(false)
                    .build();

    house.show();

    return 0;
}