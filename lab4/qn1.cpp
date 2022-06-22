/*
qn1.cpp

Write a program that has a class to represent time.
The class should have constructors to initialize data members hour, minute,
and second to 0 and to initialize them to values passed as arguments.
The class should have a member function to add time objects and return the result as a time object.
There should be functions to display time in 12-hour and 24-hour format.
*/

#include <iostream>
#include <string>

class Time
{
public:
    int hour;
    int minute;
    int second;

public:
    Time();
    Time(int h, int m, int s);
    void add_time_object( Time t1, Time t2 ,Time &temp);
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
    int hour = t.hour, minute = t.minute, second = t.second;
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
    int hour = t.hour, minute = t.minute, second = t.second;
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
