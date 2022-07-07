/*
qn6.cpp

Create a class with a data member to hold a "serial number" for each object created from the class.
That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept
of static data members. Use static member function if it is useful in the program. Otherwise,
make a separate program that demonstrates the use of static member function.

*/

#include <iostream>


class count
{
private:
    static int serial_number;

public:
    count()
    {
        serial_number+= 1;
    }
    static int get_object_number()
    {
        return serial_number;
    }

};
int count::serial_number=0;
int main()
{
        count c1,c2,c3,c4;
        std::cout<<"The total no of object declared is: "<< count::get_object_number();

    return 0;
}
