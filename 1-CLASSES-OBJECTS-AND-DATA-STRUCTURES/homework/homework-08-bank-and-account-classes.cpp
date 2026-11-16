#include <iostream>
#include <string>

using namespace std;


/*
    Exercise:
    Create a program that simulates a simple bank account system. 
    The program should have two classes: BankAccount and Bank.

    1. BankAccount class should have the following private members:
        int accountNumber: An integer representing the account number.
        double balance: A double representing the current balance.
    It should also have the following public member functions:
        BankAccount(int accNumber): A constructor that takes an account number as a parameter and initializes the balance to 0.
        void deposit(double amount): A function that takes an amount and adds it to the account's balance.
        void withdraw(double amount): A function that takes an amount and subtracts it from the account's balance.
        void displayBalance(): A function that displays the current balance of the account.

    2. Bank class should have the following private members:
        BankAccount* accounts: A pointer to an array of BankAccount objects.
        int numAccounts: An integer representing the number of accounts in the bank.
    It should also have the following public member functions:
        Bank(int num): A constructor that takes the number of accounts as a parameter and dynamically allocates memory for the accounts.
        ~Bank(): A destructor that frees the dynamically allocated memory for the accounts.
        void performTransactions(): A function that performs some transactions (e.g., deposits and withdrawals) on the bank accounts.
        void displayAllBalances(): A function that displays the balances of all the bank accounts.

    Instructions:

    1. Implement the member functions of the BankAccount class.
    2. Implement the constructor and destructor of the Bank class.
    3. Implement the performTransactions function in the Bank class, 
       which simulates some transactions(ex: accounts[0]->deposit(1000)
                                             accounts[1]->deposit(500)
                                             accounts[2]->deposit(200)
                                             accounts[2]->withdraw(50)) on the bank accounts.
    4. In the main function, create an instance of the Bank class with a specific number of accounts.
    5. Call the performTransactions function on the Bank object to simulate transactions.
    6. Finally, call the displayAllBalances function to display the balances of all bank accounts.
    7. Make sure to deallocate any dynamically allocated memory in the appropriate locations.

    This exercise demonstrates the need for destructors because the Bank class dynamically allocates memory 
    for the BankAccount objects. Without a destructor, this memory would not be freed, leading to memory leaks.
*/


/* 
    Solution 
*/

class BankAccount{
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNumber){
        this->accountNumber = accNumber;
        this->balance = 0;
    }

    BankAccount(){
        accountNumber = 0;
        balance = 0;
    }

    
    void setAccountNumber(int number){
        accountNumber = number;
    }

    void deposit(double amount){
        if(amount > 0 ){
            balance += amount;
            cout << "Deposit successful. Current balance: " << balance << endl;
        }
    }

    void withdraw(double amount){
        if(amount > 0 && amount <= balance){
            balance -= amount;
            cout << "Withdrawal successful. Current balance: " << balance << endl;
        }
        else{
            cout << "Insufficient balance. Cannot withdraw." << endl;
        }
    }

    void displayBalance(){
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balamce: " << balance << endl;
    }
};

class Bank{
private:
    BankAccount* accounts;
    int numAccounts;

public:
    Bank(int num){
        this->accounts = new BankAccount[num];
        this->numAccounts = num;

        for(int i = 0; i < numAccounts; i++){
            accounts[i].setAccountNumber(i + 1);
        }
    }

    ~Bank(){
        delete[] accounts;
    }

    void performTransactions(){
        accounts[0].deposit(500);
        accounts[1].deposit(300);
        accounts[2].deposit(200);

        accounts[0].withdraw(100);
        accounts[1].withdraw(50);
    }

    void displayAllBalances(){
        for(int i = 0; i < numAccounts; ++i){
            accounts[i].displayBalance();
        }
    }
};

int main() {

    /*      Example usage:     */
    Bank bank(3);

    bank.performTransactions();
    bank.displayAllBalances();

    return 0;
}