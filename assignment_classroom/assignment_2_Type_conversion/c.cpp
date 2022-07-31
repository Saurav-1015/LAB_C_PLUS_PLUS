// meter system to feet system 

#include <iostream>

class Meter
{
    private: 
    float meter;
    
    public: 
    Meter ( float m=0 ) { meter = m ;}
    float get_meter() { return meter ;}
};

class Feet
{
    private: 
    float  feet; 

    public:
    Feet ( float m=0 ) { feet = m ; }
    Feet operator= ( Meter m );
    void display();
};

Feet  Feet::operator= ( Meter m )
{
    feet = m.get_meter() * 3.28034 ; 
    return Feet(feet) ;
}

inline void Feet::display () { std::cout<< "In feet system: "<< feet; }

int main()
{
    float M;
    std::cout<< "Enter the value of length in meter: ";
    std::cin >> M;

    Meter m(M);
    Feet f;
    f = m ;
    f.display();
    
    return 0   ;
}