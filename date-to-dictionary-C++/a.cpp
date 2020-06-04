
/*
-----------------------------------
::Coding Question::
-----------------------------------

Write an efficent function that computes the dictionary missing dates values,
like -

Input is:
------
2 // no. of dates
2019-01-01 100
2019-01-04 115

Output:
-------
2019-01-01:100
2019-01-02:105
2019-01-03:110
2019-01-04:115


bcause - 
every missing date key value is the average if its next and 
previous date key value... !

-------------------
another test case()
--------------------
Input:
---------
3
2019-01-10 10
2019-01-11 20
2019-01-13 10

Output:
---------
2019-01-10:10
2019-01-11:20
2019-01-12:15
2019-01-13:10

*/

#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

inline vector<int> split_date(string &date) {
    int n = date.length() ;
    char parray[n + 1];
    strcpy(parray, date.c_str()) ;
    char *ptr = strtok(parray, "-") ;
    vector<int> digits ;
    while(ptr) {
        digits.push_back(stoi(ptr)) ;
        ptr = strtok(nullptr, "-") ;
    }
    return digits ;
}

inline string digits_to_date(vector<int> &nums) {
    string res ;
    for(int i = 0; i < (int) nums.size(); i++) {
        string x = to_string(nums[i]) ;
        if(x.length() == 1) {
            if(i == (int) nums.size() - 1) {res += "0" + x ; break ;}
            res += "0" + x + "-" ;    
        }else{
            res += x + "-";
        }
        if(i == (int) nums.size() - 1) {res += x ; break ;}
    }
    return res ;
}

string increment_date(string &date) {
    vector<int> dt = split_date(date) ;
    dt[2]++ ;
    return digits_to_date(dt) ;
}

int calculate_days(vector<int> &nums ) {
    int ans = 0 ;
    for(int i = 0; i < (int) nums.size(); i++) {
        if(i == 0) {
            ans += nums[i] * 365 ;
        }
        else if(i == 1) {
            ans += nums[i] * 30 ;
        }else{
            ans += nums[i] ;
        }
    }
    return ans ;
}



// neccesary function that computes - O(N) [Complexity]
vector<pair<string, int>> solution(vector<pair<string, int>> &dates) {
    int n = dates.size(), t = 0;
    vector<pair<string, int>> dictionaries;
    vector<int> differences ;
    for(int i = 1; i < n ; i++) {
        pair<string, int> next_pair = dates[i] ;
        pair<string, int> prev_pair = dates[i-1] ;
        int sumOfVal = abs(next_pair.second - prev_pair.second) ;
        vector<int> nextDigits = split_date(next_pair.first) ;
        vector<int> prevDigits = split_date(prev_pair.first) ;
        int nextDateTotal = calculate_days(nextDigits) ;
        int prevDateTotal = calculate_days(prevDigits) ;
        t = nextDateTotal - prevDateTotal ;
        int diff = 0 ;
        if(sumOfVal != 0) {diff = sumOfVal / t;}
        if(diff != 0){ differences.push_back(diff) ; }
    }
    dictionaries.emplace_back(dates[0]) ;
    differences.resize(t, differences.back()) ;
    int i = 0 ;
    while(t--){
        string inc_date = increment_date(dictionaries.back().first);
        dictionaries.emplace_back(inc_date, dictionaries.back().second + differences[i++]);
    }
    return dictionaries ;
}


int main(int argc, char const *argv[]){
    IOS ;

    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin) ;
        freopen("output", "w", stdout) ;
    #endif

    int n ;
    cin >> n ;
    vector<pair<string, int>> dates ;
    while(n--){
        string date; int value ;
        cin >> date >> value ;
        dates.emplace_back(date, value) ;
    }

    vector<pair<string, int>> missing_dates = solution(dates) ;

    for(auto x : missing_dates) {
        cout << x.first << ":" << x.second << endl ;
    }

    
    return 0;
}
