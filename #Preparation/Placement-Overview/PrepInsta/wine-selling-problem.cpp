#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

template<typename T>
void operator<<(ostream &os, vector<vector<T>> &mat) {
    for(const T i : mat) {
        for (const T j : i ){
            cout << j << " " ;
        }
        cout << endl ;
    }
}
template<typename T>
void operator<<(ostream &os, vector<T > &v){
    for (const T x : v) {
        cout << x << " " ;
    }
    cout << endl ;
}

int go(vector<int> &nums, int l, int r, int y) {
    int n = nums.size() ;
    if (l == r) {
        return y*nums[l] ;
    }
    int option1 = y * nums[l] + go(nums, l+1, r, y+1) ;
    int option2 = y * nums[r] + go(nums, l, r-1, y+1) ;
    return max(option1, option2) ;
}

int main(int argc, char const *argv[]){
    IOS ;
   
    vector<int> nums {2,4,6,2,5} ;
    cout << go (nums, 0, nums.size() - 1, 1) ;

    return 0;
}
