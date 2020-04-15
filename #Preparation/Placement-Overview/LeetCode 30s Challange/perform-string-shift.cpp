#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

string stringShift(string s, vector<vector<int>>& shift) {
    int total = 0 ;
    for(vector<int> dirAmt : shift) {
        if (dirAmt[0] == 0){
            total -= dirAmt[1] ;
        }else {
            total += dirAmt[1] ;
        }
    }
    int n = s.length();
    total %= n ;
    if (total < 0) {total+= n ;}
    return s.substr(n - total) + s.substr(0, n - total);
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    string s = "abc" ;
    vector<vector<int>> shift {{0, 1}, {1, 2}} ;

    cout << stringShift(s, shift) ;
    
   
    return 0;
}
