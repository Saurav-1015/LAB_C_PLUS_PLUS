/* 
qn3.cpp

Create a class called Musicians to contain three methods string(), wind(), and perc(). 
Each of these methods should initialize a string array to contain the following instruments
-  veena, guitar, sitar, sarod and mandolin under string()
-  flute, clarinet saxophone, nadhaswaram, and piccolo under wind()
-  tabla, mridangam, bangos, drums and tambour under perc()

It should also display the contents of the arrays that are initialized. 
Create a derived class called TypeIns to contain a method called get() and show(). 
The get() method must display a  menu as follows

Type of instruments to be displayed
a.  String instruments
b.  Wind instruments
c.  Percussion instruments

The show() method should display the relevant detail according to our choice. 
The base class variables must be accessible only to their derived classes.

*/

#include <iostream>
#include <string>
using namespace std;

class Musicians 
{
    private:
    string stringinst[5];
    string windinst[5];
    string percussioninst[5];
    public:
    void stringfunc() {
        stringinst[0]="veena";
        stringinst[1]="guitar";
        stringinst[2]="sitar";
        stringinst[3]="sarod";
        stringinst[4]="mandolin";
        for (size_t i =0 ; i<5 ; i++)
        {
            cout<< stringinst[i]<<" ";
        }
    };

    void wind() {
        // flute, clarinet saxophone, nadhaswaram, and piccolo
        windinst[0]="flute";
        windinst[1]="clarinet";
        windinst[2]="saxophone";
        windinst[3]="nadhaswaram";
        windinst[4]="piccolo";
        for (size_t i =0 ; i<5 ; i++)
        {
            cout<< windinst[i]<<" ";
        }
    };
    void perc() {
       //  tabla, mridangam, bangos, drums and tambour under perc()
       percussioninst[0] = "table";
       percussioninst[1] = "mridangam";
       percussioninst[2] = "bangos";
       percussioninst[3] = "drums";
       percussioninst[4] = "tambour";

       for (size_t i =0 ; i<5 ; i++)
        {
            cout<< percussioninst[i]<<" ";
        }
    };

};

class TypeIns : public Musicians
{
    public:
    void get() {
        char choice;
        cout << "\nType of instruments to be displayed\na.  String instruments\nb.  Wind instruments\nc.  Percussion instruments\n"<<endl;
        cin >> choice;
        show(choice);
    }
    void show( char choice) {
        if (choice == 'a'){ 
          stringfunc();
        }else if(choice == 'b'){
            wind();
        }
        else{ perc();}
    }
};

int main()
{
    TypeIns ti;
    char choice;
    ti.get();
    return 0;
}