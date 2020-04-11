#include<bits/stdc++.h>
using namespace std ;


void _max_product(vector<int>& v) {
    int _maxProduct  = 1;
    for(int i = 0 ; i < v.size(); i++) {
        if (v[i] > 0) {
            _maxProduct = _maxProduct * v [i] ;
        }
        if (v[i] == 0) {_maxProduct = 1 ;}
        else {
            int temp = _maxProduct ;
            _maxProduct = max(temp, 1) ;
        }
    }
    printf("max product: %d", _maxProduct) ;
}


int main(int argc, char const *argv[]){

    vector<int> v { -1, -3, -10, 60, 0 } ;

    _max_product(v) ;

    return 0;
}
