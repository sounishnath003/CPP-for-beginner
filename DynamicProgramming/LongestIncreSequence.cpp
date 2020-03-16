#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

void calculateLIS(vector<int> &vect) {
    vector<vector<int>> LongestSequence(vect.size()) ;
    LongestSequence[0].push_back(vect[0]) ;

    for (size_t i = 1; i < vect.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (vect[i] > vect[j]) {
                LongestSequence[i] = LongestSequence[j];
            }
        }

        LongestSequence[i].push_back(vect[i]);
    }
    

    for (auto &&i : LongestSequence)
    {
        for (auto &&j : i)
        {
            cout << j << " " ;
        }cout << endl ;
    }
    
}


int main(int argc, char const *argv[])
{
    vector<int> vect = {3,2,6,4,5,1} ;

    calculateLIS(vect) ;
    
    return 0;
}
