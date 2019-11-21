#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

vector<int> v ={1,4,-9,44,-8,55,77} ;


void bubblesort(vector<int> &v) {
    for(int i = 0 ;i < v.size() -1 ; i++) {
        for(int j = 0; j < v.size() -i -1; j++) {
            if (v[j+1] < v[j]) {
                swap(v[j], v[j+1]) ;
            }
        }
    }

    for (auto &&i : v)
        {
            std::cout << i << "  " ;
        }std::cout << std::endl ;
}

void insertionsort(vector<int> &v) {
    for(int i = 0 ; i< v.size() -1 ; i++) {
        for(int j = i+1; j > 0 ; j--) {
            if (v[j] < v[j-1]) {
                swap(v[j], v[j-1]) ;
            }
        }
    }

    for (auto &&i : v)
        {
            std::cout << i << "  " ;
        }std::cout << std::endl ;
}

void selectionsort(vector<int> &v) {
    for(int i = 0 ; i< v.size() ; i++ ) {
        int minI = i ;
        for(int j = i + 1; j< v.size() ; j++)  {
            if (v[minI] > v[j]) {
                swap(minI, j) ;
            }
        }
        swap(v[i], v[minI]) ;
    }

    for (auto &&i : v)
        {
            std::cout << i << "  " ;
        }std::cout << std::endl ;
}


int main(int argc, char const *argv[])
{
    selectionsort(v) ;
    bubblesort(v) ;
    insertionsort(v) ;
    return 0;
}
