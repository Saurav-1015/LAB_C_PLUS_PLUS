/*
Write a program to create a user-defined manipulator that will format 
the output by setting the width, precision, and fill character at the 
same time by passing arguments.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Manip
{
    private: 
    int width, precision;
    char fill;
    
    public:
    Manip (int w, int p , char f ): width(w) , precision(p), fill(f) {}
    friend ostream& operator<<( ostream& ,Manip m );
};

  ostream& operator<<( ostream&os ,Manip m)
    {
        os.precision(m.precision);
        os << setw(m.width);
        os.fill(m.fill);
        return os;
    }

    Manip wpf(int w, int p, char f)
    {
        return Manip( w, p, f);
    }
int main()
{
    float x = 345.458;
    cout << wpf(9,4,'#')<< x;
return 0;
}