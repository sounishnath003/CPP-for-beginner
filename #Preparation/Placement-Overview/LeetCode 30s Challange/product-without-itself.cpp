#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

vector<int> productExceptItself(vector<int> &nums ) {
    int n = nums.size() ;
    vector<int> pref_product; pref_product.push_back(1) ;
    for (const int x : nums ) {
        pref_product.push_back(pref_product.back() * x) ;
    }
    vector<int> suff_product(n+1); suff_product[n] = 1 ;
    for(int i = n-1; i >= 0; i--) {
        suff_product[i] = suff_product[i+1] * nums[i] ;
    }
    vector<int> res(n) ;
    for(int i = 0; i < n ;i++) {
        res[i] = pref_product[i] * suff_product[i+1] ;
    }
    return res ;
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> nums {1,2,3,4} ;
    vector<int> res = productExceptItself(nums) ;
    copy(res.begin(), res.end(), ostream_iterator<int> {cout , " "})     ;
   
    return 0;
}
