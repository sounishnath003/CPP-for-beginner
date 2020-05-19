#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

bool is_safe(vector<vector<int>> &board, int i, int j, int n) {
  // check for the cols
  for (int row = 0; row < i ; row++) {
    if(board[row][j]){
      return false ;
    }
  }
  // check for the left diag
  int x = i, y = j ;
  while(x>=0 and y>=0) {
    if(board[x][y]){
      return false ;
    }
    x--, y-- ;
  }
  // check for right diag
  x = i, y = j ;
  while(x>=0 and y<n) {
    if(board[x][y]) {
      return false ;
    }
    x--, y++ ;
  }
  return true;
}

bool solveNQueen(std::vector<vector<int>> &board, int i,int n) {
  if(i == n) {
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        if(board[i][j]){
          cout << "Q ";
        }else{
          cout << "_ " ;
        }
      }
      cout << endl ;
    }
    cout << endl ;
    return false ;
  }
  for (size_t j = 0; j < n; j++) {
    if(is_safe(board, i, j, n)) {
      board[i][j] = 1 ;
      bool is_nextQ_place = solveNQueen(board, i+1, n) ;
      if(!is_nextQ_place){
        board[i][j] = 0 ;
      }else{
        return true ;
      }
    }
  }
  return false ;
}

typedef long long ll ;
int main(int argc, char const *argv[]){
    IOS ;

    int n = 8 ;
    std::vector<std::vector<int>> board(20, std::vector<int>(20)) ;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    solveNQueen(board, 0, n) ;

    end = std::chrono::high_resolution_clock::now();
    ll elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    cout << "\nElapsed Time: " << elapsed_time << "ms\n";

    return 0;
}
