#include<iostream>

using namespace std;



class MathOperations {
private:
    int result;

public:
    
    MathOperations(int initial) {
        result = initial;
    }

    
    MathOperations& add(int val) {
        result += val;
        return *this;
    }

    MathOperations& subtract(int val) {
        result -= val;
        return *this;
    }

    MathOperations& multiply(int val) {
        result *= val;
        return *this;
    }

    MathOperations& divide(int val) {
        if (val == 0) {
            cout << "Error: Division by zero is not allowed." << endl;
        } else {
            result /= val;
        }
        return *this;
    }

    int getResult() const {
        return result;
    }
};
int main() {
    MathOperations math(10);

    math.add(5);
    math.multiply(2);
    math.divide(3);

    cout << "Result: " << math.getResult() << endl;

    return 0;
}