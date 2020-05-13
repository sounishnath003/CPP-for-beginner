#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

int go(int &n) {
    int x = log2(n) + 1 ;
    fo(i, x) { n = n xor (1 << i); }
    return n ;
}

int main(int argc, char const *argv[]){
    IOS ;
   
    int n = 1024 ;
    deb(n) ;
    cout << go(n) ;

    return 0;
}
