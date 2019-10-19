/*
-- Prims Algorithms --
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

struct Edge
{
    char vertex1;
    char vertex2;
    int weight ;

    Edge(char v1, char v2, int wei) {
        vertex1 = v1;
        vertex2 = v2;
        weight = wei;
    }
};


struct Graph {
    vector<char> vertices ;
    vector<Edge> edges ;

    vector<pair<char, Edge>> adjacennt(char u) {
        vector<pair<char, Edge>> res ;
        for (auto &&edge : edges)
        {
            if (edge.vertex1 == u){
                res.push_back(make_pair(edge.vertex2, edge) );
            }else if(edge.vertex2 == u){
                res.push_back(make_pair(edge.vertex1, edge));
            }
        }
        return res ;
    }
};


void Prims(Graph& g) {
    unordered_map<char, char> A ;
    unordered_map<char, char> PARENT ;
    unordered_map<char, int> KEY ;
    int cost = 0 ;

    for (auto &&vertex : g.vertices)
    {
        PARENT[vertex] = '\0' ;
        KEY[vertex] = INT_MAX ;
    }

    KEY['a'] = 0 ;
    vector<char> Q = g.vertices ;
    queue<char> que ;

    for (auto &&i : g.vertices)
    {
        que.push(i) ;
    }
    

    while (!que.empty())
    {
        // char u = *min_element(Q.begin(), Q.end(), [&](char x, char y){
        //     return KEY[x] > KEY[y] ;
        // }) ;

        char u = que.front() ;

        // vector<char>::iterator itr = remove(Q.begin(), Q.end(), u) ;
        que.pop() ;
        if (PARENT[u] != '\0'){
            A[u] = PARENT[u] ;
        }
        vector< pair<char, Edge>> adj = g.adjacennt(u) ;
        for (auto &&v : adj)
        {
            if(find(Q.begin(), Q.end(), v.first) != Q.end()) {
                if(v.second.weight < KEY[v.first]){
                    cost += v.second.weight ;
                    PARENT[v.first] = u ;
                    KEY[v.first] = v.second.weight ;
                }
            }
        }
        
    }

    for (auto &&i : A)
    {
        cout << i.first << " ---> " <<i.second << endl ;
    }

    cout << "Min Cost: " << cost << endl ;

}


int main(int argc, char const *argv[])
{
     char t[]{'a', 'b', 'c', 'd', 'e', 'f'};

    Graph g ;
    g.vertices = vector<char>(t, t+ sizeof(t)/sizeof(t[0])) ;
    g.edges.push_back(Edge('a', 'b', 3)) ;
    g.edges.push_back(Edge('b', 'd', 2)) ;
    g.edges.push_back(Edge('c', 'e', 7)) ;
    g.edges.push_back(Edge('f', 'a', 10)) ;
    g.edges.push_back(Edge('e', 'e', 1)) ;
    g.edges.push_back(Edge('d', 'f', 6)) ;
    g.edges.push_back(Edge('d', 'c', 9)) ;

    Prims(g) ;

    return 0;
}
