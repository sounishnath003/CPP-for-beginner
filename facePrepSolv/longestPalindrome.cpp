#include<iostream>
#include<bits/stdc++.h>
#define deb(x) cout << #x << "  " << x << endl 

using namespace std ;

vector<int> arr = {5,131,54545,1525, 12} ;
unordered_map<int, int> lengthMap ;

void countLength(vector<int> &storeN){
    int length = 0 ;
    for (auto &&i : storeN){
        length = log10(i) + 1 ;
        lengthMap[i] = length;
    }
}

void isPalindrome(int n){
    vector<int> storeN;
    int res = 0 ;
    int tmp = n;
        while (tmp!= 0)
        {
            res = res*10 + tmp%10;
            tmp /= 10 ;
        }
        if(res == n){
            storeN.push_back(n) ;
        }
        countLength(storeN);
}

void findPalindromeLong(vector<int> &arr) {
    int res = 1 ;
    for (size_t i = 0; i < arr.size(); i++)
    {
        isPalindrome(arr[i]) ;
    }
}


int main(int argc, char const *argv[])
{
    findPalindromeLong(arr);
    for (auto &&i : lengthMap){
        cout << i.first << " -> " << i.second << endl ;
    }
    return 0;
}
