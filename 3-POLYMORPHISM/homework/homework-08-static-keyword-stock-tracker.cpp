#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
/*double trackStockPrice(string symbol , double currentPrice){
    static map<string,double>HighestPrice;
    if(currentPrice > HighestPrice[symbol]){
        HighestPrice[symbol] = currentPrice;
    }
    cout << "The highest price of stock name is: " << symbol << " and its highest price is: ";
    return HighestPrice[symbol];

};

int main(){
    system("cls");
    cout << trackStockPrice("Etherium" , 800) <<endl;
    cout << trackStockPrice("Bitcoin" , 900) << endl;
    cout << trackStockPrice("Etherium" , 400) << endl;
}*/

/*class Account{
    private:
    int AccountNumber;
    double balance;
    static int nextAccountNumber;
    public:
    Account(double balance){
        this -> balance = balance;
        AccountNumber = nextAccountNumber;
        nextAccountNumber++;
    }
    ~Account(){
        nextAccountNumber--;
    }
    void withdraw(double amount){
        if(balance > amount && amount > 0){
            balance = balance - amount;
        }
        else{
            cout << "Invalid amount" <<endl;
        }
    }
    void deposit(double amount){
        if(amount > 0){
            balance = balance + amount;
        }
        else{
            cout << "Invalid amount" <<endl;
        }
    }
    void displayInfo(){
        cout << "Account Number: " << AccountNumber << "balance: " << balance << endl; 
    }

};
int Account::nextAccountNumber = 1001;
int main(){
    Account acc1(500);
    Account acc2(800);
    acc1.withdraw(399);
    acc2.deposit(800);
    acc1.displayInfo();
    acc2.displayInfo();
}*/


/*class OnlyOneInstance {
    private:
        static OnlyOneInstance *instance;
        OnlyOneInstance() {}

    public:
        OnlyOneInstance(const OnlyOneInstance &obj) = delete;
        
        static OnlyOneInstance *getInstance() {
            if (instance == nullptr) {
                instance = new OnlyOneInstance();
                return instance;
            } else {
                return instance;
            }
        }
};

OnlyOneInstance *OnlyOneInstance::instance = nullptr;
int main(){
    OnlyOneInstance* obj1 = OnlyOneInstance::getInstance();
    OnlyOneInstance* obj2 = OnlyOneInstance::getInstance();

    if(obj1 == obj2){
        cout << "Her ikisi eyni obyekte ishare edir!" << endl;
    }
}*/


/*vector<int>GetPrimes(int number){
    static vector<int>primes;
    for(int num = 2 ; num <= number ; num++){
        bool IsPrime = true;
        for(int i = 2 ; i<num ; i++){
            if(num%i == 0){
                IsPrime = false;
                break;
            }
        }
        if(IsPrime){
                primes.push_back(num);
            }
    }
    return primes;
}
int main(){
    system("cls");
    vector<int>primes = GetPrimes(100);
    for(int x : primes){
        cout << x << " ";
    }
}*/

