## Lab 4 
### 1.Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute, and second to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the result as a time object. There should be functions to display time in 12-hour and 24-hour format.
```c++

#include <iostream>
#include <string>

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time();
    Time(int h, int m, int s);
    void add_time_object( Time t1, Time t2 ,Time &temp);
    int get_hour() { return hour;}
    int get_minute() { return minute;}
    int get_second() { return second;}
};

Time::Time()
    : hour{0}, minute{0}, second{0}
{
}

Time::Time(int h, int m, int s)
    : hour{h}, minute{m}, second{s}
{
}

void Time::add_time_object( Time t1, Time t2, Time &temp )
{

    temp.hour= t1.hour + t2.hour;
    temp.minute = t1.minute + t2.minute;
    temp.second = t1.second + t2.second;

}

void display_in_12hr_format(Time t)
{
  int hour = t.get_hour(), minute = t.get_minute(), second = t.get_second();
    if (second >= 60)
    {
        minute = minute + second / 60;
        second = second - (second / 60) * 60;
    }

    if (minute >= 60)
    {
        hour = hour + minute / 60;
        minute = minute - (minute / 60) * 60;
    }

    if (hour >= 12)
    {
        hour = hour - 12 * (hour / 12);
    }

    std::cout << "\nTime in 12 hr format:\n"
              << hour << " : " << minute << " " << second;
}

void display_in_24hr_format(Time t)
{
    int hour = t.get_hour(), minute = t.get_minute(), second = t.get_second();
    if (second >= 60)
    {
        minute = minute + second / 60;
        second = second - (second / 60) * 60;
    }

    if (minute >= 60)
    {
        hour = hour + minute / 60;
        minute = minute - (minute / 60) * 60;
    }

    if (hour >=24)
    {
        hour = hour - 12 * (hour / 12);
    }

    std::cout << "\nTime in 24 hr format:\n"
              << hour << " : " << minute << " " << second;
}

int main()
{

    Time t1(14,25,12);
    Time t2 (6,12,11);
    std::cout<<"Time taken: \n\nhour: 14\nminute: 25\nsecond: 12\n\nAND\n\nhour: 6\nminute: 12\nsecond: 11\n";

    Time t3;
    Time t4;
    t3.add_time_object(t1,t2,t4);
    std::cout<<"\nAfter sum: ";
    display_in_12hr_format(t4);
    display_in_24hr_format(t4);

    return 0;
}

```
### 2.Write a program that has a class with a dynamically allocated character array as its data member. One object should contain "Engineers are" and another should contain " Creatures of logic". Member function join() should concatenate two strings by passing two objects as arguments. Display the concatenated string through a member function. Use constructors to allocate and initialize the data member. Also, write a destructor to free the allocated memory for the character array. Make your own function for the concatenation of two strings.
```c++

#include<iostream>
#include <string>

class Array
{
private:
    char *array;
public:
        Array(char a[], int n)
        {
            array =new char[n];
            for (int i=0; i<n ; i++)
            {
                *(array+i)= a[i];
                  std::cout<<*(array+i);
            }
        }
        ~Array()
        {
            delete [] array;
            std::cout<< "\ndestructor called"<<std::endl;
        }

        void concatenate()
        {
            int concat[33];
            for (int i=0; i< 13; i++)
            {
                concat[i] = array[i];
            }
            for (int i=13; i< 33; i++)
            {
                concat[i] = array[i];
            }

            // displaying
            for (int i=0 ; i<33; i++)
            {
                std::cout<< concat[i];
            }
        }
};

int main()
{
    char a[]={"Engineers are "};
    char b[]= {" Creatures of logic"};
    Array a1 {a, 14};
    Array a2 {b, 19};


    return 0;
}
```
### 3.Write a class that can store Department ID and Department Name with constructors to initialize its members. Write destructor member in the same class and display the message "Object n goes out of the scope". Your program should be made such that it should show the order of constructor and destructor invocation.
```c++

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
```
### 4.Assume that one constructor initializes data member say num_vehicle, hour, and rate. There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. Use two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).
```c++

#include <iostream>

class Vehicle
{
private:
    int num_vehicle;
    int hour;
    int rate;

public:
    Vehicle();
    Vehicle(Vehicle &v);
    void display_total_charge();
};

Vehicle::Vehicle()
: num_vehicle{15}, hour{12}, rate{100} {
}

Vehicle::Vehicle(Vehicle &v)
{
    num_vehicle = v.num_vehicle;
    hour = v.hour;
    rate = v.rate;
    std::cout<<"\nCopy constructor called";
}

void  Vehicle::display_total_charge()
{
    if ( num_vehicle>10 )
    {
        std::cout<<"\nTotal Charge: "<< (num_vehicle*hour*rate)-(num_vehicle*hour*rate*0.1);
    }else
    {
        std::cout<<"\nTotal Charge: "<< num_vehicle*hour*rate;
    }

}
int main()
{
    Vehicle v1;
    v1.display_total_charge();
    Vehicle v2 = v1;
}

```

### 5.Write a program that illustrates the following relationship and comment on them. 

i) const_object.non_const_mem_function

ii) const_object.const_mem_function

iii) non_const_object.non_const_mem_function

iv) non_const_object.const_mem_function

```c++

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

```
### 6. Create a class with a data member to hold a "serial number" for each object created from the class. That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept of static data members. Use static member function if it is useful in the program. Otherwise, make a separate program that demonstrates the use of static member function.

```c++


#include <iostream>


class count
{
private:
    static int serial_number;

public:
    count()
    {
        serial_number+= 1;
    }
    static int get_object_number()
    {
        return serial_number;
    }

};
int count::serial_number=0;
int main()
{
        count c1,c2,c3,c4;
        std::cout<<"The total no of object declared is: "<< count::get_object_number();

    return 0;
}

```