#include<iostream>
#include<bits/stdc++.h>

using namespace std ;


vector<int> v = {1,88,-8,44,78,-78,10,5,6} ;


void mergge(vector<int> &v, vector<int> &v2) {
    vector<int> v3(v.size()+ v2.size()) ;
    
    merge(begin(v), end(v), begin(v2), end(v2), begin(v3)) ;
}

vector<int> splitarray(vector<int> &v, int lo, int hi) {
     sort(begin(v), end(v)) ;
     return v ;
}


void mergesort(vector<int> &v) {
    int size = v.size() ;

    int lo = 0, hi = size ;
    int mid ;
    vector<int> f(v.size(), -1), f2(v.size(), -1) ;

        if (lo < hi)
    {
        mid = lo + (hi -lo) / 2 ;

         f = splitarray(v, lo, mid-1) ;
         f2 = splitarray(v, mid+1, hi) ;

    }

    mergge(f, f2) ;

    for (auto &&i : v)
        {
            std::cout << i << "  " ;
        }std::cout << std::endl ;

}


int main(int argc, char const *argv[])
{

    mergesort(v) ;
    
    return 0;
}
