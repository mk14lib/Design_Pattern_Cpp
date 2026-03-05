#include <iostream>
using namespace std;

/**
 * PROBLEM: Dependency Inversion Principle (DIP) Violation
 *
 * The Dependency Inversion Principle states:
 * 1. High-level modules should not depend on low-level modules. Both should depend on abstractions.
 * 2. Abstractions should not depend on details. Details should depend on abstractions.
 *
 * Consequences of this violation:
 * 1. HIGH-LEVEL MODULES DEPEND ON LOW-LEVEL: Email and SMS classes depend directly on
 *    concrete NotificationService class (lines 18, 30)
 * 2. NO ABSTRACTION LAYER: No interface defines what a notification service should do
 * 3. TIGHT COUPLING: Email and SMS are tightly coupled to NotificationService implementation
 * 4. NO FLEXIBILITY: Cannot swap NotificationService with different implementations
 * 5. DIFFICULT TESTING: Cannot inject mock/stub implementations for unit testing
 * 6. VIOLATES OPEN/CLOSED: Adding new notification types requires creating new classes
 *    that still depend on the same concrete NotificationService
 *

class NotificationService
{
public:
    void send(string msg) {
        cout << msg << endl;
    }
};

class Email
{
    NotificationService mail;
    public:
    
    void sendEmail()
    {
        cout << "[MAIL] "; 
        mail.send("Hello, this is an email");
    }
};

class SMS
{
    NotificationService sms;
    public:
    void sendSMS()
    {
        cout << "[SMS] "; 
        sms.send("Hello, this is an sms");
    }
};

int main()
{
    Email email;
    email.sendEmail();
    
    SMS sms;
    sms.sendSMS();
    
    return 0;
}

 */

class INotificationChannel {
public:
    virtual void send(const string& ) = 0;
};

class EmailChannel : public INotificationChannel {
public:
    void send(const string& msg) {
        cout << "Email Sent: " << msg << endl;
    }
};

class SMSChannel : public INotificationChannel {
public:
    void send(const string& msg) {
        cout << "SMS Sent: " << msg << endl;
    }    
};

class PushChannel : public INotificationChannel {
public:
    void send(const string& msg) {
        cout << "Push Sent: " << msg << endl;
    }        
};

class NotificationService 
{
    INotificationChannel* channel;
    
public:
    NotificationService(INotificationChannel* chl) : channel(chl) {}
    
    void notify(const string& msg)
    {
        channel->send(msg);
    }
};

int main()
{
    INotificationChannel* sms = new SMSChannel();
    INotificationChannel* mail = new EmailChannel();
    
    NotificationService emailer(mail);
    NotificationService sms_notifier(sms);
    
    emailer.notify("Hello, there! This is an email!");
    sms_notifier.notify("Hello, there! This is an sms!");
    return 0;
}