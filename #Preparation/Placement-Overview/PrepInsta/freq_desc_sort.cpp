#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    // O(NlogN approch )
    vector<int> v{1, 2, 3, 5, 2, 9, 7, 3, 5}; // => 5 3 2 9 7 1
    unordered_map<int, int> cache ;
    vector<pair<int, int>> vpair ;

    for_each(begin(v), end(v), [&](const int &a) { return cache[a]++ ; }) ;
    copy(begin(cache), end(cache), back_inserter(vpair)) ;

    sort(begin(vpair), end(vpair), [&](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first > b.first and a.second > b.second ) {a.first; } else { b.second ; }
        if (a.second == b.second) return a.first > b.first ; 
    }) ;

    for_each(begin(vpair), end(vpair), [&](pair<int, int> &b) {
        cout << b.first << " ";
    }) ;

    return 0;
}
