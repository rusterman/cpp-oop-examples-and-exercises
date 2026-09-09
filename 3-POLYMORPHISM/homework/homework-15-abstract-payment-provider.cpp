#include<iostream>
using namespace std;
class PaymentMethod{
    public:
    virtual void ProcessPayment(double payment) = 0;
    virtual ~PaymentMethod(){}
    void logPaymentAttempt(double payment){
        cout << "Payment attempt logged for amount: " << payment << endl;
    }

};
class CreditCardPayment : public PaymentMethod{
    public:
    void ProcessPayment(double amount)override{
        cout << "Payment with credit card: " << amount << endl;
    }

};
class PayPalPayment : public PaymentMethod{
    public:
    void ProcessPayment(double amount)override{
        cout << "Payment with paypal: " << amount << endl;
    }

};
int main(){
    CreditCardPayment credit1;
    PayPalPayment paypal1;
    credit1.logPaymentAttempt(100);
    credit1.ProcessPayment(100);
    cout << "------------" <<endl;
    paypal1.logPaymentAttempt(100);
    paypal1.ProcessPayment(100);


}
