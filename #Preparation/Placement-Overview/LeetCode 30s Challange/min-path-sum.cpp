#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}


int _go(vector<vector<int>> &grid ) {
    int answer = 0 ;
    int H = grid.size() , W = grid[0].size() ;
    if (grid.empty() or grid[0].empty() ) return 1 ;
    vector<vector<bool>> visited(H, vector<bool>(W)) ;
    auto inside = [&](const int row, const int col) {
        return (0 <= row and row < H) and (0 <= col and col < W) ;
    } ;
    vector<pair<int, int>> moves = { {1, 0}, {0, 1} } ;

    for(int row = 0 ; row < H ; row++) {
        for (int col = 0; col < W; col++) {
            if (!visited[row][col]) {
                visited[row][col] = true ;
                // answer += grid[row][col] ;
                printf("%d ", grid[row][col]);
                queue<pair<int, int>> q ;
                q.push({row, col}) ;
                while(!q.empty()) {
                    pair<int, int> p = q.front(); q.pop() ;
                    for(const pair<int, int> &move : moves) {
                        int new_row = p.first + move.first, new_col = p.second + move.second ;
                        if (inside(new_row, new_col) and !visited[new_row][new_col] ){
                            answer += grid[new_row][new_col];
                            visited[new_row][new_col] = true ;
                            q.push({new_row, new_col}) ;
                        }
                    }
                }
            }
        }
    }
    return answer ;
}

int go(vector<vector<int>> &grid) {
    const int INF = 1e9+5 ;
    int H = grid.size(), W = grid[0].size() ;
    vector<vector<int>> dp(H, vector<int>(W)) ;
    for (int row = 0; row < H; row++) {
        for (int col = 0 ; col < W; col ++) {
            if (row == 0 and col == 0) {
                dp[row][col] = grid[row][col] ;
            }
            else {
                dp[row][col] = grid[row][col] + min((row == 0)? INF : dp[row-1][col], (col == 0) ? INF : dp[row][col-1] ) ;
            }
        }
    }
    return dp[H-1][W-1] ;
}


    int main(int argc, char const *argv[]) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        vector<vector<int>> grid = {
            {1, 3, 5},
            {2, 1, 2},
            {4, 3, 1}};

        cout << go(grid);

        return 0;
    }
