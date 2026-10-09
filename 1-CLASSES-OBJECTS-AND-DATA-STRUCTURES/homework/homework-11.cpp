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
    // Complete the code
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
        
         void addStudent(const Student& s) {
        students.push_back(s);
    }
    void displayStudents() {
        for (const Student& s : students) {
            cout << "Name: " << s.name << endl;
            cout << "Roll Number: " << s.rollNumber << endl;
            cout << "Maths Marks: " << s.mathMarks << endl;
            cout << "Physics Marks: " << s.physicsMarks << endl;
            cout << "Chemistry Marks: " << s.chemistryMarks << endl;
            cout << "-----------------------------" << endl;
        }
    }

    
    void displayAverageMarks() {
        for (const Student& s : students) {
            double avg = (s.mathMarks + s.physicsMarks + s.chemistryMarks) / 3.0;
            cout << "Name: " << s.name << " | Average Marks: " << avg << endl;
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