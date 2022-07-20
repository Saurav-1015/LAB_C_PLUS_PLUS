/*
qn1.cpp

Write a program to create a class shape with functions to find the area of the shapes
and display the names of the shapes and other essential components of the class.
Create derived classes circle, rectangle, and trapezoid each having overriding
functions area() and display(). Write a suitable program to illustrate virtual functions
and virtual destructors.
*/

#include <iostream>
#include <cstring>
// #include <cstdlib>
using namespace std;

class Shape
{
protected:
    // string name;
    float Area;

public:
    virtual float area()=0;
    virtual void display()=0;
    virtual ~Shape(){cout<< "\nDestructor called for base class shapes \n";}
};

class circle : public Shape
{
    float r;

public:
    circle(float r = 0) { this->r = r; }
    float area()
    {
        Area = 3.14 * r * r;
        return Area;
    }
    void display()
    {
        area();
        cout << "\nThe area of circle is: " << Area;
    }
    ~circle() { cout << "\ncircle derived class destructor called"; }
};
class rectangle : public Shape
{
    float length, breadth;

public:
    rectangle(float l = 0, float b = 0)
    {
        length = l;
        breadth = b;
    }
    float area()
    {
        Area = length * breadth;
        return Area;
    }
    void display()
    {
        area();
        cout << "\nThe area of rectangle is: " << Area;
    }
    ~rectangle() { cout << "\nrectangle derived class destructor called"; }
};
class trapezoid : public Shape
{
    float a, b, dis;

public:
    trapezoid(float a, float b, float dis)
    {
        this->a = a;
        this->b = b;
        this->dis = dis;
    }
    float area()
    {
        Area = 0.5 * (a + b) * dis;
        return Area;
    }
    void display()
    {
        area();
        cout << "\nThe area of Trapezoid is: " << Area<<endl;
    }
    ~trapezoid() { cout << "\ntrapezoid destructor called"; }
};

int main()
{
    Shape *s[3];
    circle c(1);
    rectangle r(2,3);
    trapezoid t( 2,4,6);

    s[0] = &c;
    s[1] = &r;
    s[2] = &t;

    s[0]->display();
    s[1]->display();
    s[2]->display();

    return 0;
}