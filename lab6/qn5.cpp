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

    void set_real(int a) { real = a; }
    void set_imag(int b) { imag = b; }

    void display() { cout << "\n"
                          << real << " + i " << imag << endl; }
};

class addComplexNumber : public complexNumber
{
    int real;
    int imag;

public:
    addComplexNumber(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    addComplexNumber operator+(complexNumber cn)
    {
        addComplexNumber temp;
        int a = real + cn.get_real();
        temp.real = a;
        // std::cout << temp.real;
        int b = imag + cn.get_imag();
        temp.imag = b;
        // std::cout << temp.imag;
        return temp;
        // return addComplexNumber(a,b);
    }
    
    void display() { cout << "\n"
                          << real << " + i " << imag << endl; }
};

class friendDifferenceComplex : public complexNumber
{
    int real;
    int imag;

public:
    friendDifferenceComplex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    void display() { cout << "\n"
                         << real << " + i " << imag << endl; }

     friendDifferenceComplex operator-(complexNumber cn)
    {
        friendDifferenceComplex temp;
        int a =  cn.get_real() - real;
        temp.real = a;
        // std::cout << temp.real;
        int b = cn.get_imag() - imag;
        temp.imag = b;
        // std::cout << temp.imag;
        return temp;
        // return addComplexNumber(a,b);
    }
};

int main()
{
    complexNumber c1(2, 5), c2;
    addComplexNumber a1(3, 7), a2;
    friendDifferenceComplex fd1( 5, 4), fd2  ;
    a1.display();
    c1.display();
    a2 = a1 + c1; // a2 =  a1.operator(c1);
    cout << "\nAfter sum: \n";
    a2.display();

    cout << "\n----------------------------------\n";
    c1.display();
    fd1.display();
    fd2 = fd1 - c1;
    cout<<"\nAfter difference: \n";
    fd2.display();
    return 0;
}