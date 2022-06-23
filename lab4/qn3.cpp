/*
qn3.cpp

Write a class that can store Department ID and Department Name with constructors to 
initialize its members. Write destructor member in the same 
class and display the message "Object n goes out of the scope". Your program should be
made such that it should show the order of constructor and destructor invocation.
*/

#include <iostream>

class Department
{
private:
    int department_id;
    char department_name[20];
public:
    Department(){
        std::cout << "\nConstructor Invoked";
    }
    ~Department(){
        std::cout << "\nObject n goes out of the scope";
        std::cout<< "\nDestructor Invoked\n";
    }
};

int main()
{
    Department d;

    return 0;
}