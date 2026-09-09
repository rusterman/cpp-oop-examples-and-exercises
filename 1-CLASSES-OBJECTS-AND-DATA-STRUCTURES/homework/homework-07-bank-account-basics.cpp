#include <iostream>
using namespace std;
class BankAccount {
    private:
    int accountNumber;
    double balance;
    static int totalAccount;
    public:
    BankAccount(int accountNumber , int balance = 0.0){
        this -> accountNumber = accountNumber;
        this -> balance = balance;
        ++totalAccount;
    }
    void deposit(double amount){
        balance = balance + amount;
    }
    void withdraw(double amount){
        if(amount > 0 && amount <= balance){
            balance = balance - amount;
        }
        else{
            cout <<  "Invalid Balance " <<endl;
        }
    }
    double getBalance(){
        return balance;
    }
    ~BankAccount(){
        --totalAccount;
        cout << "Account "<< accountNumber << " is closed." <<endl;
    }

};
int BankAccount::totalAccount = 0;

int main() {
    BankAccount account1(12345); // Account 1 created
    BankAccount account2(67890); // Account 2 created
    account1.deposit(1000);
    account2.deposit(500);
    cout << "Balance of account 1: " << account1.getBalance() << endl;
    cout << "Balance of account 2: " << account2.getBalance() << endl;
    return 0;
}
