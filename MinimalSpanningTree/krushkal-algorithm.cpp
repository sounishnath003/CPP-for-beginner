/*
-- Krushkal Algorithms --
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

unordered_map<char, int> PARENT ;

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
};

class DisjointSet {
    public:
    void makeSet(char vertex) {
        PARENT[vertex] = vertex ;
    }

    char find(char key) {
        if (PARENT[key] == key) {
            return key ;
        }else {
            return find(PARENT[key]) ;
        }
    }

    void uninon(char set_1, char set_2) {
        char X = find(set_1) ;
        char Y = find(set_2) ;

        PARENT[X] = Y ;
    }
} ;

void KrushKal(Graph g){
    vector<Edge> A;
    DisjointSet ds ;

    for (auto &&vertex : g.vertices)
    {
        ds.makeSet(vertex)     ;
    }

    sort(g.edges.begin(), g.edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight ;
    });

    for (auto &&edge : g.edges)
    {
        char root1 = ds.find(edge.vertex1) ;
        char root2 = ds.find(edge.vertex2) ;

        if (root1 != root2) {
            A.push_back(edge);
            ds.uninon(root1, root2) ;
        }
    }

    int minCost = 0 ;

    for (auto &&i : A)
    {
        minCost+= i.weight ;
        cout << i.vertex1 << " ---> " << i.vertex2 <<endl ;
    }

    cout << "Min Cost: "<< minCost ;
}


int main(int argc, char const *argv[])
{

    char t[]{'a', 'b', 'c', 'd', 'e', 'f'};

    Graph g ;
    g.vertices = vector<char>(t, t+ sizeof(t)/sizeof(t[0])) ;
    g.edges.push_back(Edge('a', 'b', 2)) ;
    g.edges.push_back(Edge('b', 'd', 2)) ;
    g.edges.push_back(Edge('c', 'e', 7)) ;
    g.edges.push_back(Edge('f', 'a', 10)) ;
    g.edges.push_back(Edge('e', 'e', 1)) ;
    g.edges.push_back(Edge('d', 'f', 6)) ;
    g.edges.push_back(Edge('d', 'c', 9)) ;

    KrushKal(g) ;
    
    return 0;
}

