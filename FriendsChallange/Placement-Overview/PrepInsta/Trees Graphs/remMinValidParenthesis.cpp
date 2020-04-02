#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

const int N = 1e+6 ;
map<string, bool> vis ;

bool isBalanced(string s) {
    int cnt = 0 ;
    for (auto &&ch : s) {
        if(ch == '(') cnt++;
        else if(ch == ')') cnt-- ;
        if(cnt<0) return 0 ;
    }
    return cnt==0 ;
}

void bfs(string u) {
    queue<string> q ;
    vis[u] = 1 ;
    q.push(u) ;
    bool found = false ;

    while(!q.empty()) {
        string node = q.front() ;
        q.pop() ;
        if (vis[node]) continue ;
        vis[node] = 1;
        if(isBalanced(node)) found = 1, cout << node << " " ;
        if(found) continue ;
        for(int i = 0; i < node.length(); i++) {
            if (node[i] == '(' or node[i] == ')' ){
                string v = node.substr(0, i) + node.substr(i+1, u.length()) ;
                q.push(v) ;
            }
        }
    }
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;


  
    return 0;
}
