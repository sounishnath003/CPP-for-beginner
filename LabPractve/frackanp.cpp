#include<iostream>
#include<bits/stdc++.h>

using namespace std ;


vector<int> weights = {10,20,30} ;
vector<int> values = {60,40,120} ;
int capacity =  50 ; 


int getoptimalIndex(vector<int> &weights, vector<int> &values) {
    int indx = 0;
    double max = 0.0 ;

    for(int i = 0; i< weights.size(); i++) {
        if (weights[i] != 0 and (double)values[i]/weights[i] > max ){
            max = (double)values[i]/weights[i] ;
            indx  = i ;
        }
    }
    return indx ;
}


void getoptimalvalue(int capacity, vector<int> &weights, vector<int> &values) {
    double maxProfit = 0;

    for(int i = 0; i < weights.size(); i++) {
        int index = getoptimalIndex(weights, values) ;
        int a = std::min(capacity, weights[index]) ;
        maxProfit += a * (double)values[index]/weights[index] ;
        weights[index] -= a ;
        capacity -= a ;
    }

    std::cout << "max profit " << maxProfit << std::endl ;
}


void fknapsack(int capacity, vector<int> &weights, vector<int> &values) {
    getoptimalvalue(capacity, weights, values) ;
}


int knapsack(int capacity, vector<int> &weights, vector<int> &values, int n) {
    if (capacity == 0 or n <= 0) {
        return 0;
    }
    if (weights[n-1] > capacity) {
        return knapsack(capacity, weights, values, n-1) ;
    }

    return std::max( values[n-1] + knapsack(capacity - weights[n-1], weights, values, n-1),
        knapsack(capacity, weights, values, n-1)
     ) ;
}



int main(int argc, char const *argv[]){
    fknapsack(capacity, weights, values ) ;

    std::cout << knapsack(capacity, weights, values, weights.size() ) << std::endl ;
    return 0;
}
