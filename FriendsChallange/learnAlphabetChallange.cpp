#include<iostream>
#include<bits/stdc++.h>
#define deb(x) {cout << #x << " " << x << endl ;}

using namespace std ;

void _takeDecission(bool& _weightagesMatched, bool& _isConsecutive){
    if (_weightagesMatched and _isConsecutive){std::cout << "possible..." << std::endl;}
    else{std::cout << "impossible..." << std::endl;}
}

void _leanLetters(vector<string>& v) {
    sort(v.begin(), v.end()) ;
    vector<int> weightages; bool _weightagesMatched = false ;
    bool _isConsecutive = false ;
    for(int i = 0; i< v.size(); i++) {
        int sum = 0;
        for(int j = 0; j < v[i].size(); j++) {
            sum += (int)v[i][j] - '0' ;
        }
        weightages.push_back(sum) ;
    }
    for(int i = 1; i< weightages.size(); i++) {
        if (weightages[i] - weightages[i-1] == 9) {
            _weightagesMatched = true ;
            for (int i = 0; i < v.size(); i++){
                for (int j = 1; j < v[i].size(); j++){
                    if (v[i][j] - v[i][j - 1] == 1){
                        _isConsecutive = true;
                    }else{_isConsecutive = false;break;
                    }
                }
            }
        }else {_weightagesMatched = false;}
    }
    _takeDecission(_weightagesMatched, _isConsecutive);
}

int main(int argc, char const *argv[]){
    
    vector<string> v{ "def", "abc", "ghi" } ;
    _leanLetters(v);
    return 0;
}
