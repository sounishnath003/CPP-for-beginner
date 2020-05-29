#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

bool go(vector<vector<char>> &grid, string &target) {
    int H = grid.size() ;
    int W = grid[0].size() ;
    vector<vector<bool>> visited(H, vector<bool>(W)) ;
    auto inside = [&](int row, int col) {
        return (0 <= row and row < H) and (0 <= col and col < W);
    };
    string res = "";
    vector<pair<int, int>> directions {{1,0},{-1,0},{0,1},{0,-1}} ;
    for (int row = 0; row < H; row++){
        for(int col = 0; col < W; col++){
            if(!visited[row][col]){
                visited[row][col] = true ;
                queue<pair<int, int>> q ;
                q.push({row, col}) ;
                while(!q.empty()) {
                    pair<int, int> node = q.front() ; 
                    q.pop() ;
                    if(target.find(grid[node.first][node.second] )!=string::npos){res+= grid[node.first][node.second];}
                    for (const pair<int, int> &direction : directions){
                        int new_row = node.first + direction.first, new_col = node.second + direction.second ;
                        if (inside(new_row, new_col) and  !visited[new_row][new_col]){
                            visited[new_row][new_col] = true ;
                            q.push({new_row, new_col}) ;
                        }
                    }
                }
            }
        }
    }
    sort(target.begin(), target.end()) ;
    sort(res.begin(), res.end()) ;
    res.resize(distance(res.begin(), unique(res.begin(), res.end()))) ;
    target.resize(distance(target.begin(), unique(target.begin(), target.end()))) ;
    return res == target ;
}



int main(int argc, char const *argv[]){
    IOS ;
   

   vector<vector<char>> grid = {
       {'a', 'b', 'c', 'd'},
       {'e', 'f', 'g', 'r'},
       {'i','j','d','e'},
       {'k', 'l', 'o', 'c'}
   };

   string target = "eagol" ;
   cout << go(grid, target) << endl ;
    cout << target << endl ;

    return 0;
}
