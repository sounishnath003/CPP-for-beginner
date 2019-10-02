#include<iostream>
#include<bits/stdc++.h>
#define deb(x) cout << #x << "  " << x << endl

using namespace std ;

vector<int> arr1{10, 20, 20, 40, 50};
vector<int> arr2{20, 40, 50};

void subsetOrNot(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, int> stored ;
    bool f = false ;
    for (auto &&i : arr1)
    {
        stored[i]++;
    }
    for (auto &&i : arr2)
    {
        if (stored.find(i) == stored.end()){
            f = true ;
            break ;
        }else {
            stored[i]--;
            if(stored[i] == 0){
                stored.erase(stored.find(i)) ;
            }
        }
    }
    if (f) {
        cout << "not subset" << endl ;
    }else {
        cout << "subset" << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    subsetOrNot(arr1, arr2);
    return 0;
}
