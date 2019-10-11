#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

void prtLCS(vector<vector<char>>&S, string& X, int i, int j) {
  if(i == 0 || j==0 ){
      return ;
  }
  if ('s' == S[i][j]){
      prtLCS(S,X,i-1,j-1);
      cout << X[i] ;
  }else if('j' == S[i][j] ) {
      prtLCS(S,X,i, j-1);
  }else {
      prtLCS(S,X,i-1, j);
  }
}

void findLongestCommonSquence(string &X, string &Y) {
    vector<vector<int>> C ;
    vector<vector<char>> S ;
    for (size_t i = 0; i < X.size(); i++)
    {
        C.push_back(vector<int>(Y.size(), 0)) ;
        S.push_back(vector<char>(Y.size(), 0)) ;
    }

    for (size_t i = 1; i < X.size(); i++)
    {
        for(int j = 1; j<Y.size(); j++) {
            if (X[i] == Y[j]) {
                C[i][j] = C[i-1][j-1] + 1 ;
                S[i][j] = 's' ;
            }else if(C[i][j-1] >  C[i-1][j]){
                C[i][j] = C[i][j-1] ;
                S[i][j] = 'j' ;
            }else {
                S[i][j] = 'i' ;
                C[i][j] = C[i-1][j] ;
            }
        }
    }

    for (auto &&i : C)
    {
        for (auto &&j : i)
        {
            cout << j << "  ";
        }cout<< endl ;
    }
    
    prtLCS(S, X, X.size()-1, Y.size()-1);
    
    
}

int main(int argc, char const *argv[])
{
    string X = "AGCTACGSAGGCAACCGGAGCAS";
    string Y = "AGCTAGGCGCAAGCAGGGAACACGGAGCAS";

    findLongestCommonSquence(X, Y) ;

    return 0;
}
