#include<iostream>
using namespace std ;

class LeapYear
{
private:
    /* data */
public:
    void isLeapYear(int year) {
        if (year!= 0) {
            if (year %4 == 0) {
                if (year % 100 == 0) {
                 if(year % 400 == 0) {
                     cout << "Leap year " <<  year << endl ;
                    }
                    else {
                        cout << "Not leap Year " << year << endl ;
                    }
                } else {
                        cout << "Not leap Year " << year << endl ;
                    }
            }else {
                        cout << "Not leap Year " << year << endl ;
                    }
        }
    }
};


int main(int argc, char const *argv[])
{
    LeapYear obj ;
    obj.isLeapYear(2008) ;
    obj.isLeapYear(2000) ;
    obj.isLeapYear(2018) ;
    return 0;
}
