#include<iostream>
using namespace std ;

class Prime
{
private:
    /* data */
    int i;
public:
    void isPrime(long n) {
        for (i = 2; i < n; i++)
        {
            if(n%i == 0) {
                break;
            }
        }
        if(i==n) {
            cout << "prime";
        }else {
            cout << "Not prime";
        }
    }
};

int main(int argc, char const *argv[])
{
    Prime obj ;
    obj.isPrime(4306466688538014151) ;
    return 0;
}
