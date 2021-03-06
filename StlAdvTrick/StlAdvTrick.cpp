#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std ;

// the easy pissy cout of vector/sets/maps
void print(vector<double> &arr) {
    for (auto &&i : arr)
    {
        cout << i <<  " " ;
    }
    cout  << endl ;
}


// the easy pissy cout of vector/sets/maps
void print(set<int> &s) {
    for (auto &&i : s)
    {
        cout << i << "  " ;
    }
    cout << endl ;
    
}

// the easy pissy cout of vector/sets/maps
void print(map<int, double> &m) {
    for (auto &&i : m)
    {
        cout << i.second << "   " ;
    }
    cout << endl;
    
}

void vectorTuts() {
    cout << "== Vectors Tutorials ==\n" << endl ;
    
    // init vector
    vector<double> arr = {1,-2.66,2.1, -3.5,2,11,0,2 ,77,-9,4} ;
    print(arr);

    // sorting vectors
    sort(arr.begin(), arr.end()) ;
    print(arr);

    // performing binary_search
    bool present = binary_search(arr.begin(), arr.end(), -3.5);
    cout << "Item \'-3.5\' : "  << present << endl ;
    
    bool presenty = binary_search(arr.begin(), arr.end(), 2.1);
    cout << "Item \'2.1\' : "  << present << endl ;

    // pushing new elem in V_arr
    arr.push_back(56);
    print(arr);
}

void setTuts() {
    cout << "\n == Sets Tutorials == \n" << endl ;
    
    // init of set s
    set<int> s;

    // insertion of elems, in case random()
    s.insert(rand());
    s.insert(rand());
    s.insert(rand());
    s.insert(356);
    s.insert(rand());
    s.insert(rand());

    // printing the elems of the corresponding set
    print(s);


    // finding specific elem in elems of the corresponding set
    // set<datatype>::iterator => auto ;

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

void mapTuts() {
    cout << "\n == Mapping Tutorials == \n" << endl ;

    string x = "sounish nath" ;

    // init of a int_map::
    map<int, double> intMap;

    intMap[1] = 123;
    intMap[2] = 356;
    intMap[154] = 8090;

    print(intMap) ;

    map<char, int> charMap;
    
    for (auto &&i : x)
    {
        charMap[i] ++ ;
    }

    cout << charMap['o'] << endl ;
    

}


void giveMeTheInterval() {
    
    set<pair<int, int>> pairs ;
    pairs.insert({1,10});
    pairs.insert({11,100});
    pairs.insert({101,360});
    pairs.insert({370,10000});

    int find_point = 356 ;

    set<pair<int, int>>::iterator it = pairs.upper_bound({356, __INT_MAX__}) ;

    cout << it._M_node << endl ;

}

int main(int argc, char const *argv[])
{
    // vector coding
    vectorTuts();

    // set coding
    setTuts() ;
    
    // map coding
    mapTuts() ;
    
    giveMeTheInterval() ;
    
    return 0;
}
