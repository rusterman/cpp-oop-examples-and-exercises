#include<iostream>
#include<string>
using namespace std;




class BankAccount {
    private:
        int accountNumber;
        string holderName;
        double balance;

    public:
        
        BankAccount(int accountNumber, const string &holderName, double initialBalance) {
            this->accountNumber = accountNumber;
            this->holderName = holderName;
            this->balance = initialBalance;
        }

       
        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
                cout << "Deposited: " << amount << endl;
            } else {
                cout << "Invalid deposit amount." << endl;
            }
        }

       
        void withdraw(double amount) {
            if (amount <= 0) {
                cout << "Invalid withdrawal amount." << endl;
            } else if (amount > balance) {
                cout << "Insufficient funds." << endl;
            } else {
                balance -= amount;
                cout << "Withdrawn: " << amount << endl;
            }
        }

       
        double checkBalance() {
            return balance;
        }
};

int main() {

    BankAccount account(1001, "Aghademir", 500.0);

    cout << "Initial balance: " << account.checkBalance() << endl;

    account.deposit(200.0);
    cout << "Balance after deposit: " << account.checkBalance() << endl;

    account.withdraw(100.0);
    cout << "Balance after withdrawal: " << account.checkBalance() << endl;

    account.withdraw(1000.0);  // balansdan çox, xəta mesajı çıxmalıdır
    cout << "Final balance: " << account.checkBalance() << endl;

    return 0;
}