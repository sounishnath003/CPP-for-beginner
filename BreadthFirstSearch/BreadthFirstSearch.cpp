#include<iostream>
#include<queue>
#include<vector>
using namespace std ;
#define pb push_back ;


class BreadthFirstSearch
{
private:
    /* data */
    vector<bool> vLists;
    vector<vector<int>> graphs ;

public:
    BreadthFirstSearch(int n) {
        vLists.assign(n, false);
        graphs.assign(n, vector<int>());
    }

    void checkEdge(long a, long b){
        graphs[a].push_back(b);
    }

    void seachBFS(int u) {
        queue<int> q ;
        q.push(u);

        vLists[u] = true ;

        while (!q.empty()) {
            /* code */
            int fronty = q.front();
            q.pop();

            cout << fronty << endl ;

             for (auto i = graphs[fronty].begin(); i != graphs[fronty].end(); i++) { 
                if (!vLists[*i]) { 
                    q.push(*i); 
                    vLists[*i] = true; 
                } 
             }
        }
        
    }

};

int main(int argc, char const *argv[])
{
    /* code */
    int n, e; 
    
    n = 5, e = 5 ;
    BreadthFirstSearch obj(n) ;
  
    int a, b; 
    for (int i = 0; i < e; i++) { 
        a = rand();
        b = rand();
        obj.checkEdge(a,b) ;
    } 
  
    for (int i = 0; i < n; i++) { 
        //obj.seachBFS(i); 
    }

    return 0;
}