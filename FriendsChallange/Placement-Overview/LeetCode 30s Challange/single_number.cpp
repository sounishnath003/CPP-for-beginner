#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

void _singleNumber(vector<int> &v){
    int xoor = 0;
    for (int x : v) {
        xoor ^= x ;
    }
    cout << xoor << endl ;
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> v { 4, 1, 2, 1, 2 };
    _singleNumber(v) ;


    return 0;
}
