#include<iostream>
#include<string>
using namespace std;
class BankAccount {
private:
    int accountNumber;
    double balance;
    static int count;

public:
    BankAccount(int accNumber) {
        accountNumber = accNumber;
        balance = 0.0;
        count++;
    }

    ~BankAccount() {
        count--;
        cout << "Account " << accountNumber << " closed." << endl;
        if (count == 0) {
            cout << "All accounts are closed." << endl;
        }
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

    double getBalance() const {
        return balance;
    }
};

int BankAccount::count = 0;

int main() {

    BankAccount account1(12345); 
    BankAccount account2(67890); 

    account1.deposit(1000);
    account2.deposit(500);

    cout << "Balance of account 1: " << account1.getBalance() << endl;
    cout << "Balance of account 2: " << account2.getBalance() << endl;

    

    return 0;
}