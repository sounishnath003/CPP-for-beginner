#include<iostream>
#define fo(i,n) for(i=1; i<=n; i++)
using namespace std ;

template<typename... T>
void print(T... args) {
    ((cout << args << " "), ...);
}


class Factorial
{
private:
    double res= 1;
    int i = 1;
public:
    template<typename F>
    F getTheFactorial(F const& n) {

        int memo[] = {0};

        if(memo[n] != 0) {
            return memo[n];
        }

        fo(i,n) {
            res = res * i;
            memo[n] = res;
        }
        //return memo[n];
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Factorial obj;
    int f = 5;
    int r = obj.getTheFactorial(f) ;
    print("factorial of ",f, " = ", r);
    return 0;
}
