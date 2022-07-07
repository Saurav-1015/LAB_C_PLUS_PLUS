/*
qn2.cpp

Write a program that has a class with a dynamically allocated character array as its data member.
One object should contain "Engineers are" and another should contain " Creatures of logic".
Member function join() should concatenate two strings by passing two objects as arguments.
Display the concatenated string through a member function. Use constructors to
allocate and initialize the data member. Also, write a destructor to free the allocated memory for
the character array. Make your own function for the concatenation of two strings.
*/

#include<iostream>
#include <string>

class Array
{
private:
    char *array;
public:
        Array(char a[], int n)
        {
            array =new char[n];
            for (int i=0; i<n ; i++)
            {
                *(array+i)= a[i];
                  std::cout<<*(array+i);
            }
        }
        ~Array()
        {
            delete [] array;
            std::cout<< "\ndestructor called"<<std::endl;
        }

        void concatenate()
        {
            int concat[33];
            for (int i=0; i< 13; i++)
            {
                concat[i] = array[i];
            }
            for (int i=13; i< 33; i++)
            {
                concat[i] = array[i];
            }

            // displaying
            for (int i=0 ; i<33; i++)
            {
                std::cout<< concat[i];
            }
        }
};

int main()
{
    char a[]={"Engineers are "};
    char b[]= {" Creatures of logic"};
    Array a1 {a, 14};
    Array a2 {b, 19};


    return 0;
}
