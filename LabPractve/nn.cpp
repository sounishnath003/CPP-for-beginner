#include<iostream>
#include<bits/stdc++.h>

using namespace std ;


vector<int> v = {1,0,5,55,-8,44,-7,51,-78} ;

int vv[]{1, 0, 5, 55, -8, 44, -7, 51, -78};

void bubblesort(vector<int> &v) {
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        for(size_t j = 0; j<= v.size()-i-1; j++) {
            if (v[j] > v[j+1]) {
                swap(v[j], v[j+1]) ;
            }

        }
    }

    for (auto &&i : v)
    {
        std::cout << i << "  " ;
    }
    
    std::cout << std::endl ;
    
}

void insertion(vector<int> &v) {
    for(int i  = 0; i< v.size(); i++) {
        for(int j = i+1; j>0; j--) {
            if(v[j] < v[j-1]) {
                // swap(v[j], v[j-1]) ;
                v[j] ^= v[j-1];
                v[j-1] ^= v[j];
                v[j] ^= v[j-1];
            }
        }
    }

    for (auto &&i : v)
    {
        std::cout << i << "  ";
    }cout<<endl ;
}



int compare(void const* a, void const* b) {
    return (*(int*) a - *(int*)b) ;
}


void selectionsort(vector<int> &v) {
    for(int i = 0 ; i< v.size() ; i++) {
        int minI = i ;
        for(int j = i+1 ; j < v.size(); j++) {
            if(v[j] < v[minI]) {
                minI = j ;
            }

            swap(v[i], v[minI]) ;
        }
    }

    for (auto &&i : v)
        {
            std::cout << i << "  " ;
        }std::cout << std::endl ;
}

int main(int argc, char const *argv[])
{
    bubblesort(v) ;

    insertion(v) ;


    qsort(vv, v.size(), sizeof(int), compare) ;

    for (auto &&i : v)
        {
            std::cout << i << "  " ;
        }std::cout << std::endl ;

    selectionsort(v) ;
    
    return 0;
}
