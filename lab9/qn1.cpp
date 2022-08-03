/*
Create a function called sum() that returns the sum of the elements of an array. 
Make this function into a template so it will work with any numerical type. 
Write a program that applies this function to data of various types.

*/

#include <iostream>

template <class T>
T sum() 
{
    T temp_sum =0 ;
    T arr[10] ={ 1,2,3,4,5,6,7,8,9,10 } ;
    for ( size_t i = 0 ; i< 10 ; i++ )
    {
        temp_sum += arr[i] ;
    }

    return temp_sum; 
}

int main()
{

    std::cout<< "The sum of all the element of array is: "<< sum<int>() << std:: endl;

    return 0;
}