#include <iostream>

using namespace std; 


/*
    Exercise: Employee Polymorphism

    In this exercise, you are tasked with implementing a basic employee management system in C++. 
    You will create a class hierarchy for different types of employees, 
    calculate their salaries based on their roles, and display their information.

    1. Create a base class Employee with the following attributes and methods:
        Attributes:
            name (string): The name of the employee.
            baseSalary (double): The base salary of the employee.
        Methods:
            Employee(const string& n, double salary): Constructor to initialize the name and baseSalary.
            virtual double calculateSalary() const: 
            A virtual function to calculate and return the salary based on the base salary. 
            You can return the baseSalary as the default implementation.
            virtual void display() const: A virtual function to display the employee's name and salary.
    2. Create two derived classes, Manager and Developer, which inherit from the Employee class:
        Manager:
            Add an additional attribute, bonus (double), representing the bonus amount.
            Override the calculateSalary() method to calculate the salary as the sum of the base salary and the bonus.
            Override the display() method to display "Manager - " followed by the employee's name and salary.
        Developer:
            Add an additional attribute, numberOfProjects (int), representing the number of projects the developer has completed.
            Override the calculateSalary() method to calculate the salary as the sum of the base salary and a bonus of $1000 per completed project.
            Override the display() method to display "Developer - " followed by the employee's name and salary.
    3. In the main() function:
        Create an array of Employee* pointers to store instances of both Manager and Developer objects.
        Create at least two instances of each type of employee, using the constructor to initialize their attributes.
        Loop through the array of employee pointers and call the display() method for each employee to display their information.

    4. Don't forget to deallocate memory for dynamically allocated objects 
    using delete in the main() function to prevent memory leaks.

    5. Compile and run the program to verify that polymorphism is working correctly, 
    and the correct calculateSalary() and display() methods are called for each employee type.

    6. You have the flexibility to decide the access specifiers (public, private, protected) 
    for the Employee, Manager, and Developer classes based on your specific requirements.
*/


/*  Solution:  */
class Employee {
protected:
    string name;
    double baseSalary;
public:
    Employee(const string& n, double salary) : name(n), baseSalary(salary) {}
    virtual double calculateSalary() const {
        return baseSalary;
    }
    virtual void display() const {
        cout << "Employee - " << name << ", Salary: " << calculateSalary() << endl;
    }
    virtual ~Employee() {}
};

class Manager : public Employee {
private:
    double bonus;
public:
    Manager(const string& n, double salary, double b) : Employee(n, salary), bonus(b) {}
    double calculateSalary() const override {
        return baseSalary + bonus;
    }
    void display() const override {
        cout << "Manager - " << name << ", Salary: " << calculateSalary() << endl;
    }
};

class Developer : public Employee {
private:
    int numberOfProjects;
public:
    Developer(const string& n, double salary, int projects) : Employee(n, salary), numberOfProjects(projects) {}
    double calculateSalary() const override {
        return baseSalary + (numberOfProjects * 1000);
    }
    void display() const override {
        cout << "Developer - " << name << ", Salary: " << calculateSalary() << endl;
    }
};





int main() {

    /*  Example Usage  */
    const int numEmployees = 3;
    Employee* employees[numEmployees];

    employees[0] = new Manager("Alice", 50000, 10000);
    employees[1] = new Developer("Bob", 60000, 5);
    employees[2] = new Developer("Charlie", 55000, 3);

    for (int i = 0; i < numEmployees; i++) {
        
    }

    // Clean up
    

    return 0;
}
