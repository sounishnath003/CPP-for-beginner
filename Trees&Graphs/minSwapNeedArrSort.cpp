#include<iostream>
#include<bits/stdc++.h>
#define fo(i, n) for(int i=0; i<n;i++)
#define deb(x) cout << #x << "  " << x << endl 

using namespace std ;


void minSwaps(int arr[], int &size){
    int ans = 0 ;

    pair<int, int> arrPos[size] ;

    fo(i, size){
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    sort(arrPos, arrPos+size) ;

    vector<bool> vis(size, false) ;

    fo(i, size) {
        if (vis[i] || arrPos[i].second == i) continue ;

        int j = i ;
        int count = 0 ;

        while(!vis[j]) {
            vis[j] = 1 ;
            j = arrPos[j].second ; 
            count++ ;
        }

        if (count > 0 ) {
            ans += count-1 ;
        }
    }

    cout << "swaps -> " << ans << endl ;
}


int main(int argc, char const *argv[])
{
    int arr[] = {1,2,-5,7,3,0} ;
    int size = (sizeof(arr) / sizeof(int)); 
    minSwaps(arr, size) ;
    return 0;
}
