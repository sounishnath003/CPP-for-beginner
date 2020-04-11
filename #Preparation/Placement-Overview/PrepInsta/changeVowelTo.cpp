#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    string str ("Please, replace the vowels in this sentence by asterisks.");
    int found = str.find_first_of("aeiou")     ;

    while(found != string::npos) {
        str[found] =  '*';
        found = str.find_first_of("aeiou", found+1);
    }

    cout << str << endl ;
    return 0;
}
