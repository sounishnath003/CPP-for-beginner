#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

int countElemns(vector<int> &arr) {
    set<int> cache ;
    int cnt = 0 ;
    for_each(begin(arr), end(arr), [&](int x){cache.insert(x);});
    for_each(begin(arr), end(arr), [&](int x) {
        if(cache.count(x+1)) cnt++ ;
    });
    return cnt ;
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    // vector<int> arr {1,2,3} ;
    vector<int> arr {1,3,2,3,5,0} ;
    cout << countElemns(arr) << endl ;
   
    return 0;
}
