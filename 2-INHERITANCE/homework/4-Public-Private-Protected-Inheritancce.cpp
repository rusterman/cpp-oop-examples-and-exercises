#include <iostream>
#include <vector>

using namespace std;

/*
    Exercise Description:
    In this exercise, you will explore the concepts of public, protected, and private inheritance in C++. 
    You'll be presented with a scenario involving different classes and their relationships, 
    and you'll need to decide which type of inheritance 
    should be used in each case to achieve the desired behavior and access levels.

    Scenario:
    Imagine you are developing a software system to model various types of vehicles for a transportation company. 
    You need to create a hierarchy of classes to represent different types of vehicles and their attributes. 
    Additionally, there will be a Manager class that handles the management of these vehicles.
*/

/*
    Classes:

    1. Vehicle: This is the base class that will hold common attributes of all vehicles, 
    such as the vehicle's identification number (id), maximum speed (maxSpeed), 
    and a function to display information about the vehicle (display()).

    2. Car: This class represents a car and should inherit from the Vehicle class. 
    It will have additional attributes like the number of doors (numDoors)
     and a function to calculate fuel efficiency (calculateFuelEfficiency()).

    3. Bus: This class represents a bus and should also inherit from the Vehicle class. 
    It will have attributes like the maximum passenger capacity (maxPassengers) 
    and a function to announce the next bus stop (announceNextStop()).

    4. Manager: This class is responsible for managing the fleet of vehicles. 
    It should have a collection of vehicles, a function to add vehicles to the fleet (addVehicle()), 
    and a function to display information about all vehicles in the fleet (displayFleet()).
*/

/*
    Instructions:

    1. Determine the appropriate type of inheritance (public, protected, or private) between the Vehicle, Car, and Bus classes.
    2. Decide which attributes and functions should be accessible from the Manager class and other derived classes.
    3. Implement the necessary inheritance relationships and access specifiers to achieve the desired behavior.
    
    Discussion Points:
    Why would you choose public inheritance for certain classes?
    When is protected inheritance useful and in what scenarios should it be avoided?
    How does private inheritance restrict access compared to public and protected inheritance?
    
    Note: This exercise is designed to encourage understanding of inheritance types and their implications. 
    It does not involve actual coding, but rather requires conceptual analysis 
    and decision-making regarding inheritance relationships and access specifiers in C++.
*/


/*  Solution  */




int main() {

    /*    Example Usage    */
    Car car1(1, 150, 4);
    Bus bus1(2, 80, 40);

    Manager manager;

    manager.addVehicle(&car1);
    manager.addVehicle(&bus1);

    manager.displayFleet();

    /*
        [Output]

        Vehicle ID: 1, Max Speed: 150 km/h
        Vehicle ID: 2, Max Speed: 80 km/h
    */

    return 0;
}
