#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

int go(vector<int> &nums, int &k) {
    int answer = 0 ;
    int prefixSum = 0 ;
    unordered_map<int, int> cache ;
    cache[prefixSum]++ ;
    for (const int x : nums) {
        prefixSum += x ;
        int curSum = prefixSum - k ;
        answer += cache[curSum] ;
        cache[prefixSum]++ ;
    }
    return answer ;
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> nums{1,1,1} ;
    int k = 2 ;
    cout << go(nums, k);
   
    return 0;
}
