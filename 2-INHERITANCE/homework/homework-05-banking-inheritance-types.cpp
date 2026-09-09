#include <iostream>
#include <string>

using namespace std;


/*
    Exercise: Inheritance in a Banking Software Application

    In this exercise, you will design a simplified banking software application using C++ classes 
    to demonstrate the real need for public, protected, and private inheritance. 
    The application will model a basic bank system with different types of accounts and transactions. 
    You will create a base class for "Account" and derive three different types of accounts from it. 
    Then, you will demonstrate the appropriate usage of public, protected, and private inheritance in this context.

    Part 1: Base Class and Inheritance
        1. Create a base class called Account with the following properties and methods:
        Properties: accountNumber, accountHolder, balance
        Methods: deposit, withdraw, getBalance

        2. Derive three classes from the Account base class:
        a. SavingsAccount: This should inherit using public inheritance. 
        Add a method called applyInterest that increases the balance based on an interest rate.
        b. CheckingAccount: This should inherit using protected inheritance. 
        Add a method called applyMonthlyFee that deducts a fixed fee from the balance every month.
        c. CreditCardAccount: This should inherit using private inheritance. 
        Add a method called makePurchase that deducts a specified amount from the balance.
    
    Part 2: Demonstration
        1. In your main function, instantiate objects of each of the derived classes (SavingsAccount, CheckingAccount, CreditCardAccount).
        2. Simulate transactions using the instantiated objects: 
        Deposit and withdraw funds from each account. 
        Apply interest to the SavingsAccount.
        Apply monthly fees to the CheckingAccount.
        Make purchases using the CreditCardAccount.
        3. Display the account details and balances after each transaction.

    Part 3: Analysis

    1. Explain why public inheritance is suitable for the SavingsAccount class.
    2. Discuss the advantages of using protected inheritance for the CheckingAccount class.
    3. Justify the use of private inheritance for the CreditCardAccount class.
*/


/*
    Solution
*/

class Account{
protected:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    Account(int accNum, string holder, double bal)
        : accountNumber(accNum), accountHolder(holder), balance(bal){}

    void deposit(double amount){
        balance+=amount;
        cout<<"Deposit: "<<amount<<" Balance: "<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Withdraw: "<<amount<<" Balance: "<<balance<<endl;
        } 
        else{
            cout<<"Insufficient Funds"<<endl;
        }
    }

    double getBalance() const{
        return balance;
    }
};


class SavingsAccount : public Account{
public:
    SavingsAccount(int accNum, string holder, double bal)
        : Account(accNum, holder, bal) {}

    void applyInterest(double rate){
        balance= bacalnce+(balance*rate);
        cout<<"Interest Applied: Balance: "<<balance<<endl;
    }
};


class CheckingAccount : protected Account{
public:
    CheckingAccount(int accNum, string holder, double bal)
        : Account(accNum, holder, bal){}

    void applyMonthlyFee(double fee){
        balance-=fee;
        cout<<"Monthly Fee Applied: Balance: "<<balance<<endl;
    }

    void deposit(double amount) {Account::deposit(amount);}
    void withdraw(double amount) {Account::withdraw(amount);}
    double getBalance() const {return Account::getBalance();}
};

class CreditCardAccount : private Account{
public:
    CreditCardAccount(int accNum, string holder, double bal)
        : Account(accNum, holder, bal) {}

    void makePurchase(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Purchase Made: Amount: "<<amount<<" Balance: "<<balance<<endl;
        } 
        else{
            cout<<"Insufficient Funds"<<endl;
        }
    }

    double getBalance() const {return Account::getBalance();}
};

int main() {

    system("clear");

    /*    Example Usage    */

    SavingsAccount savings(1001, "John Doe", 1000.0);
    CheckingAccount checking(2001, "Jane Smith", 1500.0);
    CreditCardAccount creditCard(3001, "Alice Johnson", 500.0);

    savings.deposit(500);
    savings.applyInterest(0.05);
    savings.withdraw(200);
    
    checking.applyMonthlyFee(10);

    creditCard.makePurchase(200);
    creditCard.makePurchase(400);

    /*
        [Output]

        Deposit: 500 Balance: 1500
        Interest Applied: Balance: 1575
        Withdraw: 200 Balance: 1375
        Monthly Fee Applied: Balance: 1490
        Purchase Made: Amount: 200 Balance: 300
        Insufficient Funds
    */
}
