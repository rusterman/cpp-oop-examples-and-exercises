#include <iostream>

using namespace std;

/*
    Exercise:
    Implement a class called MathOperations that performs basic mathematical operations. 
    The class should support chaining calls using references. 
    The following operations should be supported:

    1. MathOperations& add(int val): Adds the given value to the current result.
    2. MathOperations& subtract(int val): Subtracts the given value from the current result.
    3. MathOperations& multiply(int val): Multiplies the current result by the given value.
    4. MathOperations& divide(int val): Divides the current result by the given value.
    
    Additionally, the class should provide a getResult() function that returns the current result.

    In the main() function, create an instance of MathOperations and demonstrate 
    the use of chained calls by performing the following operations:

    1. Start with an initial result of 10.
    2. Add 5, subtract 2, multiply by 3, and divide by 4.
    3. Print the final result.
    
    Note: Ensure that the class handles division by zero gracefully and returns an appropriate message.
*/


/* Solution */

class MathOperations{
private:
    int result;

public:
    MathOperations(int initial){
        result=initial;
    }

    MathOperations& add(int val){
        result+=val;
        return *this;
    }

    MathOperations& subtract(int val){
        result-=val;
        return *this;
    }

    MathOperations& multiply(int val){
        result*=val;
        return *this;
    }

    MathOperations& divide(int val){
        if(val==0){
            cout<<"Error"<<endl;
        } 
        else{
            result/=val;
        }
        return *this;
    }

    int getResult(){
        return result;
    }
};



int main() {

    /*      Example usage:     */
    MathOperations math(10);
    
    math.add(5).subtract(2).multiply(3).divide(4);
    
    cout << "Final result: " << math.getResult() << endl;
    
    return 0;
}