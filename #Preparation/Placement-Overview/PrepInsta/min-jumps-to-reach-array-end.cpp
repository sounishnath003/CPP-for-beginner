#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

int go(vector<int> &nums) {
    int n = nums.size() ;
    vector<int> dp(n, INT_MAX) ;
    dp[0] = 0 ;
    if (nums[0] == 0) {return -1 ; }
    for (int i = 1; i < n ; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] + j >= i) {
                dp[i] = min(dp[i], j + dp[j]) ; break ;
            }
        }
    }
    return dp[n-1] ;
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> nums{1,3,6,1,0,9} ;
    cout << go(nums) ;
   
    return 0;
}
