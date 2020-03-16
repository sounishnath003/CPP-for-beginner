#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

vector<int> arr{1, 2, 3, 5, 2, 9, 7, 3, 5} ;

void frecCount(vector<int> &arr) {
    unordered_map<int, int> counTable ;
    // sorting vector O(NlogN)
    sort(arr.begin(), arr.end()) ; // takes cost to do this <Not needed>

    for (auto &&i : arr)
    {
        counTable[i]++ ; // count & find => O(1)
    }

    for (auto &&i : counTable)
    {
        cout << i.first << "  -> " << i.second ; // O(N)
        cout << endl ;  
    }
    
    
}


int main(int argc, const char **argv) {
    frecCount(arr) ;
}