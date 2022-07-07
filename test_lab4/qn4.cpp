/*
qn4.cpp

Assume that one constructor initializes data member say num_vehicle, hour, and rate.
There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. Use two objects
and show a bit-by-bit copy of one object to another (make your own copy constructor).
*/

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