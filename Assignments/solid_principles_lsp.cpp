#include <iostream>
using namespace std;

class Shape {
public:
    virtual int area() const = 0; // Pure virtual function
};

class Rectangle : public Shape {
private:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int getWidth() const { 
        return width;
    }

    int getHeight() const { 
        return height; 
    }

    virtual void setWidth(int w) { 
        width = w; 
    }

    virtual void setHeight(int h) { 
        height = h; 
    }

    int area() const override { 
        return width * height; 
    }
};

class Square : public Shape {
private:
    int side;

public:
    Square(int s) : side(s) {}

    int getSide() const { 
        return side; 
    }

    void setSide(int s) { 
        side = s; 
    }

    int area() const override { 
        return side * side; 
    }
};

/*
class Square : public Rectangle {
public:
    Square(int size) : Rectangle(size, size) {}

    void setWidth(int w) override { 
        width = height = w; 
    }

    void setHeight(int h) override { 
        width = height = h; 
    }
};

void process(Rectangle& rect) {
    int w = rect.getWidth();
    rect.setHeight(10);
    cout << "Expected area: " << (w * 10) << ", Actual area: " << rect.area() << endl;
}

int main()
{
    Rectangle rect(5, 5);
    process(rect); // Works as expected

    Square sq(5);
    process(sq); // Violates LSP, area will not be as expected

    return 0;
}
*/

int main()
{
    Rectangle rect(5, 5);
    cout << "Rectangle area: " << rect.area() << endl;

    Square sq(5);  
    cout << "Square area: " << sq.area() << endl;

    Shape* shape[]  = { &rect, &sq };
    for (Shape* s : shape) {   
        cout << "Area: " << s->area() << endl; 
    }
    return 0;
}
