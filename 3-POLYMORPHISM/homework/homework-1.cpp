#include <iostream>
#include <string>

using namespace std;


/*
    Exercise: Polymorphism in C++

    Instructions:

    1. Create a C++ program that models geometric shapes.
    2. Define a base class Shape with the following properties and methods:
        Properties:
        name (string): The name of the shape.
        Methods:
        virtual void draw(): A virtual function that prints a message indicating that a shape is being drawn.
        The message should include the shape's name.
    3. Create two derived classes, Circle and Rectangle, that inherit from the Shape class. 
    Each derived class should have its own specific properties and methods:
        Circle:
        Properties:
        radius (double): The radius of the circle.
        Methods:
        Override the draw() method to print a message indicating that a circle is being drawn, along with its radius.
        Rectangle:
        Properties:
        length (double): The length of the rectangle.
        width (double): The width of the rectangle.
        Methods:
        Override the draw() method to print a message indicating that a rectangle is being drawn, along with its length and width.
    4. In the main() function, create instances of the Circle and Rectangle classes.
    5. Create an array of pointers to Shape objects and store the addresses of the Circle and Rectangle objects in the array.
    6. Use a loop to iterate through the array and call the draw() method for each object. 
    Observe how polymorphism allows you to call the appropriate draw() method based on the actual type of the object.
    7. Compile and run the program to verify that the correct messages are printed for each shape.

    Example Output:
    Drawing a circle with radius 5.0
    Drawing a rectangle with length 6.0 and width 4.0

    8. Challenge: Extend the program by adding more derived classes (e.g., Triangle, Square) 
    and further explore polymorphism by creating objects of these classes and adding them to the array of shapes. 
    Update the draw() methods in the derived classes accordingly.
*/

// Solution:
class Shape {
protected:
    string name;
public:
    Shape(const string& n) : name(n) {}
    virtual void draw() {
        cout << "Drawing a shape: " << name << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(const string& n, double r) : Shape(n), radius(r) {}
    void draw() override {
        cout << "Drawing a circle with radius " << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(const string& n, double l, double w) : Shape(n), length(l), width(w) {}
    void draw() override {
        cout << "Drawing a rectangle with length " << length
             << " and width " << width << endl;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(const string& n, double b, double h) : Shape(n), base(b), height(h) {}
    void draw() override {
        cout << "Drawing a triangle with base " << base
             << " and height " << height << endl;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(const string& n, double s) : Shape(n), side(s) {}
    void draw() override {
        cout << "Drawing a square with side " << side << endl;
    }
};


int main() {

    /*      Example usage:     */ 

    Circle circle("Circle", 5.0);
    Rectangle rectangle("Rectangle", 6.0, 4.0);
    Triangle triangle("Triangle", 4.0, 3.0);
    Square square("Square", 5.0);

    Shape* shapes[] = { &circle, &rectangle, &triangle, &square };

    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
    }

    return 0;
}
