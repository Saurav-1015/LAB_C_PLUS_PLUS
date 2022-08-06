
# Lab 2 

### 1. Write a program to set a structure to hold date(mm,dd and yy), assign values to the members of the 
structure and print out the values in the format 11/28/2004 by function. Pass the structure to the function.

```c++
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
```

### 2. Write a program using the function overloading that coverts feet to inches. Use function with no argument, one argument and two argument. Decide yourself the types of arguments. Use pass by reference in any one of the function above.
```c++ 
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

```

### 3. Define two namespaces. Square and Cube. In both the namespaces, define an integer variable names "num" and a function named "fun". The "fun" function in "Square" namespace, should return the square of an integer passed as an argument while the "fun" function in "Cube" namespace, should return the cube of an integer passed as an argument. In the main function, set the integer variables "num" of both the namespaces with different values. Then, compute and print the cube of the integer variable "num" of the "Square" namspace using the "fun" funtion of the "Cube" namespace and the square of the integer variable "num" to the "Cube" namespace using the "fun" function of the "Square" namespace.
```c++ 

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

```
### 4. Write a function that passes two temperatures by reference and sets the larger of the two numbers to a value entered by user by using return by reference.

```c++ 
#include <iostream>

int &check_great(int &temp1, int &temp2){

    if(temp1> temp2)
    {
        return temp1;
    }else{
    return temp2;
    }
}


int main(){
    int temp1;
    int temp2;

    std::cout<<"Enter values of temperatures: "<<std::endl;
    std::cin>>temp1>>temp2;

    std::cout<<"Values before running function:\ntemp1= "<<temp1<<" and "<<"temp2= "<<temp2<<std::endl;
    std::cout<<"Enter the value for greater temperature:";
    std::cin>>check_great(temp1,temp2);

    std::cout<<"Values after running function:\ntemp1= "<<temp1<<" and "<<"temp2= "<<temp2<<std::endl;


    return 0;

}

```
### 5. Assume that employee will have to pay 10 percent income tax to the government. Ask user to enter the employee salary. Use inline function to display the net payment to the employee by the company.
```c++ 

#include <iostream>

inline void display(double salary) { std::cout<<"The net payment is:"<<salary-0.1*salary<<std::endl;}

int main()
{
    double salary;
    std::cout<<"Enter the employee salary: "<<std::endl;
    std::cin>>salary;

    display(salary);
}

```
### 6. Write a program that displays the current monthly salary of chief executive officer, information officer, and system analyst, programmer that has been increased by 9, 10, 12, and 12 percentages respectively in year 2010.

### Let us assume that the salaries in year 2009 are
### Chief executive officer Rs. 35000/m
### Information officer Rs. 25000/m
### System analyst Rs. 24000/m
### Programmer Rs. 18000/m

### Make a function that takes two arguments; one salary and the other increment. Use proper default argument.

```c++ 

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

```