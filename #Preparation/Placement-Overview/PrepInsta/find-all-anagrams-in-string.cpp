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

vector<string> go(string &str, string &target) {
    int n = str.length(), tn = target.length() ;
    auto start_pointer = str.begin() ;
    auto second_pointer = str.begin() + tn ;
    vector<string> anagrams ;

    while(second_pointer < str.end()) {
        string word = string(start_pointer, second_pointer) ;
        string word2 = string(start_pointer, second_pointer) ;
        sort(word.begin(), word.end()) ;
        if (target == word) {
            anagrams.push_back(word2) ;
        }
        start_pointer = second_pointer ;
        second_pointer = second_pointer + tn ;
    }
    return anagrams ;
}


int main(int argc, char const *argv[]){
    IOS ;
   
    string str = "cbaebabacd" ;
    string target = "abc" ;

    vector<string> anagrams = go(str, target) ;
    cout << anagrams ;

}