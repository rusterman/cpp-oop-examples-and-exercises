#include <iostream>
#include <string>

using namespace std;


/*
    Static Keyword in C++
*/


/*
    Exercise-1: Stock Price Tracker

    Write a C++ program that simulates a stock price tracker function. 
    The stock price tracker function should have the following properties:

    1. Create a function named trackStockPrice that takes the stock symbol (a string) and the current stock price (a double) as parameters.
    2. Inside the function, maintain a static local variable that stores the highest stock price observed for a given stock symbol.
    3. Update the highest stock price if the current price is higher.
    4. The function should return the highest stock price observed for the given stock symbol.


*/
double trackStockPrice(string symbol, double currentPrice) {
    // your code
     static double highestPrice = 0.0; 
    if (currentPrice > highestPrice) {
        highestPrice = currentPrice;
    }
    return highestPrice;

}


/*
    Exercise-2: Bank Account Management

    Create a C++ program that models a simplified bank account management system. 
    In this system, you will create a BankAccount class with the following features:

    1. Each BankAccount object should have a unique account number that starts from 1001 and increments by 1 for each new account created.
    2. Each account should have an account balance.
    3. Implement methods to deposit and withdraw funds from the account.
    4. Implement a method to display the account details, including the account number and balance.
*/
class BankAccount {
    // your code
    private:
    int accountNumber;
    double balance;
    static int nextAccountNumber;
public:
    static int totalAccounts;

    BankAccount() {
        accountNumber = nextAccountNumber++;
        balance = 0.0;
        totalAccounts++;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
        else cout << "Insufficient funds!" << endl;
    }

    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber 
             << ", Balance: " << balance << endl;
    }
};

int BankAccount::nextAccountNumber = 1001;
int BankAccount::totalAccounts = 0;




/*
    Exercise-3: One instance Class

    Create a C++ program that implements a  class, 
    which ensures that only one instance(object) of the class can be created. 
*/
class OnlyOneInstance {
    // your code

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


/*
    Exercise-4: Prime Number Caching

    Objective:
    Write a C++ program that efficiently generates and caches prime numbers up to 100 and allows you to query the cached prime numbers.

    Requirements:
    1. Implement a function that generates prime numbers up to 100(e.g., generatePrimes(int limit)).
    2. Cache the generated prime numbers for quick retrieval.
    4. Create a menu-driven user interface to interact with the caching system.
    5. Generate and cache prime numbers up to a specified limit.
    6. Check if a number is prime using the cached data.
*/
static int primes[100] = {0};
static int primeCount = 0;

void generateAndCachePrimes(int limit) {
    primeCount = 0;
    for (int num = 2; num <= limit; num++) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes[primeCount++] = num;
        }
    }
}

bool isPrimeCached(int number) {
    for (int i = 0; i < primeCount; i++) {
        if (primes[i] == number) return true;
    }
    return false;
}

static int primes[100] = {0};   // Static cache for Prime numbers






int main() {
    BankAccount account1;
    account1.deposit(1000);
    account1.withdraw(500);
    account1.displayAccountDetails();

    BankAccount account2;
    account2.deposit(1500);
    account2.displayAccountDetails();

    // Display the total number of accounts created.
    std::cout << "Total Accounts Created: " << BankAccount::totalAccounts << std::endl;

    return 0;
}




int main() {

    //  Exercise-1: example usage
    double price1 = trackStockPrice("AAPL", 150.25);
    cout << "Highest AAPL Stock Price: $" << price1 << endl;

    double price2 = trackStockPrice("GOOGL", 2700.50);
    cout << "Highest GOOGL Stock Price: $" << price2 << endl;

    double price3 = trackStockPrice("AAPL", 155.75);
    cout << "Highest AAPL Stock Price: $" << price3 << endl;

    double price4 = trackStockPrice("TSLA", 800.00);
    cout << "Highest TSLA Stock Price: $" << price4 << endl;



    //  Exercise-2: example usage
    BankAccount account1;
    account1.deposit(1000);
    account1.withdraw(500);
    account1.displayAccountDetails();

    BankAccount account2;
    account2.deposit(1500);
    account2.displayAccountDetails();

    // Display the total number of accounts created.
    cout << "Total Accounts Created: " << BankAccount::totalAccounts << endl;



    // Exercise-3: example usage
    // your code ;-)
     OnlyOneInstance* obj1 = OnlyOneInstance::getInstance();
    OnlyOneInstance* obj2 = OnlyOneInstance::getInstance();
    cout << "Singleton test: " << (obj1 == obj2 ? "Same instance" : "Different instances") << endl;



    // Exercise-4: example usage
    // your code ;-)
    generateAndCachePrimes(100);
    cout << "Is 37 prime? " << (isPrimeCached(37) ? "Yes" : "No") << endl;
    cout << "Is 40 prime? " << (isPrimeCached(40) ? "Yes" : "No") << endl;

    return 0;


}