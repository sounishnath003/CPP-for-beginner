#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

void _moveZeros(vector<int> &nums) {
    int n = nums.size(), nxt = 0 ;
    for (int x : nums) {
        if (x != 0) {
            nums[nxt] = x ;
            nxt++ ;
        }
    }
    for(int i = nxt; nums[i] = 0, i < n; ++i) ;
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> nums {0,1,0,3,12} ;
    _moveZeros(nums) ;
    copy(begin(nums), end(nums), ostream_iterator<int> {cout, " "}) ;


    return 0;
}
