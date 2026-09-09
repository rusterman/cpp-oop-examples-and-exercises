#include<iostream>
#include<string>
using namespace std;
class Payment {
    public:
        Payment() : amount(0.0), currency("USD"), status("Pending") {}

        void setAmount(double amt) { amount = amt; }
        void setCurrency(const string& curr) { currency = curr; }
        void setStatus(const string& stat) { status = stat; }

        double getAmount() const { return amount; }
        string getCurrency() const { return currency; }
        string getStatus() const { return status; }

        virtual void ProcessPayment(){
            cout << "Process payment..." << endl;
        }

        virtual ~Payment() {}

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
        virtual void ProcessPayment() override{
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
        virtual void ProcessPayment() override{
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
        virtual void ProcessPayment()override{
            executePayment();
        }
        
    private:
        string email;
};
int main(){
system("cls");

    CreditCardPayment creditCardPayment("Visa");
    DebitCardPayment debitCardPayment("Mastercard");
    PayPalPayment payPalPayment("example@example.com");

    creditCardPayment.setAmount(100.0);
    debitCardPayment.setAmount(50.0);
    payPalPayment.setAmount(200.0);

    Payment* payments[] = { &creditCardPayment, &debitCardPayment, &payPalPayment };

    for (Payment* payment : payments) {
        payment -> ProcessPayment();
    }
}
