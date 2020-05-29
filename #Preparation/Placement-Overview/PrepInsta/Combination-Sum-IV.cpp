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

int combination(vector<int> &nums, int &target) {
	int n = nums.size() ; 
	vector<int> dp(target + 1) ;
	dp[0] = 1 ;
	for(int i = 0; i <= target; i++) {
		for(int j = 0; j < n ; j++){
			dp[i] = 1 + nums[j] + nums[i-j] ;
		}
	}
	return dp[target] ;
}


int main(int argc, char const *argv[]){
    IOS ;

	vector<int> nums {1,2,3} ;
	int target = 4;
	cout << combination(nums, target) ;

    return 0;
}


