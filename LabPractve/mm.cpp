#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

vector<int> v{1,2,0,20,52,520,60,50,6,05,5,877} ;


void binSearch(vector<int> &v ) {
    bool present = binary_search(begin(v), end(v), 20);

    if(present) {
        std::cout << "found " << present << "  " << endl ;
    }else
    {
        std::cout << "not found " << present << "  " << endl;
    }
}

unordered_map<char, int > PARENT ;

struct Edge {
    char v1, v2 ;
    int weight ;

    Edge(char vv1, char vv2, int wei) {
        v1 = vv1;
        v2 = vv2 ;
        weight = wei ;
    }
}; 

struct Graph {
    vector<char> vertices ;
    vector<Edge> edges ;
};


class Disjoint {
    public:

    void makeset(char vertex) {
        PARENT[vertex] = vertex ;
    }

    char find(char vert) {
        if (PARENT[vert] == vert) {
            return PARENT[vert] ;
        }
        else {return find(PARENT[vert]) ;} 
    }

    void unionn(char r1 , char r2) {
        char X = find(r1) ;
        char Y = find(r2) ;

        PARENT[X] = Y ;
    }
};


void Khrushkal(Graph &g) {

    vector<Edge> A;
    Disjoint ds ;

    for (auto &&c : g.vertices)
    {
        ds.makeset(c) ;
    }

    sort(begin(g.edges), end(g.edges), [](Edge a, Edge b) {
        return a.weight < b.weight ;
    }) ;
    
    for (auto &&i : g.edges)
    {
        char rb1 = ds.find(i.v1) ;
        char rb2 = ds.find(i.v2) ;

        if (!(rb1 == rb2)) {
            A.push_back(i) ;
            ds.unionn(rb1, rb2) ;
        }
    }

    int s = 0;

    for (auto &&i : A)
    {
        s = s + i.weight ;
    }

    std::cout << s << "  total min cost" << endl;

}

#define max_d 1

struct Job {
    int deadline ;
    char id;
    double profit ;
};

vector<Job> Jobbs = {
    {2, 'a', 4},
    {1, 'b', 1},
    {3, 'c', 7}
} ;

void schedulejobs(vector<Job> &Jobbs) {
    double maxProfit = 0 ;
    vector<int> slots(max_d, -1) ;

    sort(Jobbs.begin(), Jobbs.end(), [](Job &first, Job &second) {
        return (first.profit > second.profit);
    });

    for (auto &&job : Jobbs) {
        for (size_t i = 0; i <= job.deadline; i++) {
            if (i <= max_d and slots[i] == -1){
                maxProfit += job.profit ;
            }
        }   
    }

    for (size_t i = 0; i < max_d; i++)
    {
        if (slots[i] != -1)
        {
            cout << slots[i] << "    " ;
        }
    }cout<<endl;

    std::cout << maxProfit << std::endl ;
    
}

// int knapsack(int capacity, int weight[] , int value[] , int n) {
//     if(n == 0 or weight <= 0)
//         return 0;

//     if (weight[n-1] > capacity) 
//         return  knapsack(capacity, weight, value, n-1) ;

//     return max(value[n - 1] + knapsack(capacity - weight[n - 1], weight, value, n - 1),
//                knapsack(capacity, weight, value, n - 1));
// }

int knapsack(int capacity, int weight[], int value[], int n) {
    if (weight <=0 and n == 0) {
        return 0 ;
    }

    if (weight[n-1] > capacity) {
        return knapsack(capacity, weight, value, n-1) ;
    }

    return max(value[n - 1] + knapsack(capacity - weight[n - 1], weight, value, n - 1),
               knapsack(capacity, weight, value, n - 1));
}

int weight[] = {10, 20, 30};
int value[] = {60, 100, 120};
int wLimit = 50;

int main(int argc, char const *argv[])
{

    binSearch(v) ;

    char t[] = {'a', 'b', 'c', 'd', 'e', 'f'};

    Graph g;
    g.vertices = vector<char>(t, t + sizeof(t) / sizeof(t[0]));
    g.edges.push_back(Edge('a', 'b', 2));
    g.edges.push_back(Edge('b', 'd', 2));
    g.edges.push_back(Edge('c', 'e', 7));
    g.edges.push_back(Edge('f', 'a', 10));
    g.edges.push_back(Edge('e', 'e', 1));
    g.edges.push_back(Edge('d', 'f', 6));
    g.edges.push_back(Edge('d', 'c', 9));

    Khrushkal(g);

    schedulejobs(Jobbs) ;

    // std::cout << knapsack(wLimit, weight, value, 3) << std::endl ;

    

        return 0;
}
