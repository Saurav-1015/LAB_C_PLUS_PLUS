/* 
Logical operator overloading
*/

#include <iostream>
#include <iomanip>
using namespace std;

class LogicalOverloading
{
    bool a; 

    public:
    LogicalOverloading () { a = false; }
    LogicalOverloading ( bool a) 
    {
        this->a = a;
    }
    void display() { cout  << a << " ";}
    void set_data( bool a ){ this->a = a;}

    LogicalOverloading operator ||( LogicalOverloading l)
    {
        LogicalOverloading temp;
         bool temp_bool = (a || (l.a));
         temp.set_data(temp_bool);
        return ( temp );
    }
    LogicalOverloading operator &&( LogicalOverloading l)
    {
        LogicalOverloading temp;
         bool temp_bool = (a && (l.a));
         temp.set_data(temp_bool);
        return ( temp );
    }

};


int main()
{
    LogicalOverloading l1( false), l2(true), l3, l4 ;
    l3 = l1 || l2 ;
    l4 = l1 && l2;

    // boolalpha; 
    
    l3.display();
    l4.display();

    return 0;
}
 