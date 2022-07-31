/*
Index operator overloading program 
*/

#include <iostream>
using namespace std;

const int MAX = 50 ;

class indexOperatorOverloading
{
    int a[MAX];

    public:
    int & operator []( int i)
    {
        if ( i < 0 ||  i >= MAX )
        {
            cout << "\n array size out of bound\n";
            exit(1);
        }else{
            return a[i];
        }
    }


};


int main()
{
    indexOperatorOverloading obj;
    
    // filling the array
    for ( int i = 0 ; i<5; i ++)
    {
        obj[i]= i+1;
    }
    
    // printing the array
    for ( int i =0 ; i<5 ; i++ )
    {
        cout<< "\n"<< obj[i]<<" "<< endl;
    }

    // out of bound display
    obj[150]= 34; 
    
    return 0;
}