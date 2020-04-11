#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

vector<vector<string>> groupAnagrams(vector<string>& words) {
    unordered_map<string, vector<string>> m ;
    for(string word : words) {
        string word2 = word ;
        sort(begin(word2), end(word2)) ;
        m[word2].emplace_back(word) ;
    }
    vector<vector<string>> v ;
    for (auto pp : m) {
        v.push_back(pp.second) ;
    }
    return v ;
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<string> words = {"eat", "tea", "ate", "tan", "bat", "nat"} ;

    vector<vector<string>> v = groupAnagrams(words);
    for_each(begin(v), end(v), [&](const vector<string> &l) {
        for (auto s : l) {
            cout << s << " " ;
        }cout << endl ;
    }) ;

    return 0;
}
