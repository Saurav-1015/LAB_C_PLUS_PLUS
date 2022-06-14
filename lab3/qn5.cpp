/*
qn5.cpp

Assume that an object represents an employee report that contains information like employee id, total bonus, total overtime in a particular
year. Use an array of objects to represent n employees' reports. Write a program that displays the report. Use setpara() member function to
set report attributes by passing the arguments and member function displayreport() to show the report according to the parameter
passed. Display the report in the following format.

An employee with ... ... ... has received Rs ... ... ...as a bonus
and
had worked ... ... ... hours as overtime in the year ... ... ...
*/

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
        std::cout << "An employee with " << employee_id << " has received Rs " << total_bonus << " and had worked " << total_overtime << " hours as overtime in the year " << year;
        std::cout << "\n";
    }
};

int main()
{
    int n;
    std::cout << "\nEnter the no of employee: ";
    std::cin >> n;
    EmployeeReport e[n];

    std::cout << "\nEnter the year: ";
    int y{};
    std::cin >> y;

    int employee;
    int bonus;
    int overtime;

    for (int i = 0; i < n; i++)
    {
        std::cout << "\nemployee id: ";
        std::cin >> employee;

        std::cout << "\nbonus: ";
        std::cin >> bonus;

        std::cout << "\novertime: ";
        std::cin >> overtime;

        e[i].setdata(employee, bonus, overtime, y);
    }

    for (int i = 0; i < n; i++)
    {
        e[i].displayreport();
    }

    return 0;
}
