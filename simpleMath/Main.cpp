#include <iostream>
using namespace std ;

class Main
{
private:
    
public:
    void sum(int a , int b) {
        int r = a + b;
        cout << r  << endl;
    }
    void sub(int a , int b) {
        int r = a - b;
        cout << r  << endl;
    }
    void mul(int a , int b) {
        int r = a * b;
        cout << r  << endl;
    }
    void div(int a , int b) {
        if (a>b)
        {
            cout << (a/b) << endl ;
        } else if (a < b) {
            cout << (b/a) << endl ;
        } else {
            cout  << 0 << endl ;
        }
    }
};

int main(int argc, char const *argv[])
{
    Main obj ;
    obj.sum(10,12) ;
    obj.sub(50 , 48) ;
    obj.mul(44, 10) ;
    obj.div(10, 50);
    return 0;
}

