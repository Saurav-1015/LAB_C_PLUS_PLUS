/*
QN_3.cpp

Define two namespaces. Square and Cube. In both the namespaces, define an integer variable names "num" and a function named "fun".
The "fun" function in "Square" namespace, should return the square of an integer passed as an argument
while the "fun" function in "Cube" namespace, should return the cube of an integer passed as an argument.
In the main function, set the integer variables "num" of both the namespaces with different values. Then,
compute and print the cube of the integer variable "num" of the "Square" namspace using the "fun" funtion of the "Cube"
namespace and the square of the integer
variable "num" to the "Cube" namespace using the "fun" function of the "Square" namespace.
*/

#include <iostream>

namespace square{
    int num;

    inline int fun( int n) { return n*n; }
}

namespace cube{
    int num;
    inline int fun( int n) { return n*n*n; }

}

int main()
{

    square::num=10;
    cube::num=20;

    std::cout<<"Values before running function:"<<std::endl;
    std::cout<<square::num<<"\n"<<cube::num<<std::endl;

    std::cout<<"Square: "<<square::fun(cube::num)<<std::endl;

    std::cout<<"Cube: "<<cube::fun(square::num)<<std::endl;

    return 0;
}
