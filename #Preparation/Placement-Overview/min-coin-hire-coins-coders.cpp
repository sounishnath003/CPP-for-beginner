#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

// min coins hire coders
void _go(vector<int> &coders, vector<int> &coins) {
    int coins_needed = INT_MAX ;
    unordered_set<int> comp ;
    for (int i = 0; i < coders.size(); i++) {
        if (coders[i] == 3) {
            coins_needed = min(coins_needed, coins[i]) ;
        }
        int target = 3 - coders[i] ;
        if (comp.find(target) != comp.end()) {
            auto itr = find(begin(coders), end(coders), target);
            int index = distance(coders.begin(), itr);
            int cur_sum = coins[i] + coins[index] ;
            coins_needed = min(coins_needed, cur_sum) ;
        }
        comp.insert(target) ;
    }
    deb(coins_needed) ;
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<int> coders {1,3,2,3,1} ;
    vector<int> coins {3,5,2,4,6} ;

    // vector<int> coders {3,1,2,3,1} ;
    // vector<int> coins {9,5,2,7,3} ;

    // vector<int> coders {3,1,2,3,1} ;
    // vector<int> coins {9,5,2,7,6} ;



   _go(coders, coins) ;
   
    return 0;
}
