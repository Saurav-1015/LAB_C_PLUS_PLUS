/*

qn5.cpp

Write a base class that asks the user to enter a complex number and
make a derived class that adds the complex number of its own with the base.
Finally, make a third class that is a friend of derived and calculate
the difference of the base complex number and its own complex number.

*/

#include <iostream>
using namespace std;

class complexNumber
{
    int real;
    int imag;

public:
    //    complexNumber( const complexNumber &obj){ real = obj.real ; imag = obj.imag; }
    complexNumber(){};
    complexNumber(int r, int i)
    {
        real = r;
        imag = i;
    }
    int get_real() { return real; }
    int get_imag() { return imag; }

    void display() { cout << "\n"
                          << real << " + i " << imag << endl; }
};

class addComplexNumber : public complexNumber
{
    int real;
    int imag;

public:
    addComplexNumber(int r=0, int i=0)
    {
        real = r;
        imag = i;
    }
    int get_real() { return real; }
    int get_imag() { return imag; }

    complexNumber operator+(complexNumber cn)
    {
        addComplexNumber temp;
        temp.real = real + cn.get_real();
        temp.imag = imag + cn.get_imag();
        return temp;
    }
    void display() { cout << "\n"
                          << real << " + i " << imag << endl; }
};

class friendDifferenceComplex : public complexNumber
{
    int real;
    int imag;
    
public:
    friendDifferenceComplex(int r, int i)
    {
        real = r;
        imag = i;
    }
};

int main()
{
    complexNumber c1(2, 5), c2;
    addComplexNumber a1(3, 7);
    cout << "\nInitially:\n";
    a1.display();
    c1.display();
    c2 = a1 + c1;
    cout << "\nAfter sum: \n";
    c2.display();

    return 0;
}