#include<iostream>
using namespace std;
class Account{
    protected:
    int AccountNumber;
    double balance;
    public:
    Account(int AccountNumber , double balance){
        this -> AccountNumber = AccountNumber;
        this -> balance = balance;
    }
    virtual void deposit(double amount){
        balance = balance + amount;
    }
    virtual void withdraw(double amount){
        if(amount > 0 && amount <= balance){
        balance = balance - amount;
        }
        else{
            cout << "Invalid amount" <<endl;
        }
    }
    virtual void displayBalance(){
        cout << "Account Number: " << AccountNumber << endl;
        cout << "Balance: " << balance <<endl;
    }
    virtual ~Account(){}
};
class SavingsAccount : public Account{
    private:
    double InterestRate;
    public:
    SavingsAccount(int AccountNumber , double balance , double InterestRate) : Account(AccountNumber , balance){
        this -> InterestRate = InterestRate;
    }
    virtual void displayBalance()override{
        Account :: displayBalance();
        cout << "Total balance(it means with inherit): " << balance + balance*(InterestRate/100) <<endl;
    }
    virtual void withdraw(double amount)override{
        Account::withdraw(amount);
    }
};
class CheckingAccount : public Account{
    public:
    CheckingAccount(int AccountNumber , double balance) : Account(AccountNumber , balance){}
    virtual void displayBalance() override{
        Account :: displayBalance();
        cout << "Checking Account balance: " <<balance <<endl;
    }
    virtual void withdraw(double amount)override{
        Account :: withdraw(amount);
    }
};
int main(){
    system("cls");
    Account *accounts[2];
    accounts[0] = new SavingsAccount(37737373 , 800.0 , 3);
    accounts[1] = new CheckingAccount(29929929 , 900.0);
    cout << "--------Operations---------" <<endl;
    accounts[0] -> withdraw(500.9);
    accounts[1] -> deposit(450.3);
    accounts[0] -> deposit(65.7);
    accounts[1] -> withdraw(7000.8);
    for(int i = 0 ; i < 2 ; i++){
        accounts[i] -> displayBalance();
    }
    for(int i = 0 ; i<2 ;i++){
        delete accounts[i];
    }


   
    
}
