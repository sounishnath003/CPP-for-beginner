#include<iostream>
#include<bits/stdc++.h>
#define deb(x) cout << #x << " " << x << endl

using namespace std ;

vector<int> myVec{1,2,3,4,1,2,3};

void equiIndexValue(vector<int> &myVec) {
    int sum = 0, leftSum = 0 ;
    
    sum = accumulate(myVec.begin(), myVec.end(), 0) ;

    for (auto &&j : myVec)
    {
        sum -= j ;
        // deb(sum) ;

        if (leftSum == sum) {
            cout << "equibilium index value: " << j << endl ;
        }

        leftSum += j ;
        // deb(leftSum) ;
    }

}

int main(int argc, char const *argv[])
{
    equiIndexValue(myVec) ;
    return 0;
}
