#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

bool vis[1000] ;
vector<int> g[1000] ;


void dfs(int u) {
    vis[u] = true;
    for(auto &&v : g[u]) {
        if (vis[v]) continue ;
        dfs(v);
    }
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;
    freopen("inp.txt", "r", stdin) ;
    freopen("out.txt", "w", stdout) ;

    int n ; cin >> n ;
    while(n--) {
        int u, v ;
        cin >> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(3) ;

    if (vis[12]){
        cout << "visited" ;
    }else{cout << "cannot visit!" ;}
    
    return 0;
}
