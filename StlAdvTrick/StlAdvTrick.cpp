#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std ;

void printvector(vector<double> &arr) {
    for (auto &&i : arr)
    {
        cout << i <<  " " ;
    }
    cout  << endl ;
}

void printSet(set<int> &s) {
    for (auto &&i : s)
    {
        cout << i << "  " ;
    }
    cout << endl ;
    
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
    set<int> s;
    s.insert(rand());
    s.insert(rand());
    s.insert(rand());
    s.insert(356);
    s.insert(rand());
    s.insert(rand());

    printSet(s);

    set<int>::iterator it = s.find(356) ;
    if (it == s.end()) {
        cout  << "Search Item not present" << endl;
    } else {
        cout  << "Search Item present" << endl;
    }

    set<int>::iterator it1 = s.lower_bound(356);
    cout << *it1 << endl ;

    auto it2 = s.upper_bound(356);
    cout << *it2 << endl ;

}


int main(int argc, char const *argv[])
{
    // vector coding
    vectorTuts();

    // set coding
    setTuts() ;

    
    return 0;
}
