#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

vector<int> elms = {8,19,7,14,8,12} ;
unordered_map<int, bool> hashmap ; 

void removeDupls(vector<int> &elms ) {
    for (auto &&i : elms)
    {
        if (hashmap.find(i) == hashmap.end()){
            cout << i << "  " ;
        }
        hashmap[i] == true ;
    }
    
}

int main(int argc, char const *argv[])
{
    removeDupls(elms) ;
    return 0;
}
