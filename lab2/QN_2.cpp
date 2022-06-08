/*
QN_2.cpp

Write a program using the function overloading that coverts feet to inches.
Use function with no argument, one argument and two argument. Decide yourself the types of arguments.
Use pass by reference in any one of the function above.
*/

#include <iostream>
#include <string>

float feet_to_inches(){
    std::cout<<"No argument passed funtion:"<<std::endl;
    return 0;
}

float feet_to_inches(int feet){
    return feet*12;
}

float feet_to_inches(int &feet,int &inches){
    std::cout<<"\nEnter inches if present: ";
    std::cin>>inches;
    return (feet*12+inches);
}
int main()
{
    int feet,inches;

    std::cout<<"Enter any number in feet: ";
    std::cin>>feet;

    feet_to_inches();
    std::cout<<std::endl;

    std::cout<<"Feet to inches: "<<feet_to_inches(feet)<<std::endl;
    std::cout<<"\nFeet to inches: "<<feet_to_inches(feet,inches)<<std::endl;

    return 0;

}
