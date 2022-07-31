/*
Function call operator overloading
*/

#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    Complex() { real = 0 ; imag =0 ;}
    Complex operator () ( int re, int im )
    {
        real = re;
        imag = im;
        return (*this);
    }
    void display() { cout << "\nreal = " << real << " and imag = " << imag << endl; }
};

int main()
{
    Complex c1, c2;
    c1.display();
    c2 = c1(5, 3); // here c1 works as the function operator cause it works like a function here
    c2.display();
    return 0;
}