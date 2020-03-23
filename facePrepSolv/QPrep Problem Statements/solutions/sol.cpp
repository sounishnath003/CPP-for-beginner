#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}


// Two Sum Target
void _twoSum(vector<int>& v, int &target) {
    set<int> cache ;
    for (int i = 0; i < v.size(); i++) {
        int r = target - v[i] ;
        if (cache.find(v[i]) != cache.end() ) {
            cout << "( " << r << ", "  << v[i] << " )" << endl ;
        }
        cache.insert(target - v[i]) ;
    }
}

// Rain Tapping
void waterTapping(vector<int>& v) {
    vector<int> rightMax(8), leftMax(8) ;
   
   rightMax[0] = v[0] ;
   for (int i = 1; i < v.size(); i++) {
       rightMax[i] = max(v[i], rightMax[i-1]) ;
   }
   leftMax[7] = v[7] ;
   for (int i = v.size()-2; i >= 0 ; i--) {
       leftMax[i] = max(v[i], leftMax[i+1]) ;
   }
   int waterCount = 0 ;
   for (int i = 0; i < v.size(); i++) {
       waterCount += min(leftMax[i], rightMax[i]) - v[i] ;
   }
   cout << waterCount << endl ;
}

// String To Int
void _stringToInt(string& s) {
    bool minus = false;
    int res = 0;
    for(auto &i : s) {
        if (i == '-') {minus = true; continue ;}
        if (i == '+') {continue;}
        res *= 10 ;
        res+= i-'0' ;
    }
    if(minus){res*=-1;}
    cout << res << endl;
}

// Island Problem
bool safe_area(int row, int col, int i, int j) {
    if ((i >= 0 and row > i) and (j >= 0 and col > j)){
        return true;
    }
    return false ;
}

void dfs(vector<vector<int>>&mat, int row, int col , int i, int j) {
    if (safe_area(row, col, i, j)) {
        mat[i][j] = false ;
        dfs(mat, row, col, i, j-1);
        dfs(mat, row, col, i, j+1);
        dfs(mat, row, col, i-1, j);
        dfs(mat, row, col, i-1, j+1);
        dfs(mat, row, col, i, j);
        dfs(mat, row, col, i-1, j);
        dfs(mat, row, col, i, j-1);
    }
}

void _getIslands(vector<vector<int> >& mat ) {
    int row = mat.size() ;
    int col = mat[0].size() ;

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++ ) {
            if ( safe_area(row, col, i, j) and  (mat[i][j] == 1)) {
                mat[i][j] = false ;
                dfs(mat, row, col ,i, j) ;
            }
        }
    }
}

// Merge Intervals 
vector<pair<int, int>> _mergeIntervals (vector<pair<int, int>>& intervals ) {
    vector<pair<int, int> > res ;

    if (intervals.size() == 0) {cout << "" << endl ;exit(-1) ;}
    sort(begin(intervals), end(intervals),
    [&](const pair<int, int> a, const pair<int, int> b) {
        return a.first < b.first ;    
    }) ;
    res.push_back(intervals[0]) ;
    for (int i = 1; i < intervals.size(); i++) {
        if (res.back().second < intervals[i].first) {
            res.push_back(intervals[i]);
        }else{
            res.back().second = max(intervals[i].second, res.back().second);
        }
    }
    return res ;
}


// Phone Dialer Names
void _getDialNames(vector<int>& num, int cur_Index, char out[], int n) {
    const char dialer[10][5] = { "", "!", "abc ", "def ", "efg ", "ijk ", "mno ", "pqrs", "tuv", "wxyz" } ;
    
    if(cur_Index == n){
        cout  << out << " " ;
        return;
    }
    for(int i =0 ;i < strlen(dialer[num[cur_Index]]); i++){
        out[cur_Index] = dialer[num[cur_Index]][i];
        _getDialNames(num, cur_Index+1, out, n);
        if(num[cur_Index] == 0 ){return ;}
    }
}


// Matrix Position
void printPosValue(vector<vector<int> >&mat, pair<int, int>& curPos){
    cout << "value at pos{ " << curPos.first << ", " << curPos.second << " } = " << mat[curPos.first][curPos.second] << endl;
}
void _getValuesPos(vector<vector<int>>& mat, pair<int, int>& curPos, int toMOve, int noMove) {
    int row = mat.size() ;
    int col = mat[0].size() ;

    if (curPos.first < row-1 and curPos.second < col-1 ) {
        if (toMOve == 1) {
            while(noMove--){
                ++curPos.second;
                printPosValue(mat, curPos) ;
            }
        }
        if (toMOve == 2) {
            while(noMove--){
                ++curPos.first;
                printPosValue(mat, curPos);
            }
        }
        if (toMOve == 3) {
            while(noMove--){
                --curPos.second;
                printPosValue(mat, curPos);
            }
        }
        if (toMOve == 4) {
            while(noMove--){
                --curPos.first;
                printPosValue(mat, curPos);
            }
        }
    }else cout << "sorry not elem found " << endl;
    
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    freopen("inp.txt", "r", stdin) ;
    freopen("out.txt", "w", stdout) ;

    int size ; cin >> size ;
    vector<int>v;
    while (size--){
        int l ; cin >> l ;
        v.push_back(l) ;
    }

    waterTapping(v) ;
    

    return 0;
}
