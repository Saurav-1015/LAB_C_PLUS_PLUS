/*
qn4.cpp

Create a polymorphic class Vehicle and create other derived classes bus, Car , and Bike from Vehicle .
Illustrate RTTI by the use of dynamic_cast and typeid operators in this program.

*/

#include <iostream>
#include <typeinfo>
using namespace std;

class Vehicle
{
    public:
       virtual void display() {cout<<"Vehicle";}

};

class Bus : public Vehicle
{
 public:
        void display() {cout<<"Bus";}

};

class Car : public Vehicle
{
     public:
        void display() {cout<<"Car";}
};

class Bike : public Vehicle
{
     public:
        void display() {cout<<"Bike";}
};

int main()
{
    Vehicle* v;
    Bus b;
    Bus * pb;
    v= &b;

    cout<<typeid(*v).name();
    pb = dynamic_cast<Bus *> (v);
    
    if ( pb != NULL) 
    {
        cout<<"\ndowncast successfully"<<endl;
    }else{
        cout<<"fail to downcast"<< endl;
    }


    return 0;
}