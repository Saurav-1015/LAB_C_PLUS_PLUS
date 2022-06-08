
/*
QN_1.cpp

Write a program to set a structure to hold date(mm,dd and yy), assign values to the members of the 
structure and print out the values in the format 11/28/2004 by function. Pass the structure to the function.
*/

#include <iostream>
#include <iomanip>

struct date {
    int year;
    int month;
    int day;
};

void print_date(struct date s);
int main()
{

    struct date s;

    std::cout<<"Enter the year, month and day"<<std::endl;
    std::cout<<"---------------------------------------"<<std::endl;

// Taking input from user:

    std::cout<<"Year: ";
    std::cin>>s.year;

    std::cout<<"Month: ";
    std::cin>>s.month;

    std::cout<<"Day: ";
    std::cin>>s.day;

    print_date(s);

    return 0;
}

void print_date(struct date s){
    //displaying in 11/28/2004 format
   std::cout<<"\nDate:\n"
            <<std::setw(2)
            <<s.month<<"/"
            <<std::setw(2)
            <<s.day<<"/"
            <<std::setw(4)
            <<s.year
            <<std::endl;

}
