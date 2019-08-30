#include<iostream>
#include<bits/stdc++.h>
#include<disjointSets.hpp>

using namespace std ;

class Graph {
    int vetex, edge ;
    vector< pair<int, pair<int, int>> > edges; 


    Graph(int ve, int ed){
        this->vetex = ve;
        this->edge = ed;
    }

    void addEdge(int u, int v, int w){
         edges.push_back({w, {u, v}}); 
    }

    


};



int main(int argc, char const *argv[])
{
    
}
