#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

class Edge {
    int source, destination, weight ;
};

class DisjointSet {
    unordered_map<int, int> parent ;

    public:
    void makeSet(int N){
        for (size_t i = 0; i < N; i++)
        {
            parent[i] = i;
        }
    }

    int find(int k){
        if(parent[k] == k){
            return k;
        }else {
            return(find(parent[k]));
        }
    }

    void Union(int a, int b){
        int x= find(a);
        int y= find(b);

        parent[x] = y;
    }
};


vector<Edge> krushkalAlgorithm(vector<Edge> edge, int N){
    vector<Edge> minimumSpanningTree;
    DisjointSet ds ;

    

}



int main(int argc, char const *argv[])
{
    
}
