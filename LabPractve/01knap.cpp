#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

vector<int> weight = {10,25,35} ;
vector<int> value = {60,100,120} ;
int capacity = 50 ;

int knapsack(int capacity, vector<int> &weight, vector<int> &value , int n)  {
    int maxProft = 0 ;

    if (n <= 0 or capacity == 0) {
        return 0 ;
    }

    if (weight[n-1] > capacity) {
        return knapsack(capacity, weight, value, n-1) ;
    }

    return max( value[n-1] + knapsack(capacity - weight[n-1], weight, value, n-1), 
        knapsack(capacity, weight , value, n-1) 
     ) ;
}



int main(int argc, char const *argv[])
{
    cout << knapsack(capacity, weight, value, 3) << endl ;
    return 0;
}
