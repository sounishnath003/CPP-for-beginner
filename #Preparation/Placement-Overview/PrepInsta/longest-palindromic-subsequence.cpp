#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;


int lps(string &str) {
  int n = str.length() ;
  vector<vector<int>> dp(n, vector<int>(n)) ;
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
  }
  for(int len = 2; len <= n ; len++) {
    for(int i = 0; i <= n-len; i++) {
      int j = i + len - 1 ;
      if(str[i] == str[j]) {
        dp[i][j] = dp[i+1][j-1] + 2 ;
      }else {
        dp[i][j] = max(dp[i+1][j], dp[i][j-1]) ;
      }
    }
  }
  return dp[0][n-1] ;
}

int main(int argc, char const *argv[]){
    IOS ;

    string str ;
    cin >> str;
    cout << lps(str) ;

    return 0;
}
