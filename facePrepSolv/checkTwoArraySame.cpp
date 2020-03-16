#include<iostream>
#include<bits/stdc++.h>
#define deb(x) cout << #x << " " << x << endl

using namespace std ;

vector<int> v1 = {1,2,3,4,56,10};
vector<int> v2 = {1,2,10,3,4,56};

bool checkIfEqual(vector<int> &v1, vector<int> &v2) {

    // sorting elems of those for corner casing
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // if equal return 1, n-o-t 0
    if (v1 == v2) {
        return true ;
    }else {
        return false ;
    }
}


int main(int argc, char const *argv[]){

    cout << checkIfEqual(v1, v2) ;
    return 0;
}
