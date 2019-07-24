#include<iostream>
using namespace std ;

class Main
{
private:
    int rate = 8.9 ;
public:
    int interest(int ammount, double time) {
        return (ammount * rate * time)/100 ;
    }
};


int main(int argc, char const *argv[])
{   
    Main obj ;
    int r = obj.interest(20000, 2) ;
    cout << r << endl ;    
    
    return 0;
}
