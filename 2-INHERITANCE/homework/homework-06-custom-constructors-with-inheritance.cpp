#include<iostream>
using namespace std;
class Account{
    protected:
    int AccountNumber;
    string AccountHolder;
    double balance;
    public:
    Account(int AccountNumber = 0 , string AccountHolder = "Unknown" , double balance = 0){
        this -> AccountNumber = AccountNumber;
        this -> AccountHolder = AccountHolder;
        this -> balance = balance;
    }
    void deposit(double value){
        if(value > 0){
        cout << "deposit: " << value <<endl;
        balance = balance + value;
        cout << "balance: " << balance << endl;
        }
    }
    void withdraw(double value){
        cout << "Withdraw value: " << value << endl;
        if(value > 0 && value < balance){
            balance = balance - value;
            cout << "balance: " << balance << endl;
        }
        else{
            cout << "Invalid balance" <<endl;
        }
    }
    int getBalance(){
        return balance;
    }
};
class SavingsAccount : public Account{
    public:
    SavingsAccount(int AccountNumber , string AccountHolder , double balance) : Account(AccountNumber , AccountHolder , balance){
    }
    void applyInterest(double val){
        balance = balance + balance*val;
        cout << "Numerical value of the percentage: " << val << endl;
        cout << "balance: " << balance << endl; 
    }

};
class CheckingAccount : protected Account{
    public:
    CheckingAccount(int AccountNumber , string AccountHolder , double balance ) : Account(AccountNumber , AccountHolder , balance){
    }
    void applyMonthlyFee(double val){
        cout << "AplyMonthlyFee: " << val <<endl;
     if(balance >= val){
        balance = balance - val;
        cout << "balance: " <<balance<<endl;
    }
}
};
class CreditCardAccount : private Account{
    public:
    CreditCardAccount(int AccountNumber , string AccountHolder , double balance ) : Account(AccountNumber , AccountHolder , balance){
    }
    void makePurchase(double val){
        cout << "Purchase: " << val << endl;
        if(balance > val && val > 0){
            balance = balance - val;
            cout << "balance: " << balance << endl;
        }
        else{
            cout << "Invalid purchase" << endl;
        }
    }
};
int main(){
    system("cls");
    SavingsAccount savings(1001, "John Doe", 1000.0);
    CheckingAccount checking(2001, "Jane Smith", 1500.0);
    CreditCardAccount creditCard(3001, "Alice Johnson", 500.0);

    savings.deposit(500);
    savings.applyInterest(0.05);
    savings.withdraw(200);
    
    checking.applyMonthlyFee(10);

    creditCard.makePurchase(200);
    creditCard.makePurchase(400);
}
