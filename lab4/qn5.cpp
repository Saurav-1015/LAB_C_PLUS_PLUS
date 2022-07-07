/*
qn5.cpp

Write a program that illustrates the following relationship and comment on them.

i) const_object.non_const_mem_function

ii) const_object.const_mem_function

iii) non_const_object.non_const_mem_function

iv) non_const_object.const_mem_function

*/
#include <iostream>

class Temporary
{

public:
     void display_constant( ) const
    {
        std::cout<<"constant member function called"<<std::endl;
    }
    void display_N( )
    {
        std::cout<<"non-constant member function called"<<std::endl;
    }
};
int main()
{
    const Temporary a;
    Temporary b;
    a.display_constant( );
    b.display_constant( );
    b.display_N( );

    return 0;
}
