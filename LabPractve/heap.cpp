#include<bits/stdc++.h>
#include<stdio.h>

using namespace std ;

int compare(void const* a, void const *b) {
    return (*(int*)a - *(int*)b) ;
}


int bisear(vector<int> &v, int lo, int hi, int key) {
    if (lo == hi or lo > hi ){
        return 0 ;
    }

    int mid = (lo+hi) / 2 ;

    if (v[mid] == key) {
        return mid ;
    }
    if (v[mid] > key) {
        return bisear(v, lo, mid-1, key) ;
    }else {
        return bisear(v, mid, hi, key) ;
    }

    return -1 ;
}

int main(int argc, char const *argv[])
{
    vector<int> v{1,2,0,8,7,1,0,-9,11,-88,-7} ;

    int vv[] = { 1,
                 2,
                 0,
                 8,
                 7,
                 1,
                 0,
                 -9,
                 11,
                 -88,
                 -7 };



    for (auto &&i : v)
    {
        std::cout << i << "  ";
        }std::cout << std::endl ;

    make_heap(begin(v), end(v)) ;

    for (auto &&i : v)
        {
            std::cout << i << "  " ;
        }std::cout << std::endl ;


    sort_heap(begin(v), end(v)) ;

    for (auto &&i : v)
        {
            std::cout << i << "  " ;
        }std::cout << std::endl ;



    qsort(vv, (sizeof(vv)/sizeof(vv[0])), sizeof(int), compare) ;

    bool pre = binary_search(begin(v), end(v), 8);

    for (auto &&i : v)
        {
            std::cout << i << "  " ;
        }std::cout << std::endl ;


     if(pre) {
        std::cout << "found " << pre << std::endl ;
    }

    cout << bisear(v, 0, v.size()-1, 0) ;

    return 0;
}
