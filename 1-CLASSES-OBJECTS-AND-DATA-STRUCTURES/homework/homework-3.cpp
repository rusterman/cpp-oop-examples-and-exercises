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
            accountNumber = accNo;
            holderName = name;
            balance = initialBalance;
        }

        // Member functions
        // TODO: Implement member functions for deposit, withdraw, and check balance
         void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }

        void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

        void checkBalance() {
        cout << "Account Balance: " << balance << endl;
    }
        void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
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
    BankAccount acc1(1001, "Orxan Aghayev", 500.0);

    
    acc1.displayDetails();
    cout << endl;

    acc1.deposit(200);
    acc1.checkBalance();
    cout << endl;

    acc1.withdraw(100);
    acc1.checkBalance();
    cout << endl;

    acc1.withdraw(700); /
    cout << endl;

    return 0;
}

