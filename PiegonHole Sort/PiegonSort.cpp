#include<iostream>
#include<bits/stdc++.h>
#define deb(x)  cout << #x << " " << x<< endl
using namespace std ;

bool compare(int a, int b) {
    return a>b ;
}

void pigeonHolesort(vector<int> &v) {

    int max = *max_element(begin(v), end(v)) ;
    int min = *max_element(begin(v), end(v), compare) ;

    deb(min);
    deb(max);

    int range = (max - min)+1 ;
    vector<int> holes(range) ;

    for (auto &&i : v){
        holes[i - min]= i  ;
    }

    for (auto &&i : holes)
    {
        std::cout << i << "  " ;
    }std::cout<<std::endl ;
    
}



int main(int argc, char const *argv[])
{
    vector<int> v{1,5,0,4,3,2} ;
    pigeonHolesort(v) ;
    return 0;
}
