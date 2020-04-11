#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}


void maxSubSum(vector<int>& nums) {
    int ans = INT_MIN, a = 0 ;
    for(int x : nums) {
        a += x ;
        ans = max(ans, a) ;
        a = max(a, 0) ;
    }
    cout << "ans: " << ans << endl ;
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> nums {-2, -3, 4, -1, -2, 1, 5, -3} ;
    maxSubSum(nums) ;
    
    return 0;
}
