/*
qn3.cpp

Write a program to compare two objects of a class that contains an integer value as its data member.
Make overloading functions to overload equality(==), less than(<), greater than(>), not equal (!=),
greater than or equal to (>=), and less than or equal to(<=) operators using member operator functions.

*/

#include <iostream>
using namespace std;

class values
{
private:
    int a;

public:
    values(){};
    values(int x){ a= x; }
    int get_data() { return a; }

    bool operator == (const  values &b)
    {
       return(this->a== b.a);
    }
    bool operator<(const values &b)
    {
        return(this->a < b.a);
    }
    bool operator>(const values &b)
    {
        return(this->a > b.a);
    }
    bool operator!=(const values &b)
    {
        return(this->a!= b.a);
    }
    bool operator>=(const values &b)
    {
        return(this->a>= b.a);
    }
    bool operator<=(const values &b)
    {
        return(this->a <= b.a);
    }
};

int main()
{
    values d1{3}, d2{4};
  
    cout << std::boolalpha << (d1 == d2) << endl;
    cout << (d1 < d2) << endl;
    cout << (d1 > d2) << endl;  
    cout << (d1 != d2) << endl; 
    cout << (d1 >= d2) << endl;
    cout << (d1 <= d2) << endl;
    return 0;
}