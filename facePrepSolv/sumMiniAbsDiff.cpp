#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

vector<int> arr{1,3,9,6,3} ;

void sumMinAbsDiff(vector<int> &arr) {
    static int sum = 0 ;
    sort(arr.begin(), arr.end()) ;

    for (auto &&i : arr)
    {
        cout << i << "  " ;
    }cout << endl ;

    sum += abs(arr.at(0) - arr.at(1)) ;
    sum += abs(arr.at(arr.size()-2) - arr.at(arr.size()-1)) ;

    for (size_t i = 1; i < arr.size() ; i++) {
        sum+= min((abs)(arr[i] - arr[i-1]), (abs)(arr[i+1]-arr[i]));
    }
    cout << "sum: " << sum ;
}


int main(int argc, char const *argv[])
{
    sumMinAbsDiff(arr);
    return 0;
}
