// conversion from Cartesian to Polar 

#include <iostream>
#include <cmath>


class Cartesian
{
    private:
    float x, y ;

    public:
    Cartesian  ( float a =0 , float b = 0 ) { x = a ; y = b; }
    
    float get_x() { return x; }
    float get_y() { return y; }
  
};

class Polar
{
    private:
    float r; 
    float theta;  
    
    public:
    float get_r() { return r; }
    float get_theta() { return theta; }
    Polar ( float r = 0  , float theta = 0  ) { this->r = r , this->theta = theta ; }
    Polar operator= ( Cartesian c );
    
   void display() { std::cout<< "In Polar:\n r= " << r << ", theta = " << theta << std:: endl; }
};



Polar Polar::operator= ( Cartesian c )
{
    
    r = sqrt( c.get_x() * c.get_x()  + c.get_y() * c.get_y() ) ;
    theta = atan( (float)(c.get_y())/c.get_x() ) * 180/M_PI ;

    return Polar(r, theta );
       
}

int main()
{
    float x, y;
    std::cout<< "enter the coordinates in cartesian ( i.e. x and y ) seperated by space\n";
    std::cin>> x >> y;
    Polar p;
    Cartesian c(x,y) ;

    p = c;
    p.display() ;


return 0;
}