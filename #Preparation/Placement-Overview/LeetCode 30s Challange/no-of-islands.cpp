#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}


int numIslands(vector<vector<char>> &grid) {
    if (grid.empty() or grid[0].empty()) return -1 ;
    
    int H = grid.size(), W = grid[0].size(), answer = 0 ;
    vector<vector<bool>> visited(H, vector<bool>(W)) ;
    auto inside = [&] (int row, int col) {
        return (0 <= row and row < H) and (0 <= col and col < W) ;
    } ;
    vector<pair<int, int>> directions {{0, 1}, {0, -1}, {-1, 0}, {1, 0}} ;
    for(int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            if (!visited[row][col] and grid[row][col] == '1' ) {
                visited[row][col] =  true ;
                answer++ ;
                queue<pair<int, int>> q ;
                q.push({row, col}) ;
                while(!q.empty()) {
                    pair<int, int> p = q.front() ; q.pop() ;
                    for(const pair<int, int> &dir : directions) {
                        int new_row = p.first + dir.first , new_col = p.second + dir.second ;
                        if (inside(new_row, new_col) and !visited[new_row][new_col] and grid[new_row][new_col] == '1') {
                            q.push({new_row, new_col}) ;
                            visited[new_row][new_col] = true ;
                        }
                    }
                }
            }
        }
    }
    return answer ;
}



int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<vector<char>> grid {
                    {'1', '1', '0', '0', '0'},
                    {'0', '1', '0', '0', '1'},
                    {'1', '0', '0', '1', '1'},
                    {'0', '0', '0', '0', '0'},
                    {'1', '0', '1', '0', '1'} 
                   } ;
   
    cout << numIslands(grid) ;

    return 0;
}
