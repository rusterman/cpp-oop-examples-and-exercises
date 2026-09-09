#include <iostream>
#include <string>
using namespace std;
class BankAccount{
    private:
    int AccountNumber;
    int balance;
    public:
    BankAccount(int AccountNumber = 0, int balance = 0){
        this -> AccountNumber = AccountNumber;
        this -> balance = balance;
    }
    void Deposit(double amount){
        if(amount > 0){
            balance = balance + amount; 
        }
    }
    void WithDraw(double amount){
        if(amount > 0 && amount <= balance){
            balance = balance - amount;
        }
        else{
            cout << "Invalid balance" << endl;
        }
    }
    void DisplayBalnces(){
       cout << "Accoutn Number: " << AccountNumber << endl;
       cout << "Balance: " << balance << endl;
    }
};

class Bank{
    private:
    BankAccount* accounts;
    int NumAccounts;
    public:
    Bank(int NumAccounts = 0){
        this -> NumAccounts = NumAccounts;
        accounts = new BankAccount[NumAccounts];
        for(int i = 0; i < NumAccounts; i++){
            accounts[i] = BankAccount(i + 1);
        }
    }
    ~Bank(){
        delete [] accounts;
    }
    void performTransactions(){
        if(NumAccounts >= 3){
            accounts[0].Deposit(100);
            accounts[1].Deposit(100);
            accounts[2].Deposit(89);
            accounts[2].WithDraw(10);
        }
    }
    void displayAllBalances(){
        for(int i = 0 ; i < NumAccounts ; i++){
            accounts[i].DisplayBalnces();
        }
    }
};

int main() {
    system("cls");

    Bank bank(3);

    bank.performTransactions();
    bank.displayAllBalances();

    return 0;
}
