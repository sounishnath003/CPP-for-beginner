#include<bits/stdc++.h>
#define fo(i, n) for(int i = n; i >= 0; i--)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}


void go(vector<int> &stones) {
    make_heap(stones.begin(), stones.end()) ;
    while(stones.size() > 1) {
        pop_heap(stones.begin(), stones.end()) ;
        int x = stones.back() ; stones.pop_back() ;
        pop_heap(stones.begin(), stones.end()) ;
        int y = stones.back() ; stones.pop_back() ;
        if (x != y) { stones.push_back(abs(x-y)); push_heap(stones.begin(), stones.end()) ; }
    }
    cout << stones[0] << endl  ;
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> stones { 2, 6, 4, 1, 8, 1 } ;

    go(stones) ;

    return 0;
}
