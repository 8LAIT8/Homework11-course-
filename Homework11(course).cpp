/*1)
#include <iostream>
using namespace std;

class SimpleCircle {
public:
    
    SimpleCircle() : radius(10.0) {}
    SimpleCircle(double r) {
        if (r >= 0) {
            radius = r;
        }
        else {
            cout << "Radius can't be smaller than 0!" << endl;
            radius = 0.0;
        }
    }

    SimpleCircle& operator++() {
        ++radius;
        return *this;
    }

    SimpleCircle operator++(int) {
        SimpleCircle temp = *this; 
        radius++;
        return temp;
    }

    double GetRadius() const {
        return radius;
    }

private:
    double radius;
};

int main() {
    SimpleCircle circle(100.0);

    cout << "Radius: " << circle.GetRadius() << endl;

    ++circle;
    cout << "Radius1: " << circle.GetRadius() << endl;

    circle++; 
    cout << "Radius2: " << circle.GetRadius() << endl;

    return 0;
}
*/
/*2)
#include <iostream>
using namespace std;

class SimpleCircle {
public:
    
    SimpleCircle() {
        itsRadius = new double(10.0);
    }

    SimpleCircle(double r) {
        if (r >= 0) {
            itsRadius = new double(r);
        }
        else {
            cout << "Radius can't be smaller than 0!" << endl;
            itsRadius = new double(0.0);
        }
    }

    ~SimpleCircle() {
        delete itsRadius; 
    }

    double GetRadius() const {
        return *itsRadius;
    }

    void SetRadius(double r) {
        if (r >= 0) {
            *itsRadius = r;
        }
        else {
            cout << "Radius can't be negative!" << endl;
        }
    }

    SimpleCircle& operator++() {
        ++(*itsRadius); 
        return *this;
    }

    SimpleCircle operator++(int) {
        SimpleCircle temp(*itsRadius);
        (*itsRadius)++;
        return temp;
    }

private:
    double* itsRadius;
};

int main() {
    SimpleCircle circle; 
    cout << "Radius: " << circle.GetRadius() << endl;

    circle.SetRadius(10.0);
    cout << "Radius1: " << circle.GetRadius() << endl;

    ++circle;
    cout << "Radius2: " << circle.GetRadius() << endl;

    circle++; 
    cout << "Radius3: " << circle.GetRadius() << endl;

    SimpleCircle anotherCircle(15.0); 
    cout << "Another Circle Radius: " << anotherCircle.GetRadius() << endl;

    return 0;
}
*/
/*3)
#include <iostream>
using namespace std;

class SimpleCircle {
public:
    SimpleCircle() {
        itsRadius = new double(10.0); 
    }

    SimpleCircle(double r) {
        if (r >= 0) {
            itsRadius = new double(r);
        }
        else {
            cout << "Radius can't be smaller than 0!" << endl;
            itsRadius = new double(0.0);
        }
    }

    SimpleCircle(const SimpleCircle& other) {
        itsRadius = new double(*(other.itsRadius));
    }

    ~SimpleCircle() {
        delete itsRadius; 
    }

    double GetRadius() const {
        return *itsRadius;
    }

    void SetRadius(double r) {
        if (r >= 0) {
            *itsRadius = r;
        }
        else {
            cout << "Radius can't be negative!" << endl;
        }
    }

private:
    double* itsRadius; 
};

int main() {
    
    SimpleCircle circle1(25.0);
    cout << "Circle1 Radius: " << circle1.GetRadius() << endl;

    SimpleCircle circle2 = circle1;
    cout << "Circle2 Radius: " << circle2.GetRadius() << endl;

    circle1.SetRadius(20.0);
    cout << "Circle1.1: " << circle1.GetRadius() << endl;
    cout << "Circle2.1: " << circle2.GetRadius() << endl;

    return 0;
}
*/
/*4)
#include <iostream>
using namespace std;

class SimpleCircle {
public:
    SimpleCircle() {
        itsRadius = new double(5.0);
    }

    SimpleCircle(double r) {
        if (r >= 0) {
            itsRadius = new double(r);
        }
        else {
            cout << "Radius cannot be negative! Setting radius to 0." << endl;
            itsRadius = new double(0.0);
        }
    }

    
    SimpleCircle(const SimpleCircle& other) {
        itsRadius = new double(*(other.itsRadius)); 
    }

    
    SimpleCircle& operator=(const SimpleCircle& other) {
        if (this == &other) {
            return *this; 
        }

        
        delete itsRadius;

        
        itsRadius = new double(*(other.itsRadius));
        return *this;
    }

    
    ~SimpleCircle() {
        delete itsRadius;
    }

    
    double GetRadius() const {
        return *itsRadius;
    }

    
    void SetRadius(double r) {
        if (r >= 0) {
            *itsRadius = r;
        }
        else {
            cout << "Radius cannot be negative!" << endl;
        }
    }

private:
    double* itsRadius; 
};

int main() {
    SimpleCircle circle1(10.0);
    cout << "Circle1 Radius: " << circle1.GetRadius() << endl;

    SimpleCircle circle2(20.0);
    cout << "Circle2 Radius: " << circle2.GetRadius() << endl;

   
    circle2 = circle1; 
    cout << "Circle2 Radius1: " << circle2.GetRadius() << endl;

    
    circle1 = circle1; 
    cout << "Circle1 Radius1: " << circle1.GetRadius() << endl;

    return 0;
}
*/
/*5)
#include <iostream>
using namespace std;

class SimpleCircle {
public:
    
    SimpleCircle() {
        itsRadius = new double(5.0); 
    }

    
    SimpleCircle(double r) {
        if (r >= 0) {
            itsRadius = new double(r);
        }
        else {
            cout << "Radius cannot be negative! Setting radius to 0." << endl;
            itsRadius = new double(0.0);
        }
    }

    
    SimpleCircle(const SimpleCircle& other) {
        itsRadius = new double(*(other.itsRadius));
    }

    
    SimpleCircle& operator=(const SimpleCircle& other) {
        if (this == &other) {
            return *this; 
        }
        delete itsRadius;
        itsRadius = new double(*(other.itsRadius));
        return *this;
    }

   
    SimpleCircle& operator++() {
        ++(*itsRadius);
        return *this;
    }

    
    SimpleCircle operator++(int) {
        SimpleCircle temp(*this);
        ++(*itsRadius);
        return temp;
    }

    
    ~SimpleCircle() {
        delete itsRadius;
    }

   
    double GetRadius() const {
        return *itsRadius;
    }

private:
    double* itsRadius;
};

int main() {
    
    SimpleCircle circle1; 
    SimpleCircle circle2(9.0); 

    
    cout << "Circle1 Radius: " << circle1.GetRadius() << endl;
    ++circle1; 
    cout << "Circle1.1 Radius: " << circle1.GetRadius() << endl;

    cout << "Circle2 Radius: " << circle2.GetRadius() << endl;
    circle2++; 
    cout << "Circle2.1 Radius: " << circle2.GetRadius() << endl;

    circle1 = circle2;
    cout << "Circle1.2 Radius: " << circle1.GetRadius() << endl;

    return 0;
}
*/
/*8)
#include <iostream>
using namespace std;


class Shape {
public:
    Shape() {
        cout << "Shape constructor called" << endl;
    }
    virtual ~Shape() {
        cout << "Shape destructor called" << endl;
    }

    virtual void Draw() const = 0; 
};


class Rectangle : public Shape {
public:
    Rectangle(double width, double height)
        : itsWidth(width), itsHeight(height) {
        cout << "Rectangle constructor was called" << endl;
    }

    ~Rectangle() override {
        cout << "Rectangle destructor was called" << endl;
    }

    void Draw() const override {
        cout << "Drawing Rectangle with width " << itsWidth
            << " and height " << itsHeight << endl;
    }

    double GetWidth() const { return itsWidth; }
    double GetHeight() const { return itsHeight; }

protected:
    double itsWidth;
    double itsHeight;
};


class Square : public Rectangle {
public:
    Square(double side)
        : Rectangle(side, side) { 
        cout << "Square constructor was called" << endl;
    }

    ~Square() override {
        cout << "Square destructor was called" << endl;
    }

    void Draw() const override {
        cout << "Drawing Square with side " << itsWidth << endl;
    }
};

int main() {
    Square mySquare(5.0);
    mySquare.Draw();

    return 0;
}
*/
/*9)
#include <iostream>
using namespace std;


class Shape {
public:
    Shape() {
        cout << "Shape constructor was called" << endl;
    }
    virtual ~Shape() {
        cout << "Shape destructor was called" << endl;
    }
    virtual void Draw() const = 0; 
};


class Rectangle : public Shape {
public:
    Rectangle(double length, double width)
        : itsLength(length), itsWidth(width) {
        cout << "Rectangle constructor was called with length: " << length
            << " and width: " << width << endl;
    }

    ~Rectangle() override {
        cout << "Rectangle destructor was called" << endl;
    }

    void Draw() const override {
        cout << "Drawing Rectangle with length " << itsLength
            << " and width " << itsWidth << endl;
    }

protected:
    double itsLength;
    double itsWidth;
};


class Square : public Rectangle {
public:
    Square(double length)
        : Rectangle(length, length) { 
        cout << "Square constructor was called with length: " << length << endl;
    }

    ~Square() override {
        cout << "Square destructor was called" << endl;
    }

    void Draw() const override {
        cout << "Drawing Square with side " << itsLength << endl;
    }
};

int main() {
    Square mySquare(5.0);
    mySquare.Draw();

    return 0;
}
*/