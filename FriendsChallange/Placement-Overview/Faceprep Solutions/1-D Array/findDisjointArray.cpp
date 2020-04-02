#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

vector<int> arr1{44,44,44} ;
vector<int> arr2{101,101,101, 44} ;

void printVecs(vector<int> &arr1){
    for (auto &&i : arr1)
    {
        cout << i << "  ";
    }
    cout << endl;
}
 
void ifDisjoint(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, bool> stord ; // O(1)
    string set_type  ;
    printVecs(arr1);
    printVecs(arr2);
    for (auto &&i : arr1) {
        if (stord.find(i) != stord.end()) { // O(logN)
            auto k = find(arr2.begin(), arr2.end(), i) ;
            if (k == arr2.end()) { // O(NlogN)
                set_type = "=> Disjoint Array"; // O(1)
            }else {
                set_type = "=> Joint array";
            }
        }else {
            stord[i] = true ;
        }
    }
    cout << set_type << endl ;
}

int main(int argc, char const *argv[])
{
    ifDisjoint(arr1, arr2)    ;
    return 0;
}
