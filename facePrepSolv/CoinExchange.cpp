#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

int main(int argc, char const *argv[])
{
    int M = 10, N = 5 ;
    
    int *coin = new int[M] ;
    int *change = new int[N] ;

    std::cout << "enter coins -> " << std::endl ;
    for (size_t i = 0; i < M; i++)
    {
        cin >> coin[i] ;
    }

    memset(change, 0, sizeof(change)) ;

    change[0] = 1 ;

    for (int i = 0; i < M; i++)
    {
        for (int j = coin[i]; j <= N; j++)
        {
            change[j] += change[j - coin[i]];
        }
    }

    std::cout << "change will be " << std::endl ;
    std::cout << change[N] << std::endl ;

    return 0;
}
