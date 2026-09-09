#include <iostream>
using namespace std;

class MathOperations{
    private:
    int result;
    public:
    MathOperations(int result){
        this -> result = result;
    }
    MathOperations* add(int val){
        result = result + val;
        return this;
    }
    MathOperations* subtract(int val){
        result = result - val;
        return this;
    }
    MathOperations* multiply(int val){
        result = result * val;
        return this;
    }
    MathOperations* divide(int val){
        if(val != 0){
        result = result / val;
        }
        else{
            cout << "Invalid" <<endl;
        }
        return this;
    }
    int getResult(){
        return result;
    }


};

int main() {
    system("cls");
    /*      Example usage:     */
    MathOperations math(10);

    math.add(5)->subtract(2)->multiply(3)->divide(4);

    cout << "Final result: " << math.getResult() << endl;

    return 0;
}
