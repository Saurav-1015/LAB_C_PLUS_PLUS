/*
qn1.cpp
Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.

A. Make a particular member function of one class as a friend function of another class for addition.
B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.
C. Also write a small program to demonstrate that all the member functions of one class are the friend functions of
another class if the former class is made friend to the latter.

Make least possible classes to demonstrate all the above in a single program without conflict.
*/

#include <iostream>
using namespace std;

class second_coordintate;
class store;
class frnd;

class first_coordintate
{

    int a1;
    int b1;

public:
    first_coordintate(int c, int d)
        : a1{c}, b1{d}
    {
    }

    int get_data_first() { return a1; }
    int get_data_second() { return b1; }

    friend void addition(first_coordintate f1, second_coordintate f);
    friend void multiplication(first_coordintate f1, second_coordintate f2);
    friend void subtraction(first_coordintate f1, second_coordintate f2);
    friend void division(first_coordintate f1, second_coordintate f2);

    friend class frnd;
};

class second_coordintate
{
    int a2;
    int b2;

public:
    second_coordintate(int c, int d)
        : a2{c}, b2{d}
    {
    }

    int get_data_first() { return a2; }
    int get_data_second() { return b2; }
    friend void multiplication(first_coordintate f1, second_coordintate f2);
    friend void subtraction(first_coordintate f1, second_coordintate f2);
    friend void division(first_coordintate f1, second_coordintate f2);

    void addition(first_coordintate f1, second_coordintate f2)
    {
        int a, b;
        a= f1.get_data_first() + f2.get_data_first();
        b= f1.get_data_second() + f2.get_data_second();
        cout<<"Addition: ( "<< a << " , " << b <<" )"<< endl;
    }
};

class frnd
{

    public:
    void Display(first_coordintate f){
        cout<<"\nFormer class elements are: "<< f.get_data_first()<< " and "<< f.get_data_second() << endl;
    }
};

void multiplication(first_coordintate f1, second_coordintate f2)
{
    float a, b;
    a=f1.get_data_first()*f2.get_data_first();
    b=f1.get_data_second()*f2.get_data_second();
    cout<<"Multiplication: ( "<< a << " , " << b <<" )"<< endl;
}
void subtraction(first_coordintate f1, second_coordintate f2)
{
    float a, b;
    a=f1.get_data_first()-f2.get_data_first();
    b=f1.get_data_second()-f2.get_data_second();
    cout<<"Subtraction: ( "<< a << " , " << b <<" )"<< endl;
   
}
void division(first_coordintate f1, second_coordintate f2)
{
  float a, b;
    a=static_cast<float>(f1.get_data_first())/f2.get_data_first();
    b=static_cast<float>(f1.get_data_second())/f2.get_data_second();
    cout<<"Division: ( "<< a << " , " << b <<" )"<< endl;
}

int main()
{
    first_coordintate f1{1, 2};
    second_coordintate f2{3, 4};
    frnd f;

    cout<<"\nCoordintes taken: (1,2) and (3,4)"<<endl<<endl;
    cout<< "Displaying the information:"<<endl<<endl;
    f2.addition(f1, f2);
    multiplication(f1,f2);
    division(f1,f2);
    subtraction(f1,f2);

    f.Display(f1);
    return 0;
}