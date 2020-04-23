#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}
const int INF = 1e9+7 ;

int go(vector<int> &coins, int ammount) {
    vector<int> dp(ammount, INF) ;
    int n = coins.size() ;
    dp[0] = 0 ;
    for (int i = 1; i <= ammount; i++) {
        for(const int coin : coins ) {
            if (i >= coin) {
                int sub_total = dp[i - coin] ;
                dp[i] = min(dp[i], sub_total + 1) ;
            }
        }
    }
    return dp[ammount] ;
}




int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> coins {1,3,4} ;
    int ammount = 6;
    deb(ammount) ;

    clock_t t1 = clock() ;
    cout << go(coins, ammount) << endl ;
    cout << 1000.0* (clock() - t1 / CLOCKS_PER_SEC) << " ms" << endl ;

   
    return 0;
}
