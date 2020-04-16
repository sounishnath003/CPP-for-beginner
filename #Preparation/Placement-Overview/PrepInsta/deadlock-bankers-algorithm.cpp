#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

const int R = 3 ;
const int P = 5 ;

void _needMatrix(int need[P][R], int maxm[P][R], int allot[P][R]) {
    for(int row = 0; row < P; ++row) {
        for (int col = 0; col < R; ++col) {
            need[row][col] = maxm[row][col] - allot[row][col] ;
        }
    }
}

void isSafe(int processes[], int avail[], int maxm[][R], int allot[][R]){
    int need[P][R];
    _needMatrix(need, maxm, allot) ;
    bool finish[P] = {0} ;

    int safeSq[P] ;
    int _pcount = 0 ;
    while(_pcount < P) {
        bool found = false ;
        for (int p = 0; p < P ; p++) {
            if (finish[p] == 0) {
                int r ;
                for(r = 0; r < R; ++r) {
                    if (need[p][r] > avail[r] )
                        break ;
                }
                if(r == R) {
                    for(int k = 0; k < R; ++k) {
                    avail[k] += allot[p][k] ;
                    } 
                    safeSq[_pcount++] = p ;
                    finish[p] = true ;
                    found = true ;
                }
            }
        }
        if (!found) {printf("system is not in safe state\n") ;} 
    }

    for(int i = 0; i <P; ++i) {
        printf("%d ", safeSq[i]) ;
    }

}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    int processes[] = {0, 1, 2, 3, 4};

    
    int avail[] = {3, 3, 2};

    int maxm[][R] = {{7, 5, 3},
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};

    int allot[][R] = {{0, 1, 0},
                      {2, 0, 0},
                      {3, 0, 2},
                      {2, 1, 1},
                      {0, 0, 2}};
    isSafe(processes, avail, maxm, allot);

    return 0;
}
