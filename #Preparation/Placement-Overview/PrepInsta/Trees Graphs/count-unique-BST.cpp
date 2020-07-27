#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

void operator<<(ostream &os, vector<int> &v) {
    for(auto &&i : v){
        cout << i << " " ;
    }
    cout << endl ;
}

int uniqueBST(int n) {
    vector<int> dp(n + 1) ;
    dp[0] = 1, dp[1] = 1 ;
    for(int i = 2; i <= n ; i++){
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1] ;
        }
    }
    cout << dp ;
    return dp[n] ;
}

int main(int argc, char const *argv[]){
    IOS ;
   
    cout << uniqueBST(13) << endl ;

    return 0;
}
