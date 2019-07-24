#include <iostream>
using namespace std ;

void swapp(int &a, int &b) {
    int temp = a;
    a = b ;
    b = temp ;
}

int main(int argc, char const *argv[])
{
    int a = 10 , b = 20 ;
    cout << "a: " << a << " b: " << b << endl ;
    swapp(a, b);
    cout << "a: " << a << " b: " << b << endl ;
    return 0;
}


