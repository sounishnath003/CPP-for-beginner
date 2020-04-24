#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

void go(int n , int m) {
    int answer = 0 ;
    for (int bit = 30 ; bit >= 0 ; bit--) {
        if ((n & (1 << bit)) != (m & (1 << bit))) {
            break ;
        }else {
            answer |= (n & (1 << bit))  ;
        }
    }
    cout << answer << endl ;
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    go(2, 3) ;
   
    return 0;
}
