#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Vehicle{
    protected:
    int id;
    int MaxSpeed;
    public:
    Vehicle(int id , int MaxSpeed){
        this -> id = id;
        this -> MaxSpeed = MaxSpeed;
    }
    void displayVehicle(){
        cout << "ID: " << id <<endl;
        cout << "MaxSpeed: " << MaxSpeed <<endl;
    }
};
class Car : public Vehicle{
    private:
    int NumDoors;
    public:
    Car(int id , int MaxSpeed , int NumDoors) : Vehicle(id,MaxSpeed){
        this -> NumDoors = NumDoors;
    }
    void calculateFuelEfficiency(){
        cout <<"Fuel Efficiency is calculated:" <<endl;
    }
};
class Bus : public Vehicle{
    private:
    int maxPassengers;
    public:
    Bus(int id , int MaxSpeed , int maxPassengers) : Vehicle(id , MaxSpeed){
        this -> maxPassengers = maxPassengers;
    }
    void announceNextStop(){
        cout << "Announce!" <<endl;
    }
};
class Manager{
    private:
    vector<Vehicle*>fleet;
    public:
    void addVehicle(Vehicle * v ){
        fleet.push_back(v);
    }
    void displayFleet(){
        for(int i = 0 ; i < fleet.size() ; i++){
            fleet[i] -> displayVehicle();
        }
    }

};
int main(){
    Car car1(1, 150, 4);
    Bus bus1(2, 80, 40);

    Manager manager;

    manager.addVehicle(&car1);
    manager.addVehicle(&bus1);

    manager.displayFleet();
    return 0;

}
