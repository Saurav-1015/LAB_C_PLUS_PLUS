/* 
Write a program that stores the information about students (name, student id, department and address)
in a structure and then transfers the information to a file in your directory. Finally retrieves the 
information from your file and print it in the proper format on your output screen.
*/

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