#include<iostream>
using namespace std ;

template <typename T> 
    T const& Max(T const& a, T const& b, T const& c) {
        if (a>b && a > c)
        {
            return a ;
        }
        else if (b > a && b > c)
        {
            return b ;
        } else {
            return c ;
        }
        
}

int main(int argc, char const *argv[])
{
    cout << Max(120,21, 885);
    return 0;
}
