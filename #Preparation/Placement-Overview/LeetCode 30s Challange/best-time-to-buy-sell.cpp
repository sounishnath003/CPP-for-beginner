#include<bits/stdc++.h>
#define fo(i, n) for(int i = 1; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

// iterative dp[][] solution
void maxProfit(vector<int>& prices) {
    int best_without_stock = 0, best_with_stock = INT_MIN;
    for(int x : prices) {
        best_with_stock = max(best_with_stock, best_without_stock - x) ;
        best_without_stock = max(best_without_stock, best_with_stock + x) ;
    }
    cout << "output: " << best_without_stock << endl ;
}

// single in-pass solution
void maxProfit2(vector<int>& prices) {
    int maxProfitt = 0 ;
    fo(i, prices.size()) {
        if (prices[i] > prices[i-1])
            maxProfitt += prices[i] - prices[i-1] ;
    }
    cout << "output: " << maxProfitt << endl ;
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> prices {7,1,5,3,6,4} ;

    maxProfit(prices) ;
    maxProfit2(prices) ;
   
    return 0;
}
