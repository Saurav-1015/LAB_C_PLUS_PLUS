/*
Write a program for transaction processing that write and read object randomly to and from 
a random access file so that user can add, update, delete and display the account information 
(account-number, last-name, first-name, total-balance).
*/

#include <iostream>
#include <fstream>
using namespace std;

class Transaction
{
    private:

    public:
    friend ostream& operator<< (ostream& os, Transaction t);
    friend istream& operator>> (istream& is, Transaction t);
};
    
    ostream& operator<< (ostream& os, Transaction t)
    {

    }

    istream& operator>> (istream& is, Transaction t)
    {

    }

int main()
{

return 0;
}