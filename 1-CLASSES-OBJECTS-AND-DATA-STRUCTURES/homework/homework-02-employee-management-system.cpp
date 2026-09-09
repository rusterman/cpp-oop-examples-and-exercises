#include <iostream>
#include <string>
using namespace std;
class Employee{
    private:
    int ID;
    string name;
    string designation;
    double salary;
    public:
     Employee(int pID = 0 , string Pname = "Unknown" , string Pdesignation = "unknown" , double Psalary = 0.0){
        ID = pID;
        name = Pname;
        designation = Pdesignation;
        salary = Psalary;
    }

    void setID(int pID){ID = pID;}
    void setName(string Pname){name = Pname;}
    void setDesignation(string Pdesignation){designation = Pdesignation;}
    void setSalary(double Psalary){salary = Psalary;}

    void displayDetails(){
        cout << ID << endl;
        cout <<  name << endl;
        cout << designation << endl;
        cout << salary << endl;

    }

};
int main(){
    system("cls");
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
