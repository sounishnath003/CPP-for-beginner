#include<iostream>
#include<bits/stdc++.h>
#define deb(x) cout << #x << "  " << x << endl 

using namespace std ;

vector<int> elms{3,50,75,100} ;

bool isPossible(vector<int> &elms){
    for (int i = 0 ; i < elms.size(); i++)
    {
        if (elms[i]%2 == 0){
            elms[i] = elms[i]/2;
        }

        if (elms[i]%3 == 0){
            elms[i] = elms[i]/3;
        }
    }
    for (size_t i = 1; i < elms.size(); i++)
    {
        if(elms[i] != elms[0]){
            return false ;
        }else {
            return true ;
        }
    }
    return true ;
}


int main(int argc, char const *argv[])
{
    if(isPossible(elms)){
        cout << "yes" << endl;
    }else {
        cout << "no" << endl ;
    }
    return 0;
}
