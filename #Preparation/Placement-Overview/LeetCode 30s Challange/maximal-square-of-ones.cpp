#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

int go(vector<vector<int>> &matrix) {
    int H = matrix.size() ;
    int W = matrix[0].size() ;
    if (H == 0 or W == 0 ) {
        return 0 ;
    }
    int answer = INT_MIN ;
    vector<vector<int>> dp(H, vector<int>(W)) ;
    for (int row = 0; row < H; ++row) {
        for (int col = 0; col < W; ++col) {
            if (matrix[row][col] == 1) {
                dp[row][col] = 1 ;
                if (row > 0 and col > 0) {
                    dp[row][col] += min({dp[row-1][col], dp[row][col - 1], dp[row-1][col-1]}) ;
                    answer = max(answer, dp[row][col]) ;
                }
            }
        }
    }
    return answer*answer ;
}




int main(int argc, char const *argv[]){
    IOS ;
   
    vector<vector<int>> matrix {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    }    ;

    cout << go(matrix) ;

    return 0;
}
