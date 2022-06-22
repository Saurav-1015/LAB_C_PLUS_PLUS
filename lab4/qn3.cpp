/*
qn3.cpp

Write a class that can store Department ID and Department Name with constructors to 
initialize its members. Write destructor member in the same 
class and display the message "Object n goes out of the scope". Your program should be
made such that it should show the order of constructor and destructor invocation.
*/

#include <iostream>
#include <string>

class Department
{
private:
    int department_id;
    string department_name;
public:
    Department();
    ~Department();
};

Department::Department()
: department_id{12},  {
}

Department::~Department()
{
}


int main()
{

    return 0;
}