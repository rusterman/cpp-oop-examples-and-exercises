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
            this->accountNumber = accountNumber;
            this->holderName = holderName;
            this->balance = initialBalance;
        }

        // Member functions
        void deposit(double amount){
            if( amount >= 0){
                balance += amount;
            }
        }

        void withdraw(double amount){
            if(amount >= 0 && amount <= balance){
                balance -= amount;
            }else {
            cout << "Insufficient balance!" << endl;
            }
        }

        void checkBalance(){
            cout << "Account Number: " << accountNumber << endl;
            cout << "Holder Name: " << holderName << endl;
            cout << "Balance: " << balance << endl;
        }


};



int main() {

    // TODO: Create an instance of the BankAccount class
    BankAccount account1(111, "Nemii", 5000.0 );
    
    // TODO: Test the deposit, withdraw, and check balance operations
    cout << "Account Details: " << endl;

    account1.checkBalance();
    account1.deposit(2500);
    account1.withdraw(300);

    cout << endl;
    cout << "After Account Details: " << endl;

    account1.checkBalance();

    return 0;
}
