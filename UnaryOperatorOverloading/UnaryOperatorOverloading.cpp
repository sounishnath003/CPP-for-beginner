#include<iostream>
using namespace std ;

class UnaryOperatorOverloading
{
private:
    /* data */
    double feet;
    double inches ;
public:
    UnaryOperatorOverloading(){
        feet = 0 , inches = 0 ;
    }
    UnaryOperatorOverloading(double f, double in){
        feet = f;
        inches = in ;
    }

    void displayFeetInches() {
        cout << "Feet: " << feet << endl; 
        cout << "Inches: " << inches << endl; 
    }

    UnaryOperatorOverloading operator - () {
        feet = -feet;
        inches = -inches;
        return UnaryOperatorOverloading(feet, inches);
    }
    
};

int main(int argc, char const *argv[])
{
    UnaryOperatorOverloading u1(4,7);
    u1.displayFeetInches();
    -u1;
    u1.displayFeetInches();

    UnaryOperatorOverloading u2(-55,20);
    u2.displayFeetInches();
    -u2;
    u2.displayFeetInches() ;

    return 0;
}
