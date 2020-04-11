#include<iostream>
#include<bits/stdc++.h>
#define deb(x) cout << #x << "  " << x << endl 

using namespace std ;

string mainStr = "Hello Google" ;
string replacingWord = "Hello" ;
string replaceBy = "Podmarrr" ;

void replaceMent(string &mainStr, string &replacingWord, string &replaceBy) {
    deb(mainStr) ;
    mainStr.replace(mainStr.find(replacingWord), replacingWord.length(), replaceBy);
    deb(mainStr) ;
}


int main(int argc, char const *argv[])
{
    replaceMent(mainStr, replacingWord, replaceBy) ;
    return 0;
}

