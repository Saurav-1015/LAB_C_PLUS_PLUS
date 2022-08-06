## Lab 7
### 1. Write a program to create a class shape with functions to find the area of the shapes and display the names of the shapes and other essential components of the class. Create derived classes circle, rectangle, and trapezoid each having overriding functions area() and display(). Write a suitable program to illustrate virtual functions and virtual destructors.

```c++

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
```#

### 2. Create a class Person and two derived classes Employee and Student, inherited from class Person. Now create a class Manager which is derived from two base classes Employee and Student. Show the use of the virtual base class.
```c++
#include <iostream>
using namespace std;

class Person
{
    public:
        Person(int foo) {
            cout << foo << "\n";
        }
};

class Employee : virtual public Person
{
    public:
        Employee(int foo) : Person(foo){
            cout << foo << "\n";
        }

};


class Student : virtual public Person
{

public:
    Student(int foo): Person(foo) {cout << foo << "\n";}

};

class Manager : public Employee, Student
{
public:
    Manager(int foo, int bar, int baz) : Person(foo), Employee(bar), Student(baz) {
    cout << foo <<" "<< bar << endl;
    }

};


int main()
{
    Manager m(1, 2, 3);
    return 0;
}
```#

### 3. Write a program with an abstract class Student and create derive classes Engineering, Medicine and Science from base class Student. Create the objects of the derived classes and process them and access them using an array of pointers of type base class Student.
```c++

#include <iostream>
using namespace std;

class Student
{
public:
    virtual void display() =0;
};

class Engineering : public Student
{
public:
    void display() {cout<< "\nEngineering\n";}

};

class Medical : public Student
{
public:
    void display() {cout<< "medical\n";}

};

class Science : public Student
{
public:
    void display() {cout<< "science\n";}

};

int main()
{
    Engineering e;
    Medical m;
    Science s;

    Student *st[3];
    st[0] = & e;
    st[1] = & m;
    st[2] = & s;

    for (size_t i =0 ; i<3 ; i++)
    {
        st[i]->display();
    }
    return 0;
}


```#

### 4. Create a polymorphic class Vehicle and create other derived classes Bus, Car, and Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast and typeid operators in this program.
```c++

#include <iostream>
#include <typeinfo>
using namespace std;

class Vehicle
{
    public:
       virtual void display() {cout<<"Vehicle";}

};

class Bus : public Vehicle
{
 public:
        void display() {cout<<"Bus";}

};

class Car : public Vehicle
{
     public:
        void display() {cout<<"Car";}
};

class Bike : public Vehicle
{
     public:
        void display() {cout<<"Bike";}
};

int main()
{
    Vehicle* v;
    Bus b;
    Bus * pb;
    v= &b;

    cout<<typeid(*v).name();
    pb = dynamic_cast<Bus *> (v);
    
    if ( pb != NULL) 
    {
        cout<<"\ndowncast successfully"<<endl;
    }else{
        cout<<"fail to downcast"<< endl;
    }


    return 0;
}
```