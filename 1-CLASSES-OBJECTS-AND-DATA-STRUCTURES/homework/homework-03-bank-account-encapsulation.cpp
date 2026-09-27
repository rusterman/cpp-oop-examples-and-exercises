#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: Bank Account Management System

    You need to implement a simple bank account management system using encapsulation. 
    The system should have the following features:

    1. Each account should have a unique account number, holder name, and balance.
    2. The balance should not be directly accessible from outside the class.
    3. The account holder should be able to deposit and withdraw funds.
    4. The account holder should be able to check their account balance.
    
    Your task is to create a C++ class called BankAccount that encapsulates the above features. 
    Here's a code template to get you started:
*/

class BankAccount {
    private:
        // Private member variables
        int accountNumber;
        string holderName;
        double balance;

    public:
        // Constructor
        BankAccount(int accountNumber, const string &holderName, double initialBalance) {
            // TODO: Initialize member variables
            this->accountNumber = accountNumber;
            this->holderName = holderName;
            balance = initialBalance;
        }
        
        // Member functions

        // TODO: Implement member functions for deposit, withdraw, and check balance
        void deposit(double amount1){

            balance = balance + amount1;
        }
        void withdraw(double amount2){
            balance = balance - amount2;
        }
        void checkBalance() const{
            cout << "Balance is: " << balance << endl;
        }

};



int main() {

    // TODO: Create an instance of the BankAccount class
    // TODO: Test the deposit, withdraw, and check balance operations

    /*
        You need to complete the implementation of the BankAccount class by:

        1. Initializing the member variables in the constructor.
        2. Implementing member functions for deposit, withdraw, and check balance.
        3. Testing the functionality of your class in the main function by creating an instance 
        of BankAccount and performing deposit, withdrawal, and balance checks.
        
        Remember to enforce encapsulation by keeping the member variables private and providing public member functions to access and modify them.

        This exercise will help you practice encapsulation and understand how to hide 
        implementation details while exposing a controlled interface to the users of your class!
    */
   BankAccount account1(1, "Huseyn Aghazada", 550.5);
   account1.checkBalance();
   account1.deposit(12.5);
   account1.withdraw(26.7);
   account1.checkBalance();

    return 0;
}

