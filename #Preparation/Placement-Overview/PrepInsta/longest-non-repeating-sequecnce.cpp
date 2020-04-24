#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

void go(string &str) {
    int n = str.length() ;
    int maxLength = INT_MIN ;
    string res = "" ;
    for (int i = 0; i <= n; i++) {
        char cur_ch = str[i] ;
        if (res.find_first_of(cur_ch) != string::npos) {
            res = res.substr(res.find_first_of(cur_ch)+1) ;
        }else{
            maxLength = res.length();
        }
        res += str[i] ;
    }
    deb(maxLength) ;
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    string str = "1234562237890";
    deb(str) ;
    go(str) ;
   
    return 0;
}
