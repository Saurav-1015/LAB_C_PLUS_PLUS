//  from pound/ounce to kg/gm

#include <iostream>

class PoundOunce
{

    private:
    float pound ;
    float ounce;

    public:
    PoundOunce( float p = 0 , float o = 0 ) { pound = p ; ounce = o ; }
    float get_pound() { return pound; }
    float get_ounce() { return ounce; }


};

class KgGm
{

    private:
    float kg ; 
    float gm;

    public:
    KgGm( float k =0 , float g =0 ) { kg = k ; gm = g ; }

    KgGm operator= ( PoundOunce  c );
    void display() { std::cout<< "In kg/gm " << kg << " kg and  " << gm << " gm " ; }

};

KgGm KgGm::operator= ( PoundOunce  c )
{
    float temp_total_pound = c.get_pound() + c.get_ounce() /16;
    float temp_total_kg =  (temp_total_pound * 0.453592 ); 

    kg = static_cast<int> (temp_total_kg) ;
    gm = (temp_total_kg - kg) * 1000  ; 
    return ( kg, gm );
}

int main()
{
    float pnd, oun ;
    std::cout<< "Enter data for pound and ounce seperated by space: "; 
    std::cin>> pnd >> oun ;

    PoundOunce c( pnd, oun );
    KgGm k1 ;

    k1  = c ;
    k1. display() ;

    return 0;
}