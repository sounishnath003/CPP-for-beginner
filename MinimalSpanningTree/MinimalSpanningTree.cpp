#include<iostream>
#include<bits/stdc++.h>

using namespace std ;


class Edge {
    public:
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


vector<Edge> krushkalAlgorithm(vector<Edge> edges, int N){
    vector<Edge> minimumSpanningTree;
    DisjointSet ds ;

    ds.makeSet(N);

    while (minimumSpanningTree.size() != N-1) {
        Edge nextEdge = edges.back();
        edges.pop_back();

        int x = ds.find(nextEdge.source);
        int y = ds.find(nextEdge.destination);

        if(x != y){
            minimumSpanningTree.push_back(nextEdge);
            ds.Union(x, y);
        }
    }

    return minimumSpanningTree;
}


struct compare
{
	inline bool operator() (Edge const &a, Edge const &b)
	{
		return (a.weight > b.weight);
	}
};

int main(int argc, char const *argv[])
{
    vector<Edge> edges = {
        { 0, 1, 7 }, { 1, 2, 8 }, { 0, 3, 5 }, { 1, 3, 9 },
		{ 1, 4, 7 }, { 2, 4, 5 }, { 3, 4, 15 }, { 3, 5, 6 },
		{ 4, 5, 8 }, { 4, 6, 9 }, { 5, 6, 11 } 
        
        // {4, 5, 0 }, {1, 2, 7}, {1, 4, 6}, {4, 2, 9}, {4, 3, 8}, {2, 3, 6}
    };

    sort(edges.begin(), edges.end(), compare());

    int N = 2;

    vector<Edge> e = krushkalAlgorithm(edges, N);

    double profit = 0;

    for (auto &&i : e)
    {   
        profit += i.weight;
        cout << i.weight << "   ";
    }cout << endl ;
    
    cout << "Total profit : " << profit << endl;

    return 0;
}
