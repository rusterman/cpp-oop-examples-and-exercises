#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    int mathMarks;
    int physicsMarks;
    int chemistryMarks;
};

class Classroom {
    private:
        vector<Student> students;

    public:
    void addStudent(Student student){
            students.push_back(student);
    }
    void displayStudents(){
        for(int i = 0 ; i < students.size() ; i++){
            cout << "Name: " << students[i].name << endl;
            cout << "Roll Number: " << students[i].rollNumber <<endl;
            cout << "Math Mark: " << students[i].mathMarks << endl;
            cout << "Pyhsics Mark: " << students[i].physicsMarks << endl;
            cout << "Chemstry Mark: " << students[i].chemistryMarks << endl;
        }
    }
    void displayAverageMarks(){
        for(int i = 0 ; i < students.size() ; i++){
            double avarage = (students[i].mathMarks + students[i].physicsMarks + students[i].chemistryMarks)/3;
            cout << "Name: " << students[i].name << " |Avarage marks: " << avarage << endl;

        }
    }



};



int main() {

    /*      Example usage:     */
    Classroom classroom;

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << i + 1 << endl;

        Student student;
        cout << "Name: ";
        cin >> student.name;
        cout << "Roll Number: ";
        cin >> student.rollNumber;
        cout << "Maths Marks: ";
        cin >> student.mathMarks;
        cout << "Physics Marks: ";
        cin >> student.physicsMarks;
        cout << "Chemistry Marks: ";
        cin >> student.chemistryMarks;

        classroom.addStudent(student);
        cout << endl;
    }

    cout << "Details of all students:" << endl;
    classroom.displayStudents();

    cout << "Average marks of each student:" << endl;
    classroom.displayAverageMarks();
    
    return 0;
}
