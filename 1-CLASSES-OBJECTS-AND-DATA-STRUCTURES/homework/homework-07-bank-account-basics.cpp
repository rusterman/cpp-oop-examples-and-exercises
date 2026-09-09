#include <iostream>

using namespace std;

/*
    Exercise:
    Imagine you are developing a simple banking application in C++. 
    You have a class called BankAccount that represents a user's bank account. 

    The BankAccount class has the following attributes:
        accountNumber (integer) - represents the account number
        balance (double) - represents the account balance

    The BankAccount class also has the following methods:
        deposit(amount) - deposits the specified amount into the account
        withdraw(amount) - withdraws the specified amount from the account
        getBalance() - returns the current account balance

    In addition to the above functionality, you need to ensure that when a BankAccount object is destroyed, 
    it writes a log message indicating that the account is closed.

    Your task is to implement the BankAccount class with appropriate constructors, methods, and a destructor. 
    Demonstrate the need for a destructor by creating multiple BankAccount objects, manipulating them, 
    and observing the log messages when the objects are destroyed.

    Hint:
    To keep things simple, you can use a static variable to keep track of the number of BankAccount objects created, 
    and increment it in the constructor. 
    In the destructor, decrement the count and check if it reaches zero. 
    If so, write the log message.
*/


/* 
    Solution 
*/
class BankAccount {
private:
    int accountNumber;
    double balance;
    static int accountCount; 

public:
    BankAccount(int accNumber, double initialBalance=0.0){
        accountNumber=accNumber;
        balance=initialBalance;
        accountCount++;
        cout<<"BankAccount created. Account Number: "<<accountNumber<<endl;
    }

    void deposit(double amount){
        if(amount>0){
            balance+=amount;
            cout<<"Deposited "<<amount<<" into account "<<accountNumber<<endl;
        } 
        else{
            cout<<"Error"<<endl;
        }
    }

    void withdraw(double amount){
        if(amount>0 && amount<=balance){
            balance=balance-amount;
            cout<<"Withdrew "<<amount<<" from account "<<accountNumber<<endl;
        } 
        else{
            cout<<"Error"<<endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    ~BankAccount(){
        accountCount--;
        cout<<"BankAccount closed. Account Number: "<<accountNumber<<endl;
        if(accountCount==0){
            cout<<"All accounts are now closed. Logging system shutdown."<<endl;
        }
    }
};

int BankAccount::accountCount=0;


int main() {

    /*      Example usage:     */ 

    BankAccount account1(12345); // Account 1 created
    BankAccount account2(67890); // Account 2 created

    account1.deposit(1000);
    account2.deposit(500);

    cout << "Balance of account 1: " << account1.getBalance() << endl;
    cout << "Balance of account 2: " << account2.getBalance() << endl;

    // Account 1 closed (when account1 goes out of scope)
    // Account 2 closed (when account2 goes out of scope)

    return 0;
}