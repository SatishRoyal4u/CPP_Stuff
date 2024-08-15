 // Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Vehicle
{
    public:
    virtual void createVehicle()=0;
    
};

class Car: public Vehicle
{
    public:
    virtual void createVehicle()
    {
        cout<<"creating  car"<<endl;
    }
    
};

class Bike: public Vehicle
{
    public:
    virtual void createVehicle()
    {
        cout<<"creating  Bike"<<endl;
    }
    
};

int main() {
    // Write C++ code here
    cout<<"enter a VehicleType"<<endl;
    string VehicleType;
    cin >> VehicleType;
    Vehicle* vehicle;
    if(VehicleType == "Car")
    {
         vehicle = new Car();
    }
    else if (VehicleType == "Bike")
    {
         vehicle = new Bike();
    }
    vehicle->createVehicle();

    return 0;
}T
