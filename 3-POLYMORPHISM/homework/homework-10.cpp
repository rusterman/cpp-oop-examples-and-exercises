#include <iostream>

using namespace std;


/*
    Inheritance and Polymorphism with Static members
*/

/*
    Exercise: Implement static methods within the Circle and Rectangle classes 
    to calculate the areas of circles and rectangles, respectively. 
    Additionally, create a static method in the Shape class to compare the areas of two shapes.

    Tasks:

    1. Implement the CalculateArea static methods in the Circle and Rectangle classes to calculate the areas of circles and rectangles, respectively.
    2. Create a static method in the Shape class to compare the areas of two shapes. You'll need to access the CalculateArea static methods in the derived classes for this comparison.
    3. In the main function, prompt the user to enter the radius for a circle and the width and height for a rectangle.
    4. Calculate and display the areas of the circle and rectangle using the static methods.

    Implement comparisons of areas using the static method in the Shape class to determine if the areas are equal.
*/

class Shape {
public:
    // Static method to compare two areas
    static void compareAreas(double area1, double area2) {
        if (fabs(area1 - area2) < 1e-6) {
            cout << "Areas are equal." << endl;
        } else if (area1 > area2) {
            cout << "First area is larger." << endl;
        } else {
            cout << "Second area is larger." << endl;
        }
    }
};

class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}

    // Static method to calculate circle area
    static double CalculateArea(double radius) {
        return M_PI * radius * radius;
    }

private:
    double radius;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    // Static method to calculate rectangle area
    static double CalculateArea(double width, double height) {
        return width * height;
    }

private:
    double width, height;
};

int main() {
    double circleRadius, rectWidth, rectHeight;

    cout << "Enter the radius of a circle: ";
    cin >> circleRadius;

    cout << "Enter the width and height of a rectangle: ";
    cin >> rectWidth >> rectHeight;

    double circleArea = Circle::CalculateArea(circleRadius);
    double rectArea = Rectangle::CalculateArea(rectWidth, rectHeight);

    cout << "Circle Area: " << circleArea << endl;
    cout << "Rectangle Area: " << rectArea << endl;

    Shape::compareAreas(circleArea, rectArea);

    return 0;
}