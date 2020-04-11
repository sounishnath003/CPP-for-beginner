#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

vector<pair<int, int>> myVec ={
    {1,0},{0,1},
    {2,3}, {3,4},
    {4,5}, {5,2},
    {3,2}
 } ;

void printSymettric(vector<pair<int, int>> &myVec) {
    unordered_map<int, int> stord ; // O(NlogN)
    for (auto &&i : myVec) {
        if (stord.find(i.second) != stord.end() && stord[i.second] == i.first) {
            cout << "{" << i.second << ", " << i.first << "}" << endl ;
        }else {
            stord[i.first] = i.second ;
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    printSymettric(myVec) ;
    return 0;
}
