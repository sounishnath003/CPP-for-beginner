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

void vectorTuts() {
    // init vector
    vector<double> arr = {1,-2.66,2.1, -3.5,2,11,0,2 ,77,-9,4} ;
    printvector(arr);

    // sorting vectors
    sort(arr.begin(), arr.end()) ;
    printvector(arr);

    // performing binary_search
    bool present = binary_search(arr.begin(), arr.end(), -3.5);
    cout << "Item \'-3.5\' : "  << present << endl ;
    
    bool presenty = binary_search(arr.begin(), arr.end(), 2.1);
    cout << "Item \'2.1\' : "  << present << endl ;

    // pushing new elem in V_arr
    arr.push_back(56);
    printvector(arr);
}

void setTuts() {
    
}

int main(int argc, char const *argv[])
{
    
    vectorTuts();

    setTuts() ;

    
    return 0;
}
