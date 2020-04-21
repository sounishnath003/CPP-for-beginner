#include<bits/stdc++.h>
#define fo(i, n) for(int i = 1; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

int max_contiguos_subarray(vector<int> &nums) {
    stack<int> cached ;
    cached.push(nums[0]) ; int n = nums.size() ;
    int cnt = INT_MIN, t = 0 ;

    if(is_sorted(nums.begin(), nums.end(), less<int>{})) return nums.size() ;
    if(is_sorted(nums.begin(), nums.end(), greater<int>{})) return 0 ;

    fo(i, n) {
      if (cached.top() > nums[i] ) {
          t = cached.size() ;
          while(!cached.empty()) { cached.pop() ; } 
          cached.push(nums[i]) ;
      }
      if (cached.top() < nums[i]) {
          cached.push(nums[i]) ;
          int l = cached.size() ;
          cnt = max(cnt, l) ;
      }
    }
    return max(cnt, t);
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> nums{60, 45, 48, 52};
    cout << go(nums) ;
   
    return 0;
}
