/*

Write a program with an abstract class Student and create derive classes Engineering, Medicine and Science
from base class Student. Create the objects of the derived classes and process them and access them using
an array of pointers of type base class Student.
*/

#include <iostream>
using namespace std;

class Student
{
public:
    virtual void display() =0;
};

class Engineering : public Student
{
public:
    void display() {cout<< "\nEngineering\n";}

};

class Medical : public Student
{
public:
    void display() {cout<< "medical\n";}

};

class Science : public Student
{
public:
    void display() {cout<< "science\n";}

};

int main()
{
    Engineering e;
    Medical m;
    Science s;

    Student *st[3];
    st[0] = & e;
    st[1] = & m;
    st[2] = & s;

    for (size_t i =0 ; i<3 ; i++)
    {
        st[i]->display();
    }
    return 0;
}

