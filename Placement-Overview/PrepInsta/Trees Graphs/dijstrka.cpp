#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

unordered_map<string, list<pair<string, int>>> g ;

void addEdge(string u, string v, int dist) {
    g[u].push_back({v, dist}) ;
    g[v].push_back({u, dist}) ;
}

void printAdj() {
    for (auto && j : g) {
        cout << j.first << " -> " ;
        for (auto &&v : j.second) {
            cout << "( " << v.first << ", "  << v.second << " )";
        }cout << endl ;
    }
    cout << endl ;
}

void dijstrka(string u) {
    unordered_map<string, int> dist ;

    for (auto &&j : g) {
        dist[j.first] = INT_MAX ;
    }

    set<pair<int, string> > s ;
    dist[u] = 0 ;
    s.insert({0, u}) ;

    while(!s.empty()) {
        auto p = *(begin(s)) ;
        string node = p.second ;
        
        int nodeDist = p.first ;
        s.erase(s.begin()) ;

        for (auto &&v : g[node]) {
            if (nodeDist + v.second < dist[v.first] ){
                string dest = v.first ;
                auto f = s.find({dist[dest], dest}) ;
                if ( f != s.end()) {
                    s.erase(f) ;
                }
                dist[dest] = nodeDist + v.second ;
                s.insert({dist[dest], dest}) ;
            }
        }
    }

    for (auto &&d : dist) {
        cout << d.first << " is located at disrance of " << d.second << endl ;
    }


}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    clock_t t1 = clock() ;

    addEdge("Amritsar", "Delhi", 1) ;
    addEdge("Amritsar", "Jaipur", 4) ;
    addEdge("Jaipur", "Delhi", 2) ;
    addEdge("Jaipur", "Mumbai", 8) ;
    addEdge("Bhopal", "Agra", 2) ;
    addEdge("Mumbai", "Bhopal", 3) ;
    addEdge("Agra", "Delhi", 1) ;

    printAdj() ;
    
    dijstrka("Jaipur") ;


    clock_t t2 = clock() ;
    cout << "function takes: " << 1000.0*(t2-t1)/CLOCKS_PER_SEC << " miliseconds." << endl ;

    return 0;
}
