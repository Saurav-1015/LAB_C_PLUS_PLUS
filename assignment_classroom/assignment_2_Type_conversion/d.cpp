// 24 hour clock time to 12 hour clock time 

#include <iostream>

class clock_24
{

    private:
    int hour;
    int min;

    public:
    clock_24( int h =0 , int m =0 ) { hour = h ; min = m ; }
    int get_hour() { return hour; }
    int get_min() { return min; }


};

class clock_12
{

    private:
    int hour ;
    int min; 

    public:
    clock_12( int m =0 , int s =0 ) { hour = m ; min = s ; }

    clock_12 operator= ( clock_24  c );
    void display() { std::cout<< "Time in 12 hr is  "<< hour << " : " << min ; }

};

clock_12 clock_12::operator= ( clock_24  c )
{

    // for minute
    if ( c.get_min() < 60 )
    {
        min = c.get_min() ; 
    }
    else if ( c.get_min() >= 60 )
    {
        min = c.get_min() - 60 ; 
        hour = 0;
        hour ++;

    }
    
    // for hour

    if ( c.get_hour() <= 24 )
    {
        hour = c.get_hour() ; 
    }
    else if ( c.get_hour() >= 24 )
    {
        hour = c.get_hour() - 24; 
    }

    return ( hour, min );
}

int main()
{
    int hr, mi;
    std::cout<< "Enter time in 24 hr clock time:\n"; 
    std::cin>> hr >> mi ;

    clock_24 c_24( hr, mi );
    clock_12 c_12;

    c_12  = c_24;
    c_12. display() ;

    return 0;
}