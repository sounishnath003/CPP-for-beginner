#include<iostream>
#include<bits/stdc++.h>
#define deb(x) cout << #x << " " << x << endl
using namespace std ;

vector<int> elms = {1,2,3,4,1} ;
unordered_map<int, int> st ;

void nonRepeating(vector<int> &elms) {
    for (int i=0; i< elms.size(); i++)
    {
        st[elms[i]]++;
    }

    for (auto &&i : st)
    {
        if (i.second == 1){
            cout << i.first << endl ;
        }
    }
}


int main(int argc, char const *argv[])
{
    nonRepeating(elms) ;
    return 0;
}
