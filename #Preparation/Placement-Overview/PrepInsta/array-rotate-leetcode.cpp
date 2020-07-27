#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;
typedef long long ll ;

int main(int argc, char const *argv[]){
    IOS ;

    vector<int> nums{-1, -100, 3, 99};
    int k = 2 ;
    int n = nums.size() ;
    // reference space alocation of vector mems: hence in O(1) 
    // virtual clonning 
    auto swap = [&]() {
        vector<int> t ;
        copy(nums.begin() + k , nums.end(), back_inserter(t));
        copy(nums.begin(), nums.begin() + k , back_inserter(t));
        nums.clear();
        copy(t.begin(), t.end(), back_inserter(nums));
    };
    if(k <= n) { swap() ;}
    else{
        k = 2*(k - n);
        swap() ;
    }
    copy(nums.begin(), nums.end(), ostream_iterator<int> { cout, " " }) ;

    return 0;
}
