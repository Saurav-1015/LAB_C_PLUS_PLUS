## Lab 5 

### 1. Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.

A. Make a particular member function of one class as a friend function of another class for addition.

B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.

C. Also write a small program to demonstrate that all the member functions of one class are the friend functions of another class if the former class is made friend to the latter.

Make least possible classes to demonstrate all the above in a single program without conflict.
```c++

#include <iostream>
using namespace std;

class second_coordintate;
class store;
class frnd;

class first_coordintate
{

    int a1;
    int b1;

public:
    first_coordintate(int c, int d)
        : a1{c}, b1{d}
    {
    }

    int get_data_first() { return a1; }
    int get_data_second() { return b1; }

    friend void addition(first_coordintate f1, second_coordintate f);
    friend void multiplication(first_coordintate f1, second_coordintate f2);
    friend void subtraction(first_coordintate f1, second_coordintate f2);
    friend void division(first_coordintate f1, second_coordintate f2);

    friend class frnd;
};

class second_coordintate
{
    int a2;
    int b2;

public:
    second_coordintate(int c, int d)
        : a2{c}, b2{d}
    {
    }

    int get_data_first() { return a2; }
    int get_data_second() { return b2; }
    friend void multiplication(first_coordintate f1, second_coordintate f2);
    friend void subtraction(first_coordintate f1, second_coordintate f2);
    friend void division(first_coordintate f1, second_coordintate f2);

    void addition(first_coordintate f1, second_coordintate f2)
    {
        int a, b;
        a= f1.get_data_first() + f2.get_data_first();
        b= f1.get_data_second() + f2.get_data_second();
        cout<<"Addition: ( "<< a << " , " << b <<" )"<< endl;
    }
};

class frnd
{

    public:
    void Display(first_coordintate f){
        cout<<"\nFormer class elements are: "<< f.get_data_first()<< " and "<< f.get_data_second() << endl;
    }
};

void multiplication(first_coordintate f1, second_coordintate f2)
{
    float a, b;
    a=f1.get_data_first()*f2.get_data_first();
    b=f1.get_data_second()*f2.get_data_second();
    cout<<"Multiplication: ( "<< a << " , " << b <<" )"<< endl;
}
void subtraction(first_coordintate f1, second_coordintate f2)
{
    float a, b;
    a=f1.get_data_first()-f2.get_data_first();
    b=f1.get_data_second()-f2.get_data_second();
    cout<<"Subtraction: ( "<< a << " , " << b <<" )"<< endl;
   
}
void division(first_coordintate f1, second_coordintate f2)
{
  float a, b;
    a=static_cast<float>(f1.get_data_first())/f2.get_data_first();
    b=static_cast<float>(f1.get_data_second())/f2.get_data_second();
    cout<<"Division: ( "<< a << " , " << b <<" )"<< endl;
}

int main()
{
    first_coordintate f1{1, 2};
    second_coordintate f2{3, 4};
    frnd f;

    cout<<"\nCoordintes taken: (1,2) and (3,4)"<<endl<<endl;
    cout<< "Displaying the information:"<<endl<<endl;
    f2.addition(f1, f2);
    multiplication(f1,f2);
    division(f1,f2);
    subtraction(f1,f2);

    f.Display(f1);
    return 0;
}
```

### 2. Write a class to store x, y, and z coordinates of a point in three-dimensional space. Overload addition and subtraction operators for addition and subtraction of two coordinate objects. Implement the operator functions as non-member functions (friend operator functions).
```c++
#include <iostream>

using namespace std;

class space_coordinate
{
    int x;
    int y;
    int z;

public:
    space_coordinate(){};
    space_coordinate(int a, int b, int c)
    : x{a}, y{b}, z{c}
    {}

    int get_x() { return x; }
    int get_y() { return y; }
    int get_z() { return z; }

    void set_x(int a) { x=a; }
    void set_y(int b) { y=b; }
    void set_z(int c) { z=c; }
    friend space_coordinate operator + (space_coordinate s1, space_coordinate s2);
};

space_coordinate operator + (space_coordinate s1, space_coordinate s2)
{
    space_coordinate temp;
    int x,y,z;
    x= s1.get_x()+s2.get_x();
    y= s1.get_y()+s2.get_y();
    z= s1.get_z()+s2.get_z();
    temp.set_x(x);
    temp.set_y(y);
    temp.set_z(z);

    return temp;
}

space_coordinate operator - (space_coordinate s1, space_coordinate s2)
{
    space_coordinate temp;
    int x,y,z;
    x= s1.get_x()-s2.get_x();
    y= s1.get_y()-s2.get_y();
    z= s1.get_z()-s2.get_z();
    temp.set_x(x);
    temp.set_y(y);
    temp.set_z(z);

    return temp;
}

int main()
{
    space_coordinate s1{1,2,3}, s2{4,5,6};
    space_coordinate s3,s4;
    cout<<"\nCoordintes taken: (1,2,3) and (4,5,6)"<<endl<<endl;
    cout<< "Displaying the information:"<<endl<<endl;
    s3 = s1 + s2;
    s4 = s1-s2;
    cout<<"Addition: ( "<< s3.get_x() << " , "<< s3.get_y() << " , " << s3.get_z()<< " ) " << endl;
    cout<<"Subtraction: ( "<< s4.get_x() << " , "<< s4.get_y() << " , " << s4.get_z()<< " ) " << endl;
    return 0;
}
```
### 3. Write a program to compare two objects of a class that contains an integer value as its data member. Make overloading functions to overload equality(==), less than(<), greater than(>), not equal (!=), greater than or equal to (>=), and less than or equal to(<=) operators using member operator functions.
```c++
#include <iostream>
using namespace std;

class values
{
private:
    int a;

public:
    values(){};
    values(int x){ a= x; }
    int get_data() { return a; }

    bool operator == (const  values &b)
    {
       return(this->a== b.a);
    }
    bool operator<(const values &b)
    {
        return(this->a < b.a);
    }
    bool operator>(const values &b)
    {
        return(this->a > b.a);
    }
    bool operator!=(const values &b)
    {
        return(this->a!= b.a);
    }
    bool operator>=(const values &b)
    {
        return(this->a>= b.a);
    }
    bool operator<=(const values &b)
    {
        return(this->a <= b.a);
    }
};

int main()
{
    values d1{3}, d2{4};
  
    cout << std::boolalpha << (d1 == d2) << endl;
    cout << (d1 < d2) << endl;
    cout << (d1 > d2) << endl;  
    cout << (d1 != d2) << endl; 
    cout << (d1 >= d2) << endl;
    cout << (d1 <= d2) << endl;
    return 0;
}
```

### 4. Write a class Date that overloads prefix and postfix operators to increase the Date object by one day, while causing appropriate increments to the month and year (use the appropriate condition for leap year). The prefix and postfix operators in the Date class should behave exactly like the built-in increment operators.
```c++

#include <iostream>

int day_month_in_year[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date
{
    int year;
    int month;
    int day;

    bool isLeapYear()
    {
        if (year % 4 == 0 && !(year % 100 == 0) && year % 400 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                    return true;
            }
            else
                return true;
        }
        return false;
    }

public:
    Date(int month, int day, int year)
    {

        this->year = year;
        this->month = month;
        this->day = day;
    }

    void printDate()
    {

        std::cout << month << "/" << day << "/" << year << "\n";
    }

    /*Prefix*/
    Date operator++()
    {
        int total_days_in_month = day_month_in_year[month - 1];

        if (isLeapYear() && month == 2)
        {
            if (this->day == 29)
            {
                month++;
                this->day = 1;
            }
            else
            {
                this->day++;
            };

            return *this;
        }

        if (this->day + 1 > total_days_in_month)
        {
            this->day = 1;
            month++;
        }
        else
        {
            this->day++;
        }

        if (month > 12)
        {
            month = 1;
            year++;
        }

        return *this;
    }
    /*Post fix*/
    Date operator++(int)
    {
        Date return_date = *this;

        int total_days_in_month = day_month_in_year[month - 1];

        if (isLeapYear() && day == 28 && month == 2)
        {
            this->day++;
            return return_date;
        }

        if (this->day + 1 > total_days_in_month)
        {
            this->day = 1;
            month++;
        }
        else
        {
            this->day++;
        }

        if (month > 12)
        {
            month = 1;
            year++;
        }
        return return_date;
    }
};

int main(int argc, char const *argv[])
{
    Date d1(2, 27, 2000);

    d1.printDate();

    ++d1;

    d1.printDate();

    ++d1;

    d1.printDate();

    d1++;

    d1.printDate();

    d1++;

    d1.printDate();

    return 0;
}
```