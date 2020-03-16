#include<iostream>
#include<bits/stdc++.h>
#define deb(x) cout << #x << " " << x << endl 

using namespace std ;

vector<int> vec = {2,4,6,12,10} ;

string findType(vector<int> &vec) {
    int odd = 0, even = 0 ;

    for (auto &&elm : vec) {
        if (elm %2 == 0) {
            even ++ ;
        }else {
            odd ++ ;
        }
    }

    deb(even);deb(odd) ;

    if (even == vec.size()){
        return "EVEN" ;
    }else if(odd == vec.size()) {
        return "ODD";
    }else {
        return "MIXED" ;
    }
    
}

int main(int argc, char const *argv[])
{
    cout << findType(vec) ;
    return 0;
}
