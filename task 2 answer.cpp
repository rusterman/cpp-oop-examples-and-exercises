
#include <iostream>
#include <string>
using namespace std;


class Employee {
private:
    int id;
    string name;
    string designation;
    double salary;

public:
    
    Employee() {
        id = 0;
        name = "Unknown";
        designation = "Unknown";
        salary = 0.0;
    }

    
    Employee(int i, string n, string d, double s) {
        id = i;
        name = n;
        designation = d;
        salary = s;
    }

    
    void setID(int i) { id = i; }
    void setName(string n) { name = n; }
    void setDesignation(string d) { designation = d; }
    void setSalary(double s) { salary = s; }

    
    int getID() { return id; }
    string getName() { return name; }
    string getDesignation() { return designation; }
    double getSalary() { return salary; }

    
    void displayDetails() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Salary: " << salary << endl;
    }
};
int main(){
    

    

    Employee emp1(101, "John Doe", "Manager", 5000.0);
    Employee emp2;

    emp2.setID(102);
    emp2.setName("Jane Smith");
    emp2.setDesignation("Engineer");
    emp2.setSalary(4000.0);

    cout << "Employee 1 Details: " << endl;
    emp1.displayDetails();
    cout << endl;

    cout << "Employee 2 Details: " << endl;
    emp2.displayDetails();
    cout << endl;

    return 0;
}