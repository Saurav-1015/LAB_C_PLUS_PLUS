/* 
Logical operator overloading
*/

#include <iostream>
#include <iomanip>
using namespace std;

class BitwiseOverloading
{
    int a; 

    public:
    BitwiseOverloading () { a = 0; }
    BitwiseOverloading ( int a) 
    {
        this->a = a;
    }
    void display() { cout  << a << " ";}
    void set_data( int a ){ this->a = a;}

    BitwiseOverloading operator |( BitwiseOverloading l)
    {
        BitwiseOverloading temp;
         int temp_int = (a | (l.a));
         temp.set_data(temp_int);
        return ( temp );
    }
    BitwiseOverloading operator &( BitwiseOverloading l)
    {
        BitwiseOverloading temp;
         int temp_int = (a & (l.a));
         temp.set_data(temp_int);
        return ( temp );
    }

};


int main()
{
    BitwiseOverloading l1(5), l2(9), l3, l4 ;
    l3 = l1 | l2 ;
    l4 = l1 & l2;

    // boolalpha; 
    
    l3.display();   // 13
    l4.display();   // 1

    return 0;
}
 