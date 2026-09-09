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
        static bool CompareAreas(double area1 , double area2){
            if(area1 == area2){
                return true;
            }
            else{
                return false;
            }
        }
};

class Circle : public Shape {
    public:
    double radius;
        Circle(double radius) : radius(radius) {}
        static double CalculateArea(double radius , const double pi = 3.14){
            return pi*radius*radius;
        }
};

class Rectangle : public Shape {
    public:
    double width;
    double height;
        Rectangle(double width, double height) : width(width), height(height) {}
        static double CalculateArea(double width , double height){
            return width*height;
        }
};

int main() {
    double circleRadius, rectWidth, rectHeight;

    cout << "Enter the radius of a circle: ";
    cin >> circleRadius;

    cout << "Enter the width and height of a rectangle: ";
    cin >> rectWidth >> rectHeight;

    double CircleArea = Circle::CalculateArea(circleRadius);
    double RectArea = Rectangle::CalculateArea(rectWidth , rectHeight);
    cout << "Circle Area: " << CircleArea <<endl;
    cout << "Rectangle Area: " << RectArea << endl;
    bool checking = Shape::CompareAreas(CircleArea , RectArea);
    cout << "Checking: " << checking << endl;


}
