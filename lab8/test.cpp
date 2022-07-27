/*
Write a program for transaction processing that write and read object randomly to and from 
a random access file so that user can add, update, delete and display the account information 
(account-number, last-name, first-name, total-balance).
*/

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