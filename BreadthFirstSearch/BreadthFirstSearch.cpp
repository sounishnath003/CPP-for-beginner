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
    void checkEdge(int a, int b){
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
    return 0;
}
