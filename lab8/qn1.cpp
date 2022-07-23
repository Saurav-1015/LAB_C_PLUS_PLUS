/*
Write a program to demonstrate the use of different ios 
flags and functions to format the output. Create a program to generate
 the bill invoice of a department store by using different formatting.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
 
int main()
{

    cout<<"Enter the number of product bought: "<<endl;
    int MAX;
    cin>> MAX;
    cout<<"Enter product names , its quantity and unit price: "<< endl;
    
    string product_name[MAX];
    int quantity[MAX];
    int unit_price[MAX];
    for ( size_t i =0 ; i< MAX ; i ++)
    {
        cin>> product_name[i];
        cin>> quantity[i];
        cin>> unit_price[i];
    }
    cout<< "Fill up the details below:"<< endl <<endl;
    cout<<"+---------------+-------+-------------------+--------------+"<<endl;
    cout.setf(ios::left, ios::adjustfield);
    cout<<"|" <<setw(15) << "DESCRIPTION"<<setw(3)<< "|"<< setw(5)<<"QTY"<<setw(5) << "|"<<setw(15)<<"UNIT PRICE"<< setw(5)<<"|"<<setw(10)<<"AMOUNT"<< setw(6)<< "|"<<endl;
    cout<<"+---------------+-------+-------------------+--------------+"<<endl;

    for(size_t i =0 ; i < MAX ; i ++)
    {
    cout<<"|" <<setw(15) <<product_name[i] <<setw(3)<< "|"<< setw(5)<<quantity[i]<<setw(5) << "|"<<setw(15)<<unit_price[i]<< setw(5)<<"|"<<setw(10)<< (quantity[i] * unit_price[i]) << setw(6)<< "|"<<endl;
    }
    cout<<"+---------------+-------+-------------------+--------------+"<<endl;

return 0;
}