/**
 * 
 * Strategy Design Pattern - check notes
 * Basically, it is used to define a family of algorithms, 
 * encapsulate each one, and make them interchangeable. 
 * Strategy lets the algorithm vary independently from clients that use it.
 * 
 * 
 */
#include <iostream>

using namespace std;

class DrivingStrategy {
    public:
    virtual void drive() = 0;
};

class SportsDrivingStrategy: public DrivingStrategy {
    public:
    void drive() {
        cout<<"I am driving a sports vehicle...";
    }
};

class NormalDrivingStrategy: public DrivingStrategy {
    public:
    void drive() {
        cout<<"I am driving a normal vehicle";
    }
};

class Vehicle {
    DrivingStrategy* drivingStrategy;
    
    public:
    Vehicle(DrivingStrategy* ds): drivingStrategy(ds){
    }
    
    void drive() {
        this->drivingStrategy->drive();
    }
};

class Sports: public Vehicle {
    public:
    Sports(): Vehicle(new SportsDrivingStrategy()) {}
};

class Normal: public Vehicle {
    public:
    Normal(): Vehicle(new NormalDrivingStrategy()) {}
};

class Racing: public Vehicle {
    public:
    Racing(): Vehicle(new SportsDrivingStrategy()){}
};

int main() {
    Vehicle* v1 = new Normal();
    v1->drive();
    
    cout<<endl;
    
    Vehicle* v2 = new Racing();
    v2->drive();
}