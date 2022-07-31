//  from meter/cm to feet/inches

#include <iostream>

class MeterCM
{

    private:
    float meter ;
    float cm;

    public:
    MeterCM( float m =0 , float c =0 ) { meter = m ; cm = c ; }
    float get_meter() { return meter; }
    float get_cm() { return cm; }


};

class FeetInch
{

    private:
    float feet ; 
    float inch;

    public:
    FeetInch( float m =0 , float s =0 ) { feet = m ; inch = s ; }

    FeetInch operator= ( MeterCM  c );
    void display() { std::cout<< "In feet/inch " << feet << " feets and  " << inch << " inches." ; }

};

FeetInch FeetInch::operator= ( MeterCM  c )
{
     float temp_total_meter = c.get_meter() + c.get_cm() *0.01 ;
    float temp_total_feet =  (temp_total_meter * 3.28084 ); 

    feet = static_cast<int> (temp_total_feet) ;
    inch = (temp_total_feet- feet) * 12  ; 
    return FeetInch( feet, inch );
}

int main()
{
    float meter, cm ;
    std::cout<< "Enter data for meter and cm seperated by space: "; 
    std::cin>> meter >> cm ;

    MeterCM mc( meter, cm );
    FeetInch fi ;

    fi  = mc;
    fi. display() ;

    return 0;
}