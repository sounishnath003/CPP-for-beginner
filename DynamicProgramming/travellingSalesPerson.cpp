#include <iostream>
#include <bits/stdc++.h>
#define v 4

using namespace std;

void travellingSalesManMinCost(vector<vector<int>> &graphh, int startpoint)
{

    for(auto &&i : graphh) {
      for(auto &&j : i) {
        std::cout << j << "  " ;
      }std::cout << std::endl ;
    }

    vector<int> vertices;

    for (int i = 0; i < v; i++)
    {
        if(i != startpoint){
            vertices.push_back(i);
        }
    }


    int min_path = INT_MAX;

    do
    {
        int k = startpoint;
        int get_cost = 0;
        for (int i = 0; i < vertices.size(); i++)
        {
            get_cost += graphh[k][vertices[i]];
            k = vertices[i];
        }
        get_cost += graphh[k][startpoint];
        min_path = min(min_path, get_cost);
    } while (next_permutation(vertices.begin(), vertices.end()));

    std::cout << "total minimum cost --> " << min_path << std::endl;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> graphh = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    travellingSalesManMinCost(graphh, 0);

    return 0;
}
