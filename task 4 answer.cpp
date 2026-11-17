#include<iostream>
#include<string>
using  namespace std;



class Employee {
    private:
        string name;
        int age;
        string position;
        double salary;

    public:
        
        void setName(const string& name) {
            this->name = name;
        }

        void setAge(int age) {
            this->age = age;
        }

        void setPosition(const string& position) {
            this->position = position;
        }

        void setSalary(double salary) {
            this->salary = salary;
        }

        
        string getName() const {
            return name;
        }

        int getAge() const {
            return age;
        }

        string getPosition() const {
            return position;
        }

        double getSalary() const {
            return salary;
        }
};

int main() {

    Employee emp;

    emp.setName("John Doe");
    emp.setAge(30);
    emp.setPosition("Software Engineer");
    emp.setSalary(5000.0);

    cout << "Name: " << emp.getName() << endl;
    cout << "Age: " << emp.getAge() << endl;
    cout << "Position: " << emp.getPosition() << endl;
    cout << "Salary: " << emp.getSalary() << endl;

    return 0;
}



