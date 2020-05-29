#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
const int MOD = 1e9+7 ;
const int N = 1e6+7 ;
const int inf = 2e9+7 ;
typedef long long ll ;

void intersection(vector<pair<int, int>> &a, vector<pair<int, int>> &b ) {
	auto a_ptr = a.begin(),
		b_ptr = b.begin() ;
		vector<pair<int, int>> answer ; 
		while(a_ptr < a.end() or b_ptr < b.end()) {
			if(b_ptr->first <= a_ptr->second && a_ptr->first <= b_ptr->second ) {
				answer.emplace_back( max(a_ptr->first, b_ptr->first), min(a_ptr->second, b_ptr->second) );
			}
			(a_ptr->second<b_ptr->second) ? a_ptr++ : b_ptr++ ;
		}
	for(auto x : answer) {
		cout << x.first << " " << x.second << endl ;
	}
}


int main(int argc, char const *argv[]){
    IOS ;

	vector<pair<int, int>> a {{1,4}, {8,12}, {15,20}} ;
	vector<pair<int, int>> b {{3,9}, {11,12}} ;
	
	intersection(a, b) ;
	
    return 0;
}




