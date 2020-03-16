#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

vector<int> elm1 = {1,3,5};
vector<int> elm2 = {2,4,1};

void displ(vector<int> &elm1) {
    for (auto &&i : elm1)
    {
        cout << i << " " ;
    }
    cout << endl ;
}

void permut(vector<int> &elm1, vector<int> &elm2) {
    vector<int> storemul ;
    long long multiply = 0;
    int misn ;
    int misnm ;
    
    sort(elm1.begin(), elm1.end()) ;
    sort(elm2.begin(), elm2.end()) ;

    for (size_t i = 0; i < elm1.size(); i++)
    {
        while (next_permutation(elm1.begin(), elm1.end())) {
            while (next_permutation(elm2.begin(), elm2.end())) {
                multiply =  elm1[i] * elm2[i]  ;
            } 
            storemul.push_back(multiply);
        }

    }
    
   misn = *min_element(storemul.begin(), storemul.end()) ;
   misnm = *max_element(storemul.begin(), storemul.end()) ;
   cout << "minimum value " << misn << endl ;
   cout << "maximum value " << misnm << endl ;
    
}

int main(int argc, char const *argv[])
{
    permut(elm1, elm2) ;
    return 0;
}
