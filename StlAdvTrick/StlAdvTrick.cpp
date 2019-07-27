#include<iostream>
#include<vector>
using namespace std ;

int main(int argc, char const *argv[])
{
    auto arr = {1,2,3,5,2,11,0,2 ,77,-9,4} ;
    
    for (auto &&i : arr)
    {
        cout << i <<  " " ;
    }
    cout << endl ;
    
    return 0;
}
