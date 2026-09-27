#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: Employee Management System

    Description:
    Design and implement an Employee Management System using classes and constructors in C++. 
    The system should allow you to create and manage employee records.

    Requirements:

    1. Create a class named "Employee" with the following attributes:
    Employee ID (an integer)
    Employee name (a string)
    Employee designation (a string)
    Employee salary (a floating-point number)

    2. Implement the following constructors for the "Employee" class:
    A parameterized constructor that initializes all the attributes based on provided values.
    A default constructor that sets default values for the attributes.

    3. Include member functions to:
    Set and get the employee attributes (ID, name, designation, salary).
    Display the employee details.

    4. Create multiple employee objects using different constructors and display their details.

    Tips:
    Use appropriate access specifiers (such as private and public) for the class members.
    Consider using default values in the parameterized constructor to provide flexibility when creating objects.
    Test the functionality of constructors by creating objects with and without providing initial values.
    This exercise will help you practice creating and initializing objects using constructors and defaulted constructors, as well as accessing and displaying object attributes.
*/



/*  Solution */
class Employee{
    private:
    int Id;
    string name;
    string designation;
    double salary;
    public:
    Employee(){
        Id = 0;
        name = "";
        designation = "";
        salary = 0.0;
    }
    Employee(int IdP, string nameP, string designationP, double salaryP){
        Id = IdP;
        name = nameP;
        designation = designationP;
        salary = salaryP;
    }
    void setID(int idp){
        Id = idp;
    }
    void setName(string nameparam){
        name = nameparam;
    }
    void setDesignation(string deparam){
        designation = deparam;
    }
    void setSalary(double salaryparam){
        salary = salaryparam;
    }
    void displayDetails(){
        cout << "Id number: " << Id << endl;
        cout << "name: " << name << endl;
        cout << "designation: " << designation << endl;
        cout << "salary: " << salary << endl;
    }

};


int main() {

    /*      Example usage:     */ 

    // Creating employee objects using different constructors
    Employee emp1(101, "John Doe", "Manager", 5000.0);
    Employee emp2;

    emp2.setID(102);
    emp2.setName("Jane Smith");
    emp2.setDesignation("Engineer");
    emp2.setSalary(4000.0);

    // Displaying employee details
    cout << "Employee 1 Details: " << endl;
    emp1.displayDetails();
    cout << endl;

    cout << "Employee 2 Details: " << endl;
    emp2.displayDetails();
    cout << endl;

    return 0;
}