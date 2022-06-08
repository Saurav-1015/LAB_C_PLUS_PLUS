/*
QN_5.cpp

Assume that employee will have to pay 10 percent income tax to the government. Ask user to enter the
employee salary. Use inline function to display the net payment to the employee by the company.

*/

#include <iostream>

inline void display(double salary) { std::cout<<"The net payment is:"<<salary-0.1*salary<<std::endl;}

int main()
{
    double salary;
    std::cout<<"Enter the employee salary: "<<std::endl;
    std::cin>>salary;

    display(salary);
}
