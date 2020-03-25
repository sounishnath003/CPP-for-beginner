#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

void _midAvg(vector<int>& v) {
    int leftSum = 0, rightSum = 0 ;
    rightSum = accumulate(v.begin(), v.end(), rightSum) ;
    for(auto &&i : v) {
        rightSum -= i ;
        if (leftSum == rightSum){cout << i ; break ;}
        leftSum += i ;
    }
}   

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> v {1,7,5,8};

    _midAvg(v) ;

    return 0;
}
