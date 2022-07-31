/*
New/delete operator
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Student
{
    string name;
    int age;

public:
    Student(string name = " ", int age = 0)
    {
        std::cout << "\nConstructor is called\n";
        this->name = name;
        this->age = age;
    }
    string get_name() { return name; }
    int get_age() { return age; }

    void *operator new(size_t size)
    {
        std::cout << "\nNew is called and size is: " << size;
        void *temp = malloc(size);
        return temp;
    }
    void operator delete(void *s)
    {
        free(s);
        cout << "\nMemory free done ";
    }
};

int main()
{

    Student *std;
    std = new Student("Anonyms", 100);

    cout << "Name is : " << (*std).get_name() << "\nAge is: " << (*std).get_age() << endl;
    delete (std);
    return 0;
}