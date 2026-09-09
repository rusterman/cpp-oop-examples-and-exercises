#include <iostream>
#include <string>
using namespace std;
class Employee{
    private:
        string name;
        int age;
        string position;
        double salary;

    public:
    void setName(const string& name){this -> name = name;}
    void setAge(int age){this -> age = age;}
    void setPosition(const string& position){this -> position = position;}
    void setSalary(double salary){this -> salary = salary;}

    string getName()const{return name;}
    int getAge()const{return age;}
    string getPosition() const{return position;}
    double getSalary() const{return salary;}
};
int main(){
    system("cls");
    Employee employee;
    employee.setName("Shamkhal");
    employee.setAge(18);
    employee.setPosition("data scientist");
    employee.setSalary(0);
    cout << "about of employee" << endl;
    cout << employee.getName() << endl;
    cout << employee.getAge() << endl;
    cout << employee.getPosition() <<endl;
    cout << employee.getSalary() << endl;
    cout << "about of employee 2" << endl;
    Employee employee2;
    employee2.setName("Ali");
    employee2.setAge(134);
    employee2.setPosition("Angel");
    employee2.setSalary(0);
    cout << employee2.getName() << endl;
    cout << employee2.getAge() << endl;
    cout << employee2.getPosition() <<endl;
    cout << employee2.getSalary() << endl;


}
