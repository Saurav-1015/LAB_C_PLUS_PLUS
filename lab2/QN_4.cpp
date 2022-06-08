/*
QN_4.cpp

Write a function that passes two temperatures by reference and sets the larger of the two numbers to a
value entered by user by using return by reference.

*/

#include <iostream>

int &check_great(int &temp1, int &temp2){

    if(temp1> temp2)
    {
        return temp1;
    }else{
    return temp2;
    }
}


int main(){
    int temp1;
    int temp2;

    std::cout<<"Enter values of temperatures: "<<std::endl;
    std::cin>>temp1>>temp2;

    std::cout<<"Values before running function:\ntemp1= "<<temp1<<" and "<<"temp2= "<<temp2<<std::endl;
    std::cout<<"Enter the value for greater temperature:";
    std::cin>>check_great(temp1,temp2);

    std::cout<<"Values after running function:\ntemp1= "<<temp1<<" and "<<"temp2= "<<temp2<<std::endl;


    return 0;

}
