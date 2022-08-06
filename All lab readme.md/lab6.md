## Lab 6

### 1. Write a program that can convert the Distance (meter, centimeter) to meters measurement in float and vice versa. Make a class distance with two data members, meter and centimeter. You can add function members as per your requirement.
```c++

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
```

### 2. Write two classes to store distances in meter-centimeter and feet-inch systems respectively. Write conversions functions so that the program can convert objects of both types.
```c++

#include <iostream>
using namespace std;

class feet_inch;
class meter_centimeter
{
    float meter;
    float centimeter;

public:
    meter_centimeter(float m = 0, float c = 0)
    {
        meter = m;
        centimeter = c;
    }
    float get_meter() { return meter; }
    float get_centimeter() { return centimeter; }
    void display()
    {
        cout << "\nmeter: " << meter;
        cout << "  centimeter: " << centimeter;
    }

    meter_centimeter(feet_inch fi);
};

class feet_inch
{
    float feet;
    float inches;

public:
    feet_inch(float f = 0, float i = 0)
    {
        feet = f;
        inches = i;
    }
    float get_feet() { return feet; }
    float get_inches() { return inches; }
    void display()
    {
        cout << "\nfeet: " << feet;
        cout << "  inches: " << inches;
    }

    feet_inch(meter_centimeter mc)
    {
        feet = mc.get_meter() * 3.218;
        inches = mc.get_centimeter() / 2.54;
        display();
    }
};

int main()
{
    feet_inch fi(10, 14), fi1;
    meter_centimeter mc(20, 25), mc1;
    
    cout<<"\nData taken for conversion:";
    fi.display();
    mc.display();
    mc1 = fi; // mc1 = meter_centimeter(fi);
    fi1 = mc; // fi1 = feet_inch(mc);
    return 0;
}

meter_centimeter::meter_centimeter(feet_inch fi)
{
    meter = fi.get_feet() / 3.218;
    centimeter = fi.get_inches() * 2.54;
    display();
}

```

### 3. Create a class called Musicians to contain three methods string(), wind(), and perc(). Each of these methods should initialize a string array to contain the following instruments

-  veena, guitar, sitar, sarod and mandolin under string()

-  flute, clarinet saxophone, nadhaswaram, and piccolo under wind()

-  tabla, mridangam, bangos, drums and tambour under perc()

It should also display the contents of the arrays that are initialized. Create a derived class called TypeIns to contain a method called get() and show(). The get() method must display a  menu as follows

Type of instruments to be displayed

a.  String instruments

b.  Wind instruments

c.  Percussion instruments

The show() method should display the relevant detail according to our choice. The base class variables must be accessible only to their derived classes.

```c++

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
```
### 4. Write three derived classes inheriting functionality of base class person (should have a member function that asks to enter name and age) and with added unique features of student, and employee, and functionality to assign, change and delete records of student and employee. And make one member function for printing the address of the objects of classes (base and derived) using this pointer. Create two objects of the base class and derived classes each and print the addresses of individual objects. Using a calculator, calculate the address space occupied by each object and verify this with address spaces printed by the program.

```c++
#include <stdio.h>
#include <iostream>
#include <string>

class Person
{

protected:
    std::string name;
    int age;

public:
    void askDetails()
    {
        std::cout << "Name : ";
        std::cin >> this->name;

        std::cout << "Age: ";
        std::cin >> age;
    }

    void showDetails()
    {
        std::cout << "Name : " << this->name;

        std::cout << "Age: " << age;
    }

    void showAddress()
    {
        printf("Address is %u\n", this);
    }
};

class Student : public Person
{
public:
    void assignRecord(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void changeRecord(std::string name = "", int age = 0)
    {
        if (name != "")
        {
            this->name = name;
        }
        if (age > 0)
        {
            this->age = age;
        }
    }

    void deleteRecord()
    {
        this->name = "";
        this->age = 0;
    }

    void showAddress()
    {
        printf("Address is %u\n", this);
    }
};
class Employee : public Person
{

public:
    void assignRecord(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void changeRecord(std::string name = "", int age = 0)
    {
        if (name != "")
        {
            this->name = name;
        }
        if (age > 0)
        {
            this->age = age;
        }
    }

    void deleteRecord()
    {
        this->name = "";
        this->age = 0;
    }

    void showAddress()
    {
        printf("Address is %u\n", this);
    }
};

int main()
{
    Person p1;
    Person p2;

    Student s;

    Employee e;

    p1.showAddress();
    p2.showAddress();
    s.showAddress();
    e.showAddress();

    std::cout << sizeof(p1) << std::endl;
    std::cout << sizeof(p2) << std::endl;
    std::cout << sizeof(s) << std::endl;
    std::cout << sizeof(e) << std::endl;
    return 0;
}
```
### 5. Write a base class that asks the user to enter a complex number and make a derived class that adds the complex number of its own with the base. Finally, make a third class that is a friend of derived and calculate the difference of the base complex number and its own complex number.

```c++

#include <iostream>
using namespace std;

class complexNumber
{
    int real;
    int imag;

public:
    //    complexNumber( const complexNumber &obj){ real = obj.real ; imag = obj.imag; }
    complexNumber(){};
    complexNumber(int r, int i)
    {
        real = r;
        imag = i;
    }
    int get_real() { return real; }
    int get_imag() { return imag; }

    void set_real(int a) { real = a; }
    void set_imag(int b) { imag = b; }

    void display() { cout << "\n"
                          << real << " + i " << imag << endl; }
};

class addComplexNumber : public complexNumber
{
    int real;
    int imag;

public:
    addComplexNumber(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    addComplexNumber operator+(complexNumber cn)
    {
        addComplexNumber temp;
        int a = real + cn.get_real();
        temp.real = a;
        // std::cout << temp.real;
        int b = imag + cn.get_imag();
        temp.imag = b;
        // std::cout << temp.imag;
        return temp;
        // return addComplexNumber(a,b);
    }
    
    void display() { cout << "\n"
                          << real << " + i " << imag << endl; }
};

class friendDifferenceComplex : public complexNumber
{
    int real;
    int imag;

public:
    friendDifferenceComplex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    void display() { cout << "\n"
                         << real << " + i " << imag << endl; }

     friendDifferenceComplex operator-(complexNumber cn)
    {
        friendDifferenceComplex temp;
        int a =  cn.get_real() - real;
        temp.real = a;
        // std::cout << temp.real;
        int b = cn.get_imag() - imag;
        temp.imag = b;
        // std::cout << temp.imag;
        return temp;
        // return addComplexNumber(a,b);
    }
};

int main()
{
    complexNumber c1(2, 5), c2;
    addComplexNumber a1(3, 7), a2;
    friendDifferenceComplex fd1( 5, 4), fd2  ;
    a1.display();
    c1.display();
    a2 = a1 + c1; // a2 =  a1.operator(c1);
    cout << "\nAfter sum: \n";
    a2.display();

    cout << "\n----------------------------------\n";
    c1.display();
    fd1.display();
    fd2 = fd1 - c1;
    cout<<"\nAfter difference: \n";
    fd2.display();
    return 0;
}

```