#include<iostream>
using namespace std;
class Shape{
    private:
    string name;
    public:
    Shape(string name){
        this -> name = name;
    }
    virtual void draw(){
        cout << "Drawing a  ";
    }

};
class Circle : public Shape{
    private:
    double radius;
    public:
    Circle(string name , double radius) : Shape(name){
        this -> radius = radius;
    }
    virtual void draw()override{
        Shape :: draw();
        cout << "Circle with its radius is " << radius <<endl;
    }
};
class Rectangle : public Shape{
    private:
    double width;
    double height;
    public:
    Rectangle(string name , double width , double height) : Shape(name){
        this -> width = width;
        this -> height = height;
    }
    virtual void draw()override{
        Shape :: draw();
        cout << "Rectangle with its width is " << width << " and its height is " << height <<endl;
    }
};
class Triangle : public Shape{
    private:
    double katet;
    double hipotenuz;
    public:
    Triangle(string name , double katet , double hipotenuz) : Shape(name){
        this -> katet = katet;
        this -> hipotenuz = hipotenuz;
    }
    virtual void draw()override{
        Shape :: draw();
        cout << "Triangle with its katet is " << katet << " and its hipotenuz is " << hipotenuz <<endl;
    }
};
class Square : public Shape{
    private:
    double side;
    public:
    Square(string name , double side) : Shape(name){
        this -> side = side;
    }
    virtual void draw()override{
        Shape :: draw();
        cout << "Square with its side is " << side <<endl;
    }
};
int main() {
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
