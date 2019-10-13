#include<iostream>
#include<bits/stdc++.h>

using namespace std ;


unordered_map<char, int> PARENT ;

struct Edge {
    char v1;
    char v2;
    int weight ;

    Edge(char vt1, char vt2, int wei) {
        v1 = vt1;
        v2 = vt2;
        weight = wei;
    }

};

struct Graph {
    vector<Edge> edges ;
    vector<char> vectices ;
};

class DisjointSet {
private:
    
public:
    void makeSet(char vertex) {
        PARENT[vertex] = vertex ;
    }

    char findd (char vertex) {
        if(PARENT[vertex] == vertex) {
            return PARENT[vertex] ;
        }
        return findd(PARENT[vertex]) ;
    }

    void unionn(char set_1, char set_2) {
        char X = findd(set_1) ;
        char Y = findd(set_2) ;

        PARENT[X] = Y ;
    }
};


void krushkal(Graph &g) {
    vector<Edge> A ;
    DisjointSet ds ;

    for(auto c : g.vectices) {
        ds.makeSet(c) ;
    }

    sort(g.edges.begin(), g.edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight ;
    });

    for (auto &&i : g.edges)
    {
        char root1 = ds.findd(i.v1) ;
        char root2 = ds.findd(i.v2) ;

        if(root1 != root2) {
            A.push_back(i) ;
            ds.unionn(root1, root2) ;
        }
    }

int cost = 0 ;
    for (auto &&i : A)
    {
        cost+= i.weight ;
        cout << i.v1 << " ----> " << i.v2 << endl ;
    }

    cout << "total minimum cost " << cost ;
    
}

int main(int argc, char const *argv[])
{
    char t[] = {'a', 'b', 'c', 'd', 'e', 'f'} ;
    
    Graph g ;
    g.vectices = vector<char>(t, t + sizeof(t)/sizeof(t[0])) ;
    g.edges.push_back(Edge('a', 'b', 2)) ;
    g.edges.push_back(Edge('b', 'd', 2)) ;
    g.edges.push_back(Edge('c', 'e', 7)) ;
    g.edges.push_back(Edge('f', 'a', 10)) ;
    g.edges.push_back(Edge('e', 'e', 1)) ;
    g.edges.push_back(Edge('d', 'f', 6)) ;
    g.edges.push_back(Edge('d', 'c', 9)) ;

    krushkal(g) ;
    
    return 0;
}
