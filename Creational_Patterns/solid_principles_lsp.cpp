#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

// Liskov Substitution Principle (LSP)
class Bird {
public:
    virtual void fly() { std::cout << "I can fly!" << std::endl; }
};

class Sparrow : public Bird {};

class Ostrich : public Bird {
public:
    void fly() override { throw std::logic_error("I can't fly!"); } // Violates LSP
};


int main()
{
   Bird* sparrow = new Sparrow();
   cout << "Sparrow: ";
   sparrow->fly();
   
   Bird* ostrich = new Ostrich();
   
   try {
    ostrich->fly();
   } catch (const exception& e)
   {
       cout << "Ostrich: " << e.what() << endl;
   }
   return 0;
}