#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
const int mod = 1e9+7 ;
const int N = 1e6+7 ;

int no_ways(int d, int f, int target) {
	vector<int> dp(target+1) ;
	dp[0] = 1 ;
	for(int dice = 1; dice <= d; dice++){
		vector<int> new_dp(target+1);
		for(int cur_sum = 0; cur_sum <= target; ++cur_sum){
			for(int pipe = 1; pipe <= f; ++pipe){
				if(cur_sum + pipe <= target){
					int& temp = new_dp[cur_sum + pipe];
					temp += dp[cur_sum] ;
					if(temp>=mod){
						temp -= mod;
					}
				}
			}
		}
		dp = new_dp;
	}
	return dp[target];
}

int main(int argc, char const *argv[]){
	IOS ;
   
	int d, f, target ;
	scanf("%d %d %d", &d, &f, &target) ;
	cout << no_ways(d, f, target) << endl ;

	return 0;
}
