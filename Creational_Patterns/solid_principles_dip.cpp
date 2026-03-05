#include <iostream>
using namespace std;

class IMessageService {
public:
    virtual void sendMessage(const std::string& message) = 0; // Abstract method
};

class EmailService : public IMessageService {
public:
    void sendMessage(const std::string& message) override {
        std::cout << "Email sent: " << message << std::endl;
    }
};

class SMSService : public IMessageService {
public:
    void sendMessage(const std::string& message) override {
        std::cout << "SMS sent: " << message << std::endl;
    }
};

class Notification {
    IMessageService* messageService; // Dependent on abstraction
public:
    Notification(IMessageService* service) : messageService(service) {}
    
    void notify(const std::string& message) {
        messageService->sendMessage(message); // Can call any implementation of IMessageService
    }
};


int main()
{
    IMessageService* email = new EmailService();
    IMessageService* sms = new SMSService();
    // email->sendMessage("Hello! there");
    
    Notification notifier(email);
    notifier.notify("Testing Dependency inversion principle with email_notifier object");
    
    Notification sms_notifier(sms);
    sms_notifier.notify("Testing the Dependency inversion principle with sms_notifier object");
    return 0;
}