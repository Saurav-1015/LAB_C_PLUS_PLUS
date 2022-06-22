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
    Time add_time_object(int h, int m, int s);
};

Time::Time()
    : hour{0}, minute{0}, second{0}
{
}

Time::Time(int h, int m, int s)
    : hour{h}, minute{m}, second{s}
{
}

Time Time::add_time_object(int h, int m, int s)
{
    Time t1{h, m, s};
    return t1;
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

    int hour, minute, second;

    // asking input for time, hour and second
    std::cout << "\nEnter the details:";
    std::cout << "\nhour: ";
    std::cin >> hour;
    std::cout << "minute: ";
    std::cin >> minute;
    std::cout << "second: ";
    std::cin >> second;

    // calling function for creating object

    Time t2 = add_time_object(hour, minute, second); // default copy constructor will be called here as well

    display_in_12hr_format(t2);
    display_in_24hr_format(t2);

    return 0;
}
