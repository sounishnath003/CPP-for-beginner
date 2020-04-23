#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

void go(vector<vector<int>> &grid) {
    int H = grid.size(), W = grid[0].size() ;
    auto helper_sum = [&] (int number) {
        int temp = number ;    
        int cur_sum = 0 ;
        while(number) { cur_sum += number%10; number/= 10 ; }
        return (temp % cur_sum == 0) ;
    } ;
    for (int row = 0; row < H - 1; row++) {
        for (int col = 0; col < W - 1 ; col++) {
            int num1 = grid[row][col],
                num2 = grid[row][col+1],
                num3 = grid[row+1][col],
                num4 = grid[row+1][col+1] ;
            if(helper_sum(num1) and helper_sum(num2) and helper_sum(num3) and helper_sum(num4)) {
                cout << num1 << setw(6) << num2 << endl ;
                cout << num3 << setw(6) << num4 << endl ;
            }cout << endl ;
        }
    }
}



int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<vector<int>> grid = {
        {42, 54, 2},
        {30,24,27},
        {180, 190, 40},
        {11, 121, 13}
    } ;

    go(grid) ;
   
    return 0;
}
