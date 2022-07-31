// convert from kg to pound 

#include <iostream>


class Pound
{
    private:
    float pound;  
    
    public:
    Pound (float p =0) { pound = p ;}
    
    float get_pound() { return pound; }
    void operator= ( float kg );
};

void Pound::operator= ( float kg )
{
    pound = kg *2.20462 ;
    std::cout<<"In pound : "<< pound  << std::endl;
       
}

int main()
{
    float kg;
    Pound po;

    std::cout<<"enter the value in kg: "<< std::endl;
    std::cin >> kg;
    po = kg;


return 0;
}