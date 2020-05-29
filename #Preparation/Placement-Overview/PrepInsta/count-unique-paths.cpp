#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
const int MOD = 1e9+7 ;
const int N = 1e6+7 ;
const int inf = 2e9+7 ;
typedef long long ll ;

int countPaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n)) ;
	for(int row = 0; row < m ; row++){
		for (int col = 0; col < n ; col++) {
			if(row == 0 or col == 0) {
				dp[row][col] = 1 ;
			}
			else {
				dp[row][col] += dp[row-1][col] + dp[row][col-1];	
			}
		}
	}
	return dp[m-1][n-1] ;
}

int main(int argc, char const *argv[]){
    IOS ;

	cout << countPaths(7, 3) ;

    return 0;
}


