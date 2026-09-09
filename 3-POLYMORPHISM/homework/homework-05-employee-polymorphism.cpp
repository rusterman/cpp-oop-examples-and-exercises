#include<iostream>
using namespace std;
class Employee{
    protected:
    string name;
    double baseSalary;
    public:
    Employee(string name , double baseSalary){
        this -> name = name;
        this -> baseSalary = baseSalary;
    }
    virtual double calculateSalary(){
        return baseSalary;
    }
    virtual void display(){
        cout << "Name: " << name << endl;
        cout << "Base Salary: " << baseSalary <<endl;
    }
     virtual ~Employee() {}
};
class Manager : public Employee{
    private:
    double bonus;
    public:
    Manager(string name , double baseSalary , double bonus) : Employee(name , baseSalary){
        this -> bonus = bonus;
    } 
    virtual double calculateSalary()override{
        return baseSalary + bonus;
    }
    virtual void display()override{
        Employee::display();
        cout << "New salary(it means Total Salary: ) " << calculateSalary() <<endl;
    }

};
class Developer : public Employee{
    protected:
    int numberOfProjects;
    public:
    Developer(string name , double baseSalary , int numberOfProjects) : Employee(name , baseSalary){
        this -> numberOfProjects = numberOfProjects;
    }
    
    virtual double calculateSalary()override{
        return baseSalary + 1000*numberOfProjects;
    }
    virtual void display()override{
        Employee::display();
        cout << "Earnings with profits from additional projects: " << calculateSalary() <<endl;
    }
};
int main(){
    const int numEmployees = 3;
    Employee* employees[numEmployees];

    employees[0] = new Manager("Alice", 50000, 10000);
    employees[1] = new Developer("Bob", 60000, 5);
    employees[2] = new Developer("Charlie", 55000, 3);

    for (int i = 0; i < numEmployees; i++) {
        employees[i] ->display();
        employees[i] ->calculateSalary();
        
    }
}
