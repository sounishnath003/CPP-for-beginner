#include<bits/stdc++.h>
using namespace std ;

// string s = "BSD" ;
bool go(vector<vector<char>> &grid, string& s) { 
    int idx = 0 ;
    int W = grid[0].size();
    int H = grid.size() ;
    vector<vector<bool>> visited(H, vector<bool>(W)) ;
    vector<pair<int, int>> positions { {1,0}, {-1,0}, {0,1}, {0,-1} } ;
    queue<pair<int, int>> q;
    auto inside = [&](const int row, const int col) { 
        return (0 <= row && row < H) && (0 <= col && col < W) ;
    };
    for(int row = 0; row < H; ++row){
        for(int col = 0; col < W; ++col) {
            if(grid[row][col] == s[idx]) {
                idx++ ;
                visited[row][col] = true ;
                queue<pair<int, int>> cache ;
                cache.push({row, col});
                while(!cache.empty()) {
                    pair<int, int> curpos = cache.front() ; cache.pop() ;
                    for(auto &&pos : positions) {
                        int _nrow = curpos.first + pos.first, _ncol = curpos.second + pos.second ;
                        if(inside(_nrow, _ncol) && !visited[_nrow][_ncol]) {
                            visited[_nrow][_ncol] = true ;
                            cache.push({_nrow, _ncol}) ;
                            if(grid[_nrow][_ncol] == s[idx]) { idx++ ;}
                        }
                    }
                }
            }
        }
    }
    return idx == (int) s.length() ? true : false ;
}


int main(int argc, char const *argv[]){
   
    vector<vector<char>> grid {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string s ; cin >>s ;
    cout << s << endl ;
    cout << "found : " << go(grid, s) << endl ;

    return 0;
}
