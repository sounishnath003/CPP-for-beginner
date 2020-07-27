#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

int go(string &str) {
	set<char> nus ;
	string nums = "" ;
	for (const char x : str) {
		if (isdigit(x) && (atoi(&x) % 2 == 0) ) { nus.insert(x) ;}else {return -1 ;}
	}
	copy(nus.begin(), nus.end(), back_inserter(nums)) ;
	int answer = 2 ;
	do{
		int number = stoi(nums) ;
		if ((number&1) == 0) {
			answer = max(answer, number) ;
		}
	}while(next_permutation(nums.begin(), nums.end())) ;
	return (answer == 2) ? -1 : answer ;
}

int main(int argc, char const *argv[]){
	IOS ;
   
	string str = "infytq@73119755" ;

	cout << go(str) << endl ;

	return 0;
}
