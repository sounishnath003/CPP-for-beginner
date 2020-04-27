#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

int go(string text1, string text2) {
   int n = text1.length(),
       m = text2.length() ;
    vector<vector<int>> dp(n+1, vector<int>(m+1)) ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (text1[i] == text2[j] ) {
                dp[i+1][j+1] = 1 + dp[i][j] ;
            }else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]) ;
            }
        }
    }
    return dp[n][m] ;
}

int main(int argc, char const *argv[]){
    IOS ;
    
    string text1 = "abcde" , text2 = "cde" ;
    cout << text1 << " " << text2 << endl ;
    cout << go(text1, text2) ;

    return 0;
}
