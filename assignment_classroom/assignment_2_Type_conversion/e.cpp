// liter to gallons


#include <iostream> 

class Liter
{

    private: 
    float l;

    public:
    Liter( float liter =0 ) { l = liter ; }
    float get_liter() { return l;}
};

class Galon
{

    private: 
    float g;

    public:
    Galon ( float galon =0 ) { g = galon  ; }
    float get_galon() { return g;}
    Galon operator= ( Liter l ) ;
    void display();
};


Galon Galon::operator= ( Liter l ) 
{
    g = l.get_liter() * 0.264172 ;
    
    return Galon( g ) ;
}

void Galon::display ()
{
    std::cout<< "In Gallons: "<< g ; 
}

int main() 
{
    float liter; 
    std::cout<< "enter the value in liter: " ; 
    std::cin >> liter;
    
    Liter li(liter); 
    Galon ga; 

    ga = li;
    ga.display() ;
    return 0 ;
}