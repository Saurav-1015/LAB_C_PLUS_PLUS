

/*

QN_6.cpp

Write a program that displays the current monthly salary of chief executive officer, information officer,
and system analyst, programmer that has been increased by 9, 10, 12, and 12 percentages respectively
in year 2010.

Let us assume that the salaries in year 2009 are
Chief executive officer Rs. 35000/m
Information officer Rs. 25000/m
System analyst Rs. 24000/m
Programmer Rs. 18000/m

Make a function that takes two arguments; one salary and the other increment. Use proper default
argument.
*/

#include <iostream>

void display(int s, int increment=0){
    std::cout<<"\nSalary after increment is: "<<(s+s*increment/100)<<std::endl;
}
int main()
{

    int ceo_salary=35000;
    int io_salary=25000;
    int sy_analyst_salay=24000;
    int programmer_salary=18000;

    std::cout<<"CE0 SALARY: ";
    display(ceo_salary,9);
    std::cout<<"INFORMATION OFFICER SALARY: ";
    display(io_salary,10);
    std::cout<<"SYSTEM ANALYST SALARY: ";
    display(sy_analyst_salay,12);
    std::cout<<"PROGRAMMER SALARY: ";
    display(programmer_salary,12);


    return 0;
}
