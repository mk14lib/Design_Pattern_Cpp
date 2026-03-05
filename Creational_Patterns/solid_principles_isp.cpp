#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

// Interface Segregation Princple (ISP)
class IPrinter {
public:
    virtual void print() = 0;
};

class IFax {
public:
    virtual void fax() = 0;
};

class Printer : public IPrinter {
public:
    void print() override {
        cout << "[IPrinter] Printing via IPrinter" << endl;
    }
};

class MultiFunctionPrinter : public IPrinter, public IFax { // client depends only on the required interfaces
public:
    void print() override {
        cout << "[MultiFunctionPrinter] Printing via IPrinter" << endl;
    }
    void fax() override {
        cout << "[MultiFunctionPrinter] Printing via IFax" << endl;
    }
};

int main()
{
    Printer printer1;
    printer1.print();
    
    MultiFunctionPrinter printer2;
    printer2.print();
    printer2.fax();
    
    return 0;
}