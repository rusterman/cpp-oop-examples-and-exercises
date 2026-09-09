#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: Employee Management System

    You are tasked with creating an employee management system for a company. 
    Each employee has a name, age, position, and salary. 
    Your goal is to implement a class called Employee that encapsulates 
    these attributes and provides appropriate setters and getters.

    Your task is to create a C++ class called Employee with the following specifications:

    1. Private member variables:
        name (string): Holds the name of the employee.
        age (int): Holds the age of the employee.
        position (string): Holds the position/title of the employee.
        salary (double): Holds the salary of the employee.
    
    2. Public member functions:
        setName(const string& name): Sets the name of the employee.
        setAge(int age): Sets the age of the employee.
        setPosition(const string& position): Sets the position of the employee.
        setSalary(double salary): Sets the salary of the employee.
        getName() const: Returns the name of the employee.
        getAge() const: Returns the age of the employee.
        getPosition() const: Returns the position of the employee.
        getSalary() const: Returns the salary of the employee.
    
    Your implementation should allow external code to set and get the attributes of
    an Employee object using the appropriate setter and getter functions.

    Here's a code template to get you started:
*/

class Employee {
    private:
        string name;
        int age;
        string position;
        double salary;

    public:
        // TODO: Implement setters and getters
        void setName(const string& n){
            name=n;
        }

        void setAge(int a){
            age=a;
        }

        void setPosition(const string& p){
            position = p;
        }

        void setSalary(double s){
            salary=s;
        }

        string getName() const{
            return name;
        }

        int getAge() const{
            return age;
        }

        string getPosition() const{
            return position;
        }

        double getSalary() const{
            return salary;
    }

};



int main() {

    // TODO: Test the Employee class by creating an object, setting attributes, and getting attribute values
    Employee emp;

    emp.setName("Aysel");
    emp.setAge(20);
    emp.setPosition("Worker");
    emp.setSalary(100);

    cout<<"Employee Details:"<<endl;
    cout<<"Name: "<<emp.getName()<<endl;
    cout<<"Age: "<<emp.getAge()<<endl;
    cout<<"Position: "<<emp.getPosition()<<endl;
    cout<<"Salary: "<<emp.getSalary()<<endl;
    return 0;
}

