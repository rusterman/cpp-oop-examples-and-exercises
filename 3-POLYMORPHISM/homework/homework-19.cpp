#include <iostream>
#include <string>

using namespace std;

/*
    Polymorphism

    16. Compile time Polymorphism and Tun time polymorphism
*/


/*
    Polymorphism and Overloading Exercise
    
    Instructions:
    In this exercise, you will analyze and identify instances of compile-time polymorphism 
    and run-time polymorphism in the provided C++ code. Additionally, 
    you will determine where method overloading and operator overloading are utilized.

    Tasks:

    1. Identify the section(s) in the code where method overloading is used for compile-time polymorphism. 
    Comment on what makes it an example of compile-time polymorphism.

    2. Operator Overloading:
    Locate the section in the code where operator overloading is used for compile-time polymorphism. 
    Comment on what makes it an example of compile-time polymorphism.

    3. Virtual Function and Inheritance:
    Find the section(s) where run-time polymorphism is demonstrated through virtual functions and inheritance. 
    Comment on how the code achieves run-time polymorphism.

    4. Identify and Discuss:
    In the main function, there are sections labeled "Guess: Is this an example of compile-time or run-time polymorphism?" for each polymorphic scenario.
    Make a guess for each and provide a brief explanation for your choice.

    Feel free to discuss your observations and reasoning. Once you've made your guesses and comments, 
    compile and run the code to see if your predictions align with the actual behavior.
*/


class MathOperations {
public:
    // Method Overloading - Compile-Time Polymorphism
    // This is method overloading because the same function name `add`
    // is defined with different parameter types (int and double).
    // The compiler decides which version to call at compile time.
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

class Complex {
public:
    double real;
    double imag;

    // Operator Overloading - Compile-Time Polymorphism
    // The `+` operator is overloaded here.
    // When `c1 + c2` is written, the compiler resolves this call at compile time.
    Complex operator+(const Complex& other) const {
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }
};

class Shape {
public:
    // Virtual Function and Inheritance - Run-Time Polymorphism
    // The function `draw()` is declared virtual.
    // Which version of `draw()` gets called depends on the actual object type at run time.
    virtual void draw() const {
        cout << "Drawing a Shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Square" << endl;
    }
};


int main() {
    MathOperations math;

    // Guess: Is this an example of compile-time or run-time polymorphism?
    // Answer: Compile-time polymorphism, because method overloading is resolved at compile time.
    cout << "Sum (int): " << math.add(3, 4) << endl;

    // Guess: Is this an example of compile-time or run-time polymorphism?
    // Answer: Compile-time polymorphism, because the overloaded double version is chosen at compile time.
    cout << "Sum (double): " << math.add(3.5, 4.5) << endl;

    Complex c1, c2, result;
    c1.real = 1.0;
    c1.imag = 2.0;
    c2.real = 2.5;
    c2.imag = 1.5;

    // Guess: Is this an example of compile-time or run-time polymorphism?
    // Answer: Compile-time polymorphism, because operator overloading is resolved at compile time.
    result = c1 + c2;
    cout << "Sum: " << result.real << " + " << result.imag << "i" << endl;

    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    // Guess: Is this an example of compile-time or run-time polymorphism?
    // Answer: Run-time polymorphism, because `draw()` is virtual and resolved at run time.
    shape1->draw();  // Calls the draw() method of Circle

    // Guess: Is this an example of compile-time or run-time polymorphism?
    // Answer: Run-time polymorphism, because `draw()` is virtual and resolved at run time.
    shape2->draw();  // Calls the draw() method of Square

    delete shape1;
    delete shape2;
}