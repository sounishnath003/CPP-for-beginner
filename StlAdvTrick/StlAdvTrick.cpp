#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

void printvector(vector<double> &arr) {
    for (auto &&i : arr)
    {
        cout << i <<  " " ;
    }
    cout  << endl ;
}

int main(int argc, char const *argv[])
{
    vector<double> arr = {1,-2.66,2.1, -3.5,2,11,0,2 ,77,-9,4} ;
    sort(arr.begin(), arr.end()) ;
    printvector(arr);

    bool present = binary_search(arr.begin(), arr.end(), -3.566);

    cout << present << endl ;
    
    return 0;
}
