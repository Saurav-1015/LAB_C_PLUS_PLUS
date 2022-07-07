/*
qn4.cpp

Write three derived classes inheriting functionality of base class person
(should have a member function that asks to enter name and age) and with added
unique features of student, and employee, and functionality to assign, change
and delete records of student and employee. And make one member function for
printing the address of the objects of classes (base and derived) using this pointer.
Create two objects of the base class and derived classes each and print
the addresses of individual objects. Using a calculator, calculate the address
space occupied by each object and verify this with address spaces printed by the program.
*/

#include <iostream>
using namespace std;

class person
{
    char name[20];
    int age;

public:
    void Enter()
    {
        cout << "\nEnter name: ";
        cin >> name;
        cout << "\nage: ";
        cin >> age;
    }
    void printAddress()
    {
        cout << "\nThe address of person object  is: " << this << endl;
    }
};

class student : public person
{

    int rollno;
    int grade;

public:
    void printAddress()
    {
        cout << "\nThe address of student object is:  " << this << endl;
    }
};

class employee : public person
{

    int employeeID;

public:
    void printAddress()
    {
        cout << "\nThe address of employee object is: " << this << endl;
    }
};

int main()
{
    person p1, p2;
    student s1, s2;
    employee e1, e2;

    p1.printAddress();
    p2.printAddress();
    s1.student::printAddress();
    s2.printAddress();
    e1.employee::printAddress();
    e2.printAddress();

    cout << "want to add more student (y/n)";
    char y_n;
    cin >> y_n;

    if (y_n == 'y' || y_n == 'n')
    {
    int student_record_no;
        cin >> student_record_no;
        cout << student_record_no << " no of student object added. You may use it";
        student s[student_record_no];
    }

    return 0;
}