#include <iostream>
#include <string>
using namespace std;
class Person{
    protected:
    string name;
    int age;
    int grades;
    public:
    Person(string name = "Unknown" , int age = 0 , int grades = 0){
        this -> name = name;
        this -> grades = grades;
        this -> age = age;
    }
};
class Teacher : public Person{
    public:
   Teacher(string name , int age , int grades) : Person(name , age , grades){}; /* daha rahat "using Person :: Person" da yazila bilerdi.Yeni bir basa
   persondaki konstruktoru kopyalayiram Teacher(child konstruktora). Menim yazdigim numunede ise men Teacher konstruktoru yaradiram ve o konstruktorla
   Person konstruktorun cagiriram , yəni bir nov yeni funksiya yaradiram.*/
     void ReviewGrades(){
        cout << name << " is reviewing grades" <<endl;
        cout << "Grade: " << grades <<endl;
     }
};
int main() {
    system("cls");
    Teacher teacher("Ms. Johnson", 35, 5);
    Teacher teacher1("Mr.Power" , 55 , 4);
    teacher.ReviewGrades();  
    teacher1.ReviewGrades();
    return 0;
}
