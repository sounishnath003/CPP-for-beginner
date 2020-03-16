#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

vector<int> datas = {1,20,1,0,50,8,80,8,84,5,15,77} ;

void reversse(vector<int> &datas) {
    reverse(datas.begin(), datas.end()) ;
    for (auto &&i : datas)
    {
        cout << i << "  " ;
    }
    cout << endl ;
    
}

int main(int argc, char const *argv[])
{
    reversse(datas) ;
    return 0;
}
