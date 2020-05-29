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

int max_rod_cutting(vector<int> &prices, int rodlength) {
	vector<int> dp(rodlength + 1) ;
	for(int i = 1; i <= rodlength; i++){
		for(int j = 1; j <= i; j++) {
			dp[i] = max( dp[i], prices[j-1] + dp[i - j] );
		}
	}
	return dp[rodlength] ;
}

int main(int argc, char const *argv[]){
    IOS ;

	vector<int> lengths {1,2,3,4,5,6,7,8};
    vector<int> prices {1,5,25,9,10,17,17,20};
    cout << max_rod_cutting(prices, 4);
    

    return 0;
}


