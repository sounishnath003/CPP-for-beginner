#include<iostream>
#include<bits/stdc++.h>
#define deb(x) cout << #x << " " << x << endl 
using namespace std ;

vector<int> datas = {1,2,3,4,5,9} ;
// vector<int> datas = {1,4,9,16} ;

void sumOfPerfectSquare(vector<int> &datas) {
    int sum = 0 ;

    int integer_sqrt;
    float float_sqrt;
    
    // 4 => sqrt(4) = 2
    // 3 => sqrt(3) = 1.713

    for (auto &&elm : datas) {
        integer_sqrt = (int)sqrt(elm) ;
        float_sqrt = (float)sqrtf(elm) ;

        if (integer_sqrt == float_sqrt){
            cout << elm << "    " ;

            sum += elm ;
        }
    }
    cout << endl ;
    cout << "SUM: " << sum << endl ;
    
}


int main(int argc, char const *argv[])
{
    sumOfPerfectSquare(datas) ;
    return 0;
}
