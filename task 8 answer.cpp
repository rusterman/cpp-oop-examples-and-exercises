#include<iostream>
#include<string>
using namespace std;
class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    
    BankAccount(int accNumber){
        accountNumber = accNumber;
        balance = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Invalid or insufficient funds." << endl;
        }
    }

    void displayBalance() {
        cout << "Account " << accountNumber << " balance: " << balance << endl;
    }
};

class Bank {
private:
    BankAccount** accounts;  
    int numAccounts;

public:
    
    Bank(int num) {
        numAccounts = num;
        accounts = new BankAccount*[numAccounts];
        for (int i = 0; i < numAccounts; i++) {
            accounts[i] = new BankAccount(1001 + i);
        }
    }

    
    ~Bank() {
        for (int i = 0; i < numAccounts; i++) {
            delete accounts[i];
        }
        delete[] accounts;
    }

    // Tapşırıqdakı əməliyyatlar
    void performTransactions() {
        if (numAccounts >= 3) {
            accounts[0]->deposit(1000);
            accounts[1]->deposit(500);
            accounts[2]->deposit(200);
            accounts[2]->withdraw(50);
        }
    }

    void displayAllBalances() {
        for (int i = 0; i < numAccounts; i++) {
            accounts[i]->displayBalance();
        }
    }
};
int main() {

    Bank bank(3);

    bank.performTransactions();
    bank.displayAllBalances();

    return 0;
}