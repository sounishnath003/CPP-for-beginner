#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

unordered_map<int, list<int>> g ;

void addEdge(int u, int v) {
  g[u].push_back(v) ;
  g[v].push_back(u) ;
}
vector<bool> visited(N) ;
queue<int> q ;
vector<int> blockages{0,0,1,1,0,0,0,0,0};


void bfs(int u, int &cnt) {
  q.push(u) ;
  visited[u] = true ;
  int _cnt = 0 ;
  while(!q.empty()) {
    int node = q.front() ;
    q.pop() ;
    for(auto &&v : g[node]) {
      if(!visited[v] and blockages[v] == 0){
        _cnt++ ;
        q.push(v);
        visited[v] = true ;
      }else if(!visited[v] and blockages[v] == 1 ){
        _cnt++ ;
      }
    }
  }
  cnt = _cnt + 1 ;
}

int maxWaterPossible(unordered_map<int, list<int>> &g, std::vector<int> &blockages) {
  int cnt = 0 ;
  for(const auto u : g) {
    if (blockages[u.first] == 0 and !visited[u.first]){
      for (const auto v : g[u.first]) {
        if(blockages[v] == 0)
          bfs(v, cnt) ;
      }
    }
  }
  return cnt ;
}


int main(int argc, char const *argv[]){
    IOS ;

    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,4);
    addEdge(4,5);
    addEdge(5,6);
    addEdge(6,7);

    cout << maxWaterPossible(g, blockages) ;

    return 0;
}
