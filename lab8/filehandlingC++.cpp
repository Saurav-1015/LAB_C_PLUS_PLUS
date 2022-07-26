#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream file;
	file.open("test.txt");
	char string_array[50] = "Yo man";
	file<< string_array;
	cout<<string_array << endl;
	file.close();
	cout<< "\nfile closed successfully";

	// reading operation from file
	ifstream rfile;
	rfile.open("test.txt");
	char  get_string[50];
	rfile.getline(get_string,50);
	cout<<"the content of the file is: "<< endl << get_string;
	rfile.close();

return 0;
}

