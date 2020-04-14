#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

void print(vector<int>& v) {
    copy(begin(v), end(v), ostream_iterator<int>{cout, " "}); cout << endl ;
}

void go(vector<int> &v) {
    unordered_map<int, int> first_oc ;
    vector<int> pref ; int answer = 0 ;
    pref.emplace_back(0) ;

    replace(begin(v), end(v), 0, -1) ;
    for(const int x : v) {
        pref.emplace_back(pref.back() + x) ;
    }
    for(int i = 0; i < pref.size(); i++) {
        int x = pref[i] ;
        if (first_oc.find(x) != first_oc.end()) answer = max(answer, i+1 - first_oc[x]) ;
        first_oc[x] = i+1 ;
    }
    deb(answer) ;
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> v {0, 1} ;
    print(v) ;
    go(v) ;

    return 0;
}
