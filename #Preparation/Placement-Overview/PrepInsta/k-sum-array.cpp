#include<bits/stdc++.h>
#define fo(i, n) for(int i = 1; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

int go(vector<int> &nums, int k) {
    if (nums.size() == 0) return 0 ;
    unordered_map<int, int> c{{0, 1}} ;
    int cus = 0, ans = 0 ; 
    for(int x : nums) {
        cus += x ;
        ans = ans + c[cus - k] ;
        ++c[cus] ;
    }
    return ans ;
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> nums{3,6, 4, 5, 7, 2, 4, 5, 9, 8, 1};
    int k = 9 ;

    cout << go(nums, k) ;

    return 0;
}
