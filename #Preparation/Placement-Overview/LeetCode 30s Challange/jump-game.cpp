#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i <= n; i++)
#define foo(i, k, n) for(int i = k; i <= n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;


int go(vector<int> &nums) {
    int n = nums.size() ;
    pair<int, int> interval {0,0} ;
    int jumps = 0 ;
    if (n <= 1) {
        return true ;
    }
    while (true) {
        jumps++ ;
        int can_reach = -1 ;
        foo(i, interval.first, interval.second) {
            can_reach = max(can_reach, i + nums[i]);
        }
        if (can_reach >= n - 1) {
            return true ;
        }
        interval = {interval.second + 1, can_reach} ;
        if (interval.first > interval.second ) {
            return false ;
        }
    }
    assert(false) ;
}

bool canJump(vector<int>& nums) {
    int n = nums.size() ;
    int can_reach = 0 ;
    fo(i, can_reach) {
        if (can_reach >= n - 1) {return true ;}
        can_reach = max(can_reach, nums[i] + i) ;
    }
    return false ;
}


int main(int argc, char const *argv[]){
    IOS ;
   
    vector<int> nums {3,2,1,1,4} ;
    cout << canJump(nums) ;

    return 0;
}
