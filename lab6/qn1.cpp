/*

qn1.cpp
Write a program that can convert the Distance (meter, centimeter) to meters measurement
in float and vice versa. Make a class distance with two data members, meter and centimeter.
You can add function members as per your requirement.

*/

#include <iostream>
#include <iomanip>
using namespace std;

class Distance
{
    float meter;
    float centimeter;

public:
    Distance() : meter(23), centimeter(47){};

    float get_meter() { return meter; }
    float get_centimeter() { return centimeter; }
    operator float()
    {
        float tempFloat;
        tempFloat = meter + centimeter / 100;
        return tempFloat;
    }

    Distance(float f)
    {
        int temp = static_cast<int>(f);
        meter = temp;
        centimeter = (f - temp) * 100;
    }
};
int main()
{
    Distance d;
    float f;
    f = d;
    float f1 = 34.57;
    Distance e;
    e = f1;
    cout << "\nValue:\nmeter = 23 \ncentimeter = 47\n"
         << endl;
    cout << "In Meter only: " << f;
    cout << "\nValue taken in meter only: " << f1;
    cout << "\nValue in (meter, centimeter): \n"
         << e.get_meter() << " " << e.get_centimeter();
    return 0;
}