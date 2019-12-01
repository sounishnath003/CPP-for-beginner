#include<iostream>
#include<bits/stdc++.h>

using namespace std ;


long X = 28415 ;
int l = 6 ;

unordered_map<int, bool> unop ;

// template <typename T>
// ostream &operator<<(ostream &os, const vector<T> &v)
// {
//     os << "[";
//     for (int i = 0; i < v.size(); ++i)
//     {
//         os << v[i];
//         if (i != v.size() - 1)
//             os << ", ";
//     }
//     os << "]\n";
//     return os;
// }

vector<int> _splitupDigs(int num) {
    vector<int> _strVectr ; 
    while (num > 0) {
        int rme = 0 ;
        int rm = num / 10 ;
        _strVectr.push_back(rm) ;
        rme = rme * 10 + rm ;
        num/= 10 ;
    }
    return _strVectr ;
}

bool hasDisntDigs(vector<int> _v) {
    int count = 0 ;

    vector<int> _tmpCpy  = _v;

    for (auto &&i : _v)
    {
        if (unop.find(i) == unop.end()) {
            count ++ ;
        }
        unop[i] = true ;
    }

    if (count >= 4) {
        return true;
    }
    
}


int _calNoDigits(int digits){
    int k;
    return  (k = (int)log10(digits) + 1);
}

void getmultiple(long x, int l) {
    vector<int>  _strmultiple ;
    static int counttt = 0;

    for(int i = 1; i< 9999; i++) {
        _strmultiple.push_back(x * i) ;
    }

    for (auto &&i : _strmultiple)
        {
            if (_calNoDigits(i) == l){
                int _tmpI = i ;
                vector<int> _temop = _splitupDigs(i) ;
                if (hasDisntDigs(_temop)){
                    counttt ++ ;
                    // std::cout << _tmpI << std::endl ;
                }
            }
        }std::cout << std::endl ;
        std::cout << "total solutions --> " << counttt << std::endl;
}



int main(int argc, char const *argv[])
{
    getmultiple(X, l) ;
    
    return 0;
}
