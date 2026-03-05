#include <iostream>
#include <fstream>

using namespace std;

// Open Close Principle (OCP)
// Open for extension but closed for modification
class Shape {
public:
    virtual double area() const = 0; // pure virtual function to be overridden by the extending child-class
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

int main()
{
   Shape* shape = new Circle(3.14);
   cout << "Circle area: " + to_string(shape->area()) + " m2" << endl;
   
   shape = new Rectangle(1.25, 2.55);
   cout << "Rectangle area: " + to_string(shape->area()) + " m2" << endl;
   
   return 0;
}