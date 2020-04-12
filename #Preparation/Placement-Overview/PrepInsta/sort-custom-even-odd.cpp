#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

// sort even odd customely
void _sort_custom(vector<int> &v) {
    sort(v.begin(), v.end(), [&](const int &i, const int &j ) {
        if (i&1 and j&1) return i > j;
        if (!(i&1) and !(j&1)) return i < j ;
        if (i & 1) return (bool) i ;
        return false ;
    });
    copy(begin(v), end(v), ostream_iterator<int>{cout, " "});
}


void _sort(vector<int> &v) {
    vector<int> even, odd ;
    sort(v.begin(), v.end(), [&](const int& i, const int& j) {
        if (i&1 and j&1) return i > j;
        return i < j ;
    });

    copy_if(v.begin(), v.end(), back_inserter(odd), [&](const int &i) { return i & 1; });
    copy_if(v.begin(), v.end(), back_inserter(even), [&](const int &i) { return !(i & 1); });
    copy(even.begin(), even.end(), back_inserter(odd));

    copy(begin(odd), end(odd), ostream_iterator<int> {cout, " "}) ;
}



int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;


    vector<int> v {0, 4, 5, 3, 7, 2, 1};
    _sort_custom(v) ;
   
    return 0;
}
