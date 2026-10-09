#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: Implement a Banking System

    In this exercise, you will create a basic banking system with the following classes:

    1. Account (Base Class):
        Create a base class called Account with the following attributes and methods:
        - accountNumber (integer)
        - balance (double)
        - Account(const int accountNumber, const double balance) constructor.
        - A virtual destructor for proper resource cleanup.
        - virtual void deposit(double amount) method to deposit funds into the account.
        - virtual void withdraw(double amount) method to withdraw funds from the account.
        - virtual void displayBalance() method to display the current balance.

    2. SavingsAccount (Derived Class):
        Create a derived class called SavingsAccount that inherits from Account. This class should include:
         - A constructor that takes an account number, initial balance, and an interest rate (e.g., 3%).
         - An overridden displayBalance() method that displays the current balance along with the interest rate.
         - An overridden withdraw() method that checks if the withdrawal amount is less than the balance and, if so, 
           processes the withdrawal. If the withdrawal amount exceeds the balance, display an error message.
    3.  CheckingAccount (Derived Class):
         - Create another derived class called CheckingAccount that inherits from Account. This class should include:
         - A constructor that takes an account number and initial balance.
         - An overridden displayBalance() method that displays the current balance along with a message indicating it's a checking account.
         - An overridden withdraw() method that checks if the withdrawal amount is less than the balance and, if so, 
           processes the withdrawal. If the withdrawal amount exceeds the balance, display an error message.
    4. Main Function:
        - In the main() function, create instances of both SavingsAccount and CheckingAccount. 
        - Deposit and withdraw funds from these accounts, and display their balances to demonstrate polymorphism.
    
    5. Proper Cleanup:
     - Make sure to delete the account objects at the end of the main() function to ensure that their destructors are called.
*/


class Account {
protected:
    int accountNumber;
    double balance;
public:
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual ~Account() {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " into account " << accountNumber << endl;
    }

    virtual void withdraw(double amount) {
        balance -= amount;
        cout << "Withdrew " << amount << " from account " << accountNumber << endl;
    }

    virtual void displayBalance() const {
        cout << "Account " << accountNumber << " Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
public:
    SavingsAccount(int accNum, double bal, double rate)
        : Account(accNum, bal), interestRate(rate) {}

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "SavingsAccount " << accountNumber << ": Withdrew " << amount << endl;
        } else {
            cout << "SavingsAccount " << accountNumber << ": Insufficient funds!" << endl;
        }
    }

    void displayBalance() const override {
        cout << "SavingsAccount " << accountNumber 
             << " Balance: " << balance 
             << " (Interest Rate: " << interestRate << "%)" << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNum, double bal) : Account(accNum, bal) {}

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "CheckingAccount " << accountNumber << ": Withdrew " << amount << endl;
        } else {
            cout << "CheckingAccount " << accountNumber << ": Insufficient funds!" << endl;
        }
    }

    void displayBalance() const override {
        cout << "CheckingAccount " << accountNumber 
             << " Balance: " << balance << endl;
    }
};

int main() {
    Account* savings = new SavingsAccount(1001, 1000.0, 3.0);
    Account* checking = new CheckingAccount(2001, 2000.0);

    savings->deposit(500.0);
    savings->withdraw(200.0);
    savings->displayBalance();

    checking->deposit(300.0);
    checking->withdraw(2500.0); // deliberately exceeds balance
    checking->displayBalance();

    delete savings;
    delete checking;

    return 0;
}