// command (behaviourial)

#include<iostream>
using namespace std;

// command interface

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};


// Reciever (actual worker)
class Light {
public:
    void turnOn() {
        cout << "Light is ON\n";
    }

    void turnOff() {
        cout << "Light is OFF\n";
    }
};

// concrete commands

class LightOnCommand : public Command {
private:
    Light* light;
public:
    LightOnCommand(Light* l) : light(l) {}

    void execute() override {
        light->turnOn();
    }
};

class LightOffCommand : public Command {
private:
    Light* light;
public:
    LightOffCommand(Light* l) : light(l) {}

    void execute() override {
        light->turnOff();
    }
};

// invoker

class RemoteControl {
private:
    Command* command;
public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void pressButton() {
        command->execute();
    }
};

// client code

int main() {

    Light livingRoomLight;

    LightOnCommand lightOn(&livingRoomLight);
    LightOffCommand lightOff(&livingRoomLight);

    RemoteControl remote;

    remote.setCommand(&lightOn);
    remote.pressButton();   // Light is ON

    remote.setCommand(&lightOff);
    remote.pressButton();   // Light is OFF

    return 0;
}

