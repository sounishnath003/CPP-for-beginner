#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=30;
int n, m;
string s[mxN], ans;
vector<int> adj[26];
bool bad;
bool vis[26], act[26];

void dfs(int u) {
	act[u]=1;
	vis[u]=1;
	for(int v : adj[u]) {
		if(act[v]&&v^u)
			bad=1;
		else {
			if(!vis[v])
				dfs(v);
		}
	}
	act[u]=0;
	ans+=(char)(u+'A');
}

void solve() {
	cin >> n >> m;
	set<char> t;
	for(int i=0; i<n; ++i) {
		cin >> s[i];
		for(char c : s[i])
			t.insert(c);
		if(i) {
			for(int j=0; j<m; ++j)
				adj[s[i-1][j]-'A'].push_back(s[i][j]-'A');
		}
	}
	memset(vis, 0, 26);
	memset(act, 0, 26);
	ans="";
	bad=0;
	for(char c : t)
		if(!vis[c-'A'])
			dfs(c-'A');
	if(bad)
		ans="-1";
	cout << ans << "\n";
	for(int i=0; i<26; ++i)
		adj[i].clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}