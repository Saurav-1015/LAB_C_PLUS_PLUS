/*
qn2.cpp

Write a class to store x, y, and z coordinates of a point in three-dimensional space.
Overload addition and subtraction operators for addition and subtraction of two coordinate objects.
Implement the operator functions as non-member functions (friend operator functions).
*/

#include <iostream>

using namespace std;

class space_coordinate
{
    int x;
    int y;
    int z;

public:
    space_coordinate(){};
    space_coordinate(int a, int b, int c)
    : x{a}, y{b}, z{c}
    {}

    int get_x() { return x; }
    int get_y() { return y; }
    int get_z() { return z; }

    void set_x(int a) { x=a; }
    void set_y(int b) { y=b; }
    void set_z(int c) { z=c; }
    friend space_coordinate operator + (space_coordinate s1, space_coordinate s2);
};

space_coordinate operator + (space_coordinate s1, space_coordinate s2)
{
    space_coordinate temp;
    int x,y,z;
    x= s1.get_x()+s2.get_x();
    y= s1.get_y()+s2.get_y();
    z= s1.get_z()+s2.get_z();
    temp.set_x(x);
    temp.set_y(y);
    temp.set_z(z);

    return temp;
}

space_coordinate operator - (space_coordinate s1, space_coordinate s2)
{
    space_coordinate temp;
    int x,y,z;
    x= s1.get_x()-s2.get_x();
    y= s1.get_y()-s2.get_y();
    z= s1.get_z()-s2.get_z();
    temp.set_x(x);
    temp.set_y(y);
    temp.set_z(z);

    return temp;
}

int main()
{
    space_coordinate s1{1,2,3}, s2{4,5,6};
    space_coordinate s3,s4;
    cout<<"\nCoordintes taken: (1,2,3) and (4,5,6)"<<endl<<endl;
    cout<< "Displaying the information:"<<endl<<endl;
    s3 = s1 + s2;
    s4 = s1-s2;
    cout<<"Addition: ( "<< s3.get_x() << " , "<< s3.get_y() << " , " << s3.get_z()<< " ) " << endl;
    cout<<"Subtraction: ( "<< s4.get_x() << " , "<< s4.get_y() << " , " << s4.get_z()<< " ) " << endl;
    return 0;
}