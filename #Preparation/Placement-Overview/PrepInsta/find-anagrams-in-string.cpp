#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;


void go(string &str, string &pattern) {
	sort(pattern.begin(), pattern.end()) ;
	int pn = pattern.size() ;
	auto startPointer = str.begin() ;
	auto secondPointer = str.begin() + pn ;
	int cnt = 0 ;
	while(secondPointer <= str.end()) {
		string word = string(startPointer, secondPointer) ;
		sort(word.begin(), word.end()) ;
		if(word == pattern) {
			cout << distance(str.begin(), startPointer) << " " ;
		}
		startPointer++ ;
		secondPointer++;
	};
}


int main(int argc, char const *argv[]){
	IOS ;

	string str ;
	string pattern ;

	cin >> str >> pattern ;

	go(str, pattern) ;

	return 0;
}
