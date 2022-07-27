/*
Create a class Person and two derived classes Employee and Student, inherited from class Person.
Now create a class Manager which is derived from two base classes Employee and Student.
Show the use of the virtual base class.

*/
#include <iostream>
using namespace std;

class Person
{
    public:
        Person(int foo) {
            cout << foo << "\n";
        }
};

class Employee : virtual public Person
{
    public:
        Employee(int foo) : Person(foo){
            cout << foo << "\n";
        }

};


class Student : virtual public Person
{

public:
    Student(int foo): Person(foo) {cout << foo << "\n";}

};

class Manager : public Employee, Student
{
public:
    Manager(int foo, int bar, int baz) : Person(foo), Employee(bar), Student(baz) {
    cout << foo <<" "<< bar << endl;
    }

};


int main()
{
    Manager m(1, 2, 3);
    return 0;
}