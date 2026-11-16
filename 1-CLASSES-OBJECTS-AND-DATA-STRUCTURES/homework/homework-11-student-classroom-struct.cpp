#include <iostream>
#include <vector>

using namespace std;

/*
    Exercise:
    Implement a program to store and manage the information of students in a class. 
    Each student should have the following attributes: name, roll number, 
    and marks in three subjects (Maths, Physics, and Chemistry).

    1. Define a struct called Student that holds the attributes mentioned above.

    2. Implement a class called Classroom that represents a class of students. 
    The class should have the following functionalities:
        Add a new student to the class.
        Display the details of all students in the class.
        Calculate and display the average marks of each student.
        
    3. In the main() function, create an instance of the Classroom class. 
    Prompt the user to enter the details of multiple students and add them to the class. 
    After adding the students, display the details of all students and their average marks.
*/


/* Solution */
struct Student {
    string name;
    int rollNumber;
    double mathMarks;
    double physicsMarks;
    double chemistryMarks;

};

class Classroom {
    private:
        vector<Student> students;

    public:
        void addStudent(Student A){
            students.push_back(A);
        }

        void displayStudents(){
            for(int i = 0; i < students.size(); i++){
                cout << "Name: " << students[i].name << endl;
                cout << "Roll Number: " << students[i].rollNumber << endl;
                cout << "Math Mark: " << students[i].mathMarks << endl;
                cout << "Physic Mark: " << students[i].physicsMarks << endl;
                cout << "Chemistry Mark: " << students[i].chemistryMarks << endl;
            }
        }

        double calculateAverage(Student s){
            return (s.mathMarks + s.chemistryMarks + s.physicsMarks) / 3;
        }

        void displayAverageMarks(){
            for(int i = 0; i < students.size(); i++){
                cout << students[i].name << " Average: "
                    << calculateAverage(students[i]) << endl;
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