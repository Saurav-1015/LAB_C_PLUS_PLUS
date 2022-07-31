/*
assignment operator overloading
*/

#include <iostream>
using namespace std;

class AssignmentOperator
{

    private: 
    int a ;

    public: 
    AssignmentOperator( int a = 0 ) { this->a  = a ;}
    int get_data() { return a;}
    void  set_data(int a ) { this->a = a ;}

    void operator =( AssignmentOperator as)
    {
        this->a = as.a;
    }

};

int main ()
{
    AssignmentOperator obj(5), obj1;
    cout<<"for first object: "<< obj.get_data();
    obj1 = obj;     // obj1.operator=(obj);
    cout<<"\nfor second object created: "<< obj1.get_data();

    return 0;
}