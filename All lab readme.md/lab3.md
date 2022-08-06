## Lab 3

### 1. Write a simple program that converts the temperature in Celsius scale to Fahrenheit scale and vice versa using the basic concept of class and object. Make separate classes for Celsius and Fahrenheit which will have the private members that hold the temperature value and make conversion functions in each class for conversion from one to another. For example, you need to have a function toFahrenheit() in class Celsius that converts to Fahrenheit scale and returns the value.
```c++

#include <iostream>

class Celcius
{
private:
    float celcius{};

public:
    float toFahrenheit()
    {
        return (9 * (celcius / 5) + 32);
    }

    void set_celcius(int cel)
    {
        celcius = cel;
    }
};

class Fahrenheit
{
private:
    float fahrenheit{};

public:
    float toCelcius()
    {
        return ((fahrenheit - 32) * 5 / 9);
    }

    void set_fahrenheit(int fah)
    {
        fahrenheit = fah;
    }
};

int main()
{
    Celcius c;
    Fahrenheit f;
    float cel{}, fah{};
    std::cout << "\nEnter the temperature in celcius: ";
    std::cin >> cel;
    c.set_celcius(cel);

    std::cout << "\nEnter the temperature in Fahrenheit: ";
    std::cin >> fah;
    f.set_fahrenheit(fah);

    std::cout << "\n-----------------Displaying the conversion:----------------\n";
    std::cout << "Equivalent of celcius " << cel << " to fahrenheit is: " << c.toFahrenheit() << "\n";
    std::cout << "Equivalent of fahrenheit " << fah << " to celcius is: " << f.toCelcius() << "\n";

    return 0;
}

```

### 2. Assume that you want to check whether the number is prime or not. Write a program that asks for numbers repeatedly. When it finishes checking a number the program asks if the user wants to do another calculation. The response can be 'y' or 'n'. Don't forget to use the object-oriented concept.

```c++
#include <iostream>
#include <string>

class Prime
{
private:
    // Data members;
    int prime{};

public:
    void set_prime(int p) { prime = p; }
    bool prime_check()
    {
        bool flag = true;
        int f = 0;
        if (prime != 1)
        {
            for (int i = 1; i <= prime; i++)
            {
                if (prime % i == 0)
                {
                    f++;
                }
            }
        }
        else
        {
            f = 2;
        }

        if (f == 2)
        {
            return flag;
        }
        else
        {
            flag = false;
            return flag;
        }
    }
};

int main()
{
    Prime p;
    int PRIME{};

    std::string str;
    do
    {
        std::cout << "Enter number to check for prime: ";
        std::cin >> PRIME;
        p.set_prime(PRIME);

        if (p.prime_check())
        {
            std::cout << "\nThe entered number is prime ";
        }
        else
        {
            std::cout << "\nThe entered number is not prime ";
        }

        std::cout << "\nWant to repeat (y/n): ";
        std::cin >> str;

    } while (str != "n");

    return 0;
}
```
### 3. Create a class called carpark that has int data member for car id, int data member for charge/hour, and float data member for the parked time. Make functions to set data members and show the charges and parked hours of the corresponding car id. Make functions for setting and showing the data members. Member function should be called from other functions.

```c++

#include <iostream>
class Carpark
{
private:
    // datamember
    int car_id{};
    int charge_per_hour{};
    float parked_time{};

public:
    // member functions
    void set_data_members(int car, int charge, float parked)
    {
        car_id = car;
        charge_per_hour = charge;
        parked_time = parked;

        display_info();
    }

    void display_info()
    {
        std::cout << "\n---------------For carid " << car_id << " ----------------\n";
        std::cout << "Parked hour: " << parked_time << "\n";
        std::cout << "Charge for parking: " << charge_per_hour * parked_time << "\n";
    }
};

int main()
{
    Carpark c;
    int CARID, CHARGE;
    float PARKED;
    std::cout << "Enter car id: ";
    std::cin >> CARID;
    std::cout << "Enter charge per hour: ";
    std::cin >> CHARGE;
    std::cout << "Enter parked time(hour): ";
    std::cin >> PARKED;
    c.set_data_members(CARID, CHARGE, PARKED);

    return 0;
}
```

### 4. Write a program with classes to represent a circle, rectangle, and triangle. Each class should have data members to represent the actual objects and member functions to read and display objects, find perimeter and area of the objects, and other useful functions. Use the classes to create objects in your program.

```c++

#include <iostream>
#include <cmath>

class Circle
{
private:
    float radius{};

public:
    void read(float rad) { radius = rad; }
    void display()
    {
        std::cout << "\n------------For Circle----------------\n";
        std::cout << "area: " << (3.14 * radius * radius);
        std::cout << "\nPerimeter: " << (2 * 3.14 * radius);
    }
};

class Rectangle
{
private:
    float length{};
    float breadth{};

public:
    void read(float l, float b)
    {
        length = l;
        breadth = b;
    }
    void display()
    {
        std::cout << "\n------------For Rectangle----------------\n";
        std::cout << "area: " << (length * breadth);
        std::cout << "\nPerimeter: " << (2 * (length + breadth));
    }
};

class Triangle
{
private:
    float a;
    float b;
    float c;

public:
    void read(float A, float B, float C)
    {
        a = A;
        b = B;
        c = C;
    }
    void display()
    {
        float s = (a + b + c) / 2;
        float AREA = sqrt(s * (s - a) * (s - b) * (s - c));
        std::cout << "\n------------For Triangle----------------\n";
        std::cout << "area: " << AREA;
        std::cout << "\nPerimeter: " << 2 * s;
    }
};

int main()
{
    Circle ci;
    Rectangle r;
    Triangle t;

    int rad;
    // for cicle
    std::cout << "\nFor Circle:\n";
    std::cout << "radius: ";
    std::cin >> rad;
    ci.read(rad);
    ci.display();

    // for rectangle
    float length{}, breadth{};
    std::cout << "\n\nFor Rectangle: \n";
    std::cout << "length: ";
    std::cin >> length;
    std::cout << "breadth: ";
    std::cin >> breadth;
    r.read(length, breadth);
    r.display();

    // for triangle
    float a{}, b{}, c{};
    std::cout << "\n\nFor triangle: \n";
    std::cout << "Enter three sides of triangle: ";
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    t.read(a, b, c);
    t.display();

    return 0;
}
```

### 5. Assume that an object represents an employee report that contains information like employee id, total bonus, total overtime in a particular year. Use an array of objects to represent n employees' reports. Write a program that displays the report. Use setpara() member function to set report attributes by passing the arguments and member function displayreport() to show the report according to the parameter passed. Display the report in the following format.

### An employee with ... ... ... has received Rs ... ... ...as a bonus

### and

### had worked ... ... ... hours as overtime in the year ... ... ...

```c++

#include <iostream>

class EmployeeReport
{
private:
    int employee_id{};
    int total_bonus{};
    int total_overtime{};
    int year{};

public:
    void setdata(int employee, int bonus, int overtime, int y)
    {
        employee_id = employee;
        total_bonus = bonus;
        total_overtime = overtime;
        year = y;
    }

    void displayreport()
    {
        std::cout << "An employee with employee id " << employee_id << " has received Rs " << total_bonus << " and had worked " << total_overtime << " hours as overtime in the year " << year;
        std::cout << "\n";
    }
};

int main()
{
    EmployeeReport e[3];

    std::cout << "\nEnter the year: ";
    int y{};
    std::cin >> y;

    int employee;
    int bonus;
    int overtime;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "\nemployee id: ";
        std::cin >> employee;

        std::cout << "\nbonus: ";
        std::cin >> bonus;

        std::cout << "\novertime: ";
        std::cin >> overtime;

        e[i].setdata(employee, bonus, overtime, y);
    }

    for (int i = 0; i < 3; i++)
    {
        e[i].displayreport();
    }

    return 0;
}

```