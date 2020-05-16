#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

template<typename T>
void operator<<(ostream &os, vector<vector<T>> &mat) {
    for(const T i : mat) {
        for (const T j : i ){
            cout << j << " " ;
        }
        cout << endl ;
    }
}
template<typename T>
void operator<<(ostream &os, vector<T > &v){
    for (const T x : v) {
        cout << x << " " ;
    }
    cout << endl ;
}

int go(vector<int> &items, int k) {
    int  n = items.size() ;
    vector<vector<int>> dp(k+1, vector<int>(n+1)) ;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            int curmax = INT_MIN ;
            for (int m = 0; m < j; m++) {
                curmax = max(curmax, items[j] - items[m] + dp[i-1][m] );
            }
            dp[i][j] = max(dp[i][j-1], curmax) ;
        }
    }
    return dp[k][n-1] ;
}

int main(int argc, char const *argv[]){
    IOS ;
   
    vector<int> items {5,11,3,50,60,90} ;
    cout << go(items, 2) ;

    return 0;
}
