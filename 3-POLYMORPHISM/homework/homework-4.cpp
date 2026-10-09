#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: Decide on Virtual Methods

    You are provided with a payment processing system implemented in C++. 
    The system includes a base class Payment and three derived classes: CreditCardPayment, 
    DebitCardPayment, and PayPalPayment. Each payment method has its own unique behavior.

    Your task is to decide which methods should be polymorphic (i.e., override in derived classes) 
    and modify the code accordingly. 
    
    Follow these steps:

    1. Review the existing code and identify methods that should be made virtual (polymorphic). 
    Polymorphic methods are those that have a different implementation in the derived classes 
    and are related to the specific payment method.
    2. Implement virtual methods in the derived classes by overriding the base class method.
    3. Update the main function to create instances of different payment methods, set payment details, 
    and process payments using polymorphism.
    4. Test the code to ensure that each payment method behaves correctly and that polymorphism is used effectively.

    Note: You can make any method virtual if it is related to the specific payment method's behavior. 
    Some methods may not need to be virtual if they have a common implementation across all payment methods.
*/

class Payment {
    public:
        Payment() : amount(0.0), currency("USD"), status("Pending") {}

        void setAmount(double amt) { amount = amt; }
        void setCurrency(const string& curr) { currency = curr; }
        void setStatus(const string& stat) { status = stat; }

        double getAmount() const { return amount; }
        string getCurrency() const { return currency; }
        string getStatus() const { return status; }

        // Decide which methods should be virtual and make them so.
        // ?? void processPayment() {
        //     // Implement processPayment in derived classes if needed
        // }
        

        virtual ~Payment() {}
        virtual void processPayment() = 0;

    private:
        double amount;
        string currency;
        string status;
};


class CreditCardPayment : public Payment {
    public:
        CreditCardPayment(const string& cardType) : cardType(cardType) {}

        void authorizePayment() {
            cout << "Authorizing Credit Card Payment of " << getAmount() << " " << getCurrency() << " (Card Type: " << cardType << ")" << endl;
            setStatus("Authorized");
        }

        // Override the base class method if it's virtual
        // void processPayment()
        void processPayment() override {
    authorizePayment();
}
        

    private:
        string cardType;
};


class DebitCardPayment : public Payment {
    public:
        DebitCardPayment(const string& cardType) : cardType(cardType) {}

        void verifyFunds() {
            cout << "Verifying Funds for Debit Card Payment of " << getAmount() << " " << getCurrency() << " (Card Type: " << cardType << ")" << endl;
            setStatus("Funds Verified");
        }

        // Override the base class method if it's virtual
        // void processPayment()
        void processPayment() override {
    verifyFunds();
}

    private:
        string cardType;
};


class PayPalPayment : public Payment {
    public:
        PayPalPayment(const string& email) : email(email) {}

        void executePayment() {
            cout << "Executing PayPal Payment of " << getAmount() << " " << getCurrency() << " (Email: " << email << ")" << endl;
            setStatus("Executed");
        }

        // Override the base class method if it's virtual
        // void processPayment()
        void processPayment() override {
    executePayment();
}

    private:
        string email;
};


int main() {
    
    system("clear");

    CreditCardPayment creditCardPayment("Visa");
    DebitCardPayment debitCardPayment("Mastercard");
    PayPalPayment payPalPayment("example@example.com");

    creditCardPayment.setAmount(100.0);
    debitCardPayment.setAmount(50.0);
    payPalPayment.setAmount(200.0);

    Payment* payments[] = { &creditCardPayment, &debitCardPayment, &payPalPayment };

    for (Payment* payment : payments) {
        // Use polymorphism to process payments
        // TODO:
    }
    for (Payment* payment : payments) {
    payment->processPayment(); // hər biri öz metodunu çağıracaq
    cout << "Status: " << payment->getStatus() << endl;
}

    return 0;
}
