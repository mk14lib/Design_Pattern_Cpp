#include <iostream>
using namespace std;

class PaymentMethod
{
    public:
    virtual void process() = 0; // pure virtual interface
};

class CreditCardPayment : public PaymentMethod
{
    public:
    void process() override {
        cout << "You chose Credit Card as payment method\n";
    }
};

class DebitCardPayment : public PaymentMethod
{
    public:
    void process() override {
        cout << "You chose Debit Card as payment method\n";
    }
};

class PayPalPayment : public PaymentMethod
{
    public:
    void process() override {
        cout << "You chose PayPal as payment method\n";
    }
};

class ApplePayPayment : public PaymentMethod
{
    public:
    void process() override {
        cout << "You chose ApplePay as payment method\n";
    }
};

class PaymentProcessor {
    PaymentMethod& pm;
public:
    PaymentProcessor(PaymentMethod& pm) : pm(pm) {}

    void execute()
    {
        pm.process();
        ProcessPayment();
    }

	void ProcessPayment()
	{
		cout << "> Credentials auto retrieved from personal database\n";
		cout << "> 10% .. 20% .. 100%\n";
		cout << "> Payment Successful!\n";
	}
};

int main()
{
    CreditCardPayment cc;
    DebitCardPayment dc;
    PayPalPayment pp;
    ApplePayPayment ap;
    
 	cout << "Choose a payment method\n";
	cout << " 1. Credit Card\n";
	cout << " 2. Debit Card\n";
	cout << " 3. PayPal\n";
	cout << " 4. ApplePay\n";
	cout << "Your Choice : ";
    
    int choice = 0;
    cin >> choice;
    
    switch(choice)
    {
        case 1: {
            PaymentProcessor pay(cc);
            pay.execute();
            break;
        }
        
        case 2: {
            PaymentProcessor pay(dc);
            pay.execute();
            break;
        }
        
        case 3: {
            PaymentProcessor pay(pp);
            pay.execute();
            break;
        }
        
        case 4: {
            PaymentProcessor pay(ap);
            pay.execute();
            break;
        }
        
        default: {
            cout << "Please choose from available payment methods\n";
            break;
        }
    }
	return 0;
}