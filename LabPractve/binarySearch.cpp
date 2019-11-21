#include<iostream>
#include<bits/stdc++.h>

using namespace std ;


vector<int> v = {1,0,5,-88,4,-8,74,99,-2,10,55,994,987,-44} ;

int bsearch(vector<int> &v, int lo, int hi, int key) {

    sort(v.begin(), v.end()) ;
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (v[mid] == key) {
            return mid ;
            break ;
        }

        if (v[mid] > key) {
            return bsearch(v, lo, mid-1, key) ;
        }else {
            return bsearch(v, mid+1, hi, key) ;
        }
    }
}


int main(int argc, char const *argv[])
{
    std::cout << bsearch(v, 0, v.size()-1, -2) << std::endl ;

    return 0;
}
