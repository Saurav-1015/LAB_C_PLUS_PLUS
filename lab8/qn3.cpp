/*
Write a program to overload stream operators to read a complex number and display the complex number in 
a + ib format.
*/

#include <iostream>
// #include <iomanip>
using namespace std;

class Complex
{

    private: 
    int re;
    int imag;

    public:
    Complex( int r = 0, int i = 0) { re = r ; imag = i;}
    friend istream& operator>>( istream& is , Complex& c);
    friend ostream& operator<<( ostream& os , Complex& c);
    
};

istream& operator>>( istream& is , Complex& co)
{
    is>>co.re>> co.imag;
    return is;
}

ostream& operator<<( ostream& os , Complex& co)
{
    os << co.re<< " + i "<< co.imag;
    return os;
}

int main()
{
    Complex c;
    cout << "Enter the real and imaginary part for the complex number:" << endl;
    cin >> c;
    cout <<"The complex number is:"<< endl;
    cout << c;

return 0;
}