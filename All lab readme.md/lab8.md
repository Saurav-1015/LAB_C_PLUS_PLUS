
### 1. Write a program to demonstrate the use of different ios flags and functions to format the output. Create a program to generate  the bill invoice of a department store by using different formatting.

```c++
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

    cout << "Enter the number of product bought: " << endl;
    int MAX;
    cin >> MAX;
    cout << "Enter product names , its quantity and unit price: " << endl;

    string product_name[MAX];
    int quantity[MAX];
    int unit_price[MAX];
    for (size_t i = 0; i < MAX; i++)
    {
        cin >> product_name[i];
        cin >> quantity[i];
        cin >> unit_price[i];
    }
    cout << "Fill up the details below:" << endl
         << endl;
    cout << "+---------------+-------+-------------------+--------------+" << endl;
    cout.setf(ios::left, ios::adjustfield);
    cout << "|" << setw(15) << "DESCRIPTION" << setw(3) << "|" << setw(5) << "QTY" << setw(5) << "|" << setw(15) << "UNIT PRICE" << setw(5) << "|" << setw(10) << "AMOUNT" << setw(6) << "|" << endl;
    cout << "+---------------+-------+-------------------+--------------+" << endl;

    int total_sum = 0;
    for (size_t i = 0; i < MAX; i++)
    {
        total_sum += (quantity[i] * unit_price[i]);
        cout << "|" << setw(15) << product_name[i] << setw(3) << "|" << setw(5) << quantity[i] << setw(5) << "|" << setw(15) << unit_price[i] << setw(5) << "|" << setw(10) << quantity[i] * unit_price[i] << setw(6) << "|" << endl;
    }
    cout << "+---------------+-------+-------------------+--------------+" << endl;
    cout << "|";
    // cout.width(43);

    cout.setf(ios::right, ios::adjustfield);
    cout<<setw(18)<<""<<"Total"<< setw(20)<< "";
    cout << "|";
    cout<< setw(4) <<"";
    cout.setf(ios::left, ios::adjustfield);
    cout<< setw(10)<< total_sum<< "|" << endl;
    // cout << setw(4) << "" << total_sum << setw(6);
    // cout << "|" << endl;
    cout << "+---------------+-------+-------------------+--------------+" << endl;

    return 0;
}
```

### 2. Write a program to create a user-defined manipulator that will format the output by setting the width, precision, and fill character at the  same time by passing arguments.
```c++
#include <iostream>
#include <iomanip>
using namespace std;

class Manip
{
    private: 
    int width, precision;
    char fill;
    
    public:
    Manip (int w, int p , char f ): width(w) , precision(p), fill(f) {}
    friend ostream& operator<<( ostream& ,Manip m );
};

  ostream& operator<<( ostream&os ,Manip m)
    {
        os.precision(m.precision);
        os << setw(m.width);
        os.fill(m.fill);
        return os;
    }

    Manip wpf(int w, int p, char f)
    {
        return Manip( w, p, f);
    }
int main()
{
    float x = 345.458;
    cout << wpf(9,4,'#')<< x;
return 0;
}
```

### 3. Write a program to overload stream operators to read a complex number and display the complex number in a + ib format.

```c++
#include <iostream>
// #include <iomanip>
using namespace std;

class Complex
{

    private: 
    int re;
    int imag;

    public:
    Complex( int r = 0, int i = 0) { re = r ; imag = i;}
    friend istream& operator>>( istream& is , Complex& c);
    friend ostream& operator<<( ostream& os , Complex& c);
    
};

istream& operator>>( istream& is , Complex& co)
{
    is>>co.re>> co.imag;
    return is;
}

ostream& operator<<( ostream& os , Complex& co)
{
    os << co.re<< " + i "<< co.imag;
    return os;
}

int main()
{
    Complex c;
    cout << "Enter the real and imaginary part for the complex number:" << endl;
    cin >> c;
    cout <<"The complex number is:"<< endl;
    cout << c;

return 0;
}
```
### 4. Write a program that stores the information about students (name, student id, department and address) in a structure and then transfers the information to a file in your directory. Finally retrieves the information from your file and print it in the proper format on your output screen.
```c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 100 ;
struct Student
{
    string name;
    int st_id;
    string depart;
    string addrs;
};

int main()
{
    Student s;
    // opening file and writing inside it
    ofstream openfile;
    openfile.open("test.txt");
    cout<< "Enter the data for a student: FORMAT(name, id, depart, address)" << endl;
    cin>>s.name >> s.st_id>> s.depart>> s.addrs;
    openfile<<s.name<<" "<<s.st_id<< " "<< s.depart<< " "<< s.addrs << endl;
    openfile.close();
    cout<< "File closed successfully" << endl;

    // extracting from file
    ifstream getfile;
    char temp_string[MAX];
    getfile.open("test.txt");
    getfile.getline(temp_string, MAX );
    cout<< "\nThe content of file is displayed below: "<< endl;
    cout<< temp_string << endl;

return 0;
}
```

### 5. Write a program for transaction processing that write and read object randomly to and from a random access file so that user can add, update, delete and display the account information (account-number, last-name, first-name, total-balance).
```c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{   
    int acc_no;
    char last_name[20];
    char first_name[20];
    int total_balance;
    char c;
    cout<<"for adding: a\ndisplaying: d\nappend: p"<< endl;
    cin>> c;

    if( c == 'a' )
    {
         
        ofstream open_file( "test.txt");
        cout<<"enter first name, last name and total balance seperated by spaces: \n";
        cin>>first_name>> last_name>> total_balance;
        open_file<<first_name << " "<< last_name<< " "<< total_balance<< "\n";

    }else if( c == 'd')
    {
        ifstream read_file( "test.txt");
        read_file>> first_name >> last_name >> total_balance;
        cout<<"Data of file is: "<< endl;
        
        cout<< "first name: "<< first_name <<endl;
        cout<< "last name: " << last_name  <<endl;
        cout<< "total balance: "<< total_balance  <<endl;

    }else if( c == 'p' )
    {
        ofstream open_file( "test.txt", ios::app);
        cout<<"enter first name, last name and total balance seperated by spaces: \n";
        cin>>first_name>> last_name>> total_balance;
        open_file<<first_name << " "<< last_name<< " "<< total_balance;

    }

return 0;
}
```
