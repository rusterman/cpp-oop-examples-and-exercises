#include <iostream>
#include <string>

using namespace std;

/*
    Polymorphism

    15. Abstract Classes as Interfaces
*/


/*
    Exercise: Shape Hierarchy Design

    Instructions:

    1. Identify Common Functionality:
        Analyze the scenario involving shapes, drawing, and resizing.
        Identify functionalities common to all shapes. These will go into the Shape interface.
    2. Consider Partial Implementation: 
        Determine if there are functionalities common to all drawable shapes that can be partially implemented. 
        If yes, create an abstract class named DrawableShape that extends the Shape interface and provides a partial implementation.
    3. Implement Concrete Classes:
        Implement concrete classes (e.g., Circle and Square) that inherit from either the Shape interface or the DrawableShape abstract class.
    4. Virtual Destructors:
        Ensure proper cleanup by adding virtual destructors where necessary.
    5. Demonstrate Usage:
        In the main function, create instances of concrete classes and demonstrate the use of the interface or abstract class methods.

    Tips:
        Tip 1: Think about functionalities that are common among all shapes and should be defined in an interface.
        Tip 2: Consider functionalities that can have a partial implementation common to all drawable shapes; create an abstract class if necessary.
        Tip 3: Implement concrete classes based on your design, ensuring they inherit from the appropriate interface or abstract class.
        Tip 4: Use virtual destructors where necessary for proper cleanup.
        Tip 5: In the main function, create instances of concrete classes and demonstrate the use of the interface or abstract class methods.

    Note: 
    The goal is to reinforce the understanding of when to use interfaces and abstract classes in a class hierarchy representing shapes and their behaviors.
*/


// Starter Code: 

// TODO: Identify common functionalities for the Shape interface


// TODO: Consider partial implementation in an abstract class named DrawableShape


// TODO: Implement concrete classes (e.g., Circle and Square) inheriting from the interface or abstract class


// Shape interface
class Shape {
public:
    virtual void draw() const = 0;              // hər bir fiqur özünü çəkir
    virtual double calculateArea() const = 0;   // sahə hesablanır
    virtual void resize(double factor) = 0;     // ölçü dəyişdirilir
    virtual ~Shape() {}
};

// Abstract class with partial implementation
class DrawableShape : public Shape {
public:
    void draw() const override {
        cout << "Drawing a generic shape..." << endl;
    }
    virtual ~DrawableShape() {}
};

// Concrete Circle class
class Circle : public DrawableShape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        cout << "Drawing a Circle with radius " << radius << endl;
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    void resize(double factor) override {
        radius *= factor;
        cout << "Circle resized. New radius: " << radius << endl;
    }
};

// Concrete Square class
class Square : public DrawableShape {
private:
    double side;
public:
    Square(double s) : side(s) {}

    void draw() const override {
        cout << "Drawing a Square with side " << side << endl;
    }

    double calculateArea() const override {
        return side * side;
    }

    void resize(double factor) override {
        side *= factor;
        cout << "Square resized. New side: " << side << endl;
    }
};

int main() {
    Circle circle(5.0);
    Square square(4.0);

    // Circle
    circle.draw();
    cout << "Circle Area: " << circle.calculateArea() << endl;
    circle.resize(1.5);
    cout << "Resized Circle Area: " << circle.calculateArea() << endl;

    cout << endl;

    // Square
    square.draw();
    cout << "Square Area: " << square.calculateArea() << endl;
    square.resize(2.0);
    cout << "Resized Square Area: " << square.calculateArea() << endl;

    return 0;
}

