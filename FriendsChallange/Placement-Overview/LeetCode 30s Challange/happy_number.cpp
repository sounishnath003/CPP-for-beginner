#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

int f(int n) {
    int sum = 0 ;
    while(n) {
        int digit = n % 10 ;
        sum += digit * digit ;
        n /= 10 ;
    }
    return sum ;
}

bool isHappy(int n) {
    unordered_set<int> s ;
    while(true) {
        if (n == 1) return true ;
        n = f(n) ;
        if (s.count(n) == 1) return false; 
        s.insert(n) ;
    }
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    int n = 36 ;
    cout << isHappy(n) ;
    return 0;
}
