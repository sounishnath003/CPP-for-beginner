#include <bits/stdc++.h>
#define deb(x)                          \
    {                                   \
        cout << #x << " " << x << endl; \
    }
using namespace std;

void _possibleOrNot(vector<int> &_TAs, int &_XAmmount)
{
    int c_sum = _TAs[0], start = 0;
    bool _isTrue = false;
    for (int i = 1; i < _TAs.size(); i++)
    {
        while (c_sum > _XAmmount)
        {
            c_sum -= _TAs[start];
            start++;
        }
        if (c_sum == _XAmmount)
        {
            _isTrue = true;
        }
        c_sum += _TAs[i];
    }
    if (_isTrue)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << endl;
    }
}
int main(int argc, char const *argv[]){
    
    vector<vector<int>> _tas ;
    int testcaseNO ;
    cin >> testcaseNO ;

    vector<int> _tasSize, ammount ;
    for(int i =0 ; i< testcaseNO ; i++) {
        int _TmptasSize, _TmpAmmount ;
        cin >> _TmptasSize >> _TmpAmmount ;
        _tasSize.push_back(_TmptasSize); 
        ammount.push_back(_TmpAmmount) ;
        int _valueTas ; vector<int> _tasTemp(_tasSize) ;
        for(int i = 0; i< _TmptasSize; i++) {
            cin >> _valueTas ;
            _tasTemp.push_back(_valueTas) ;
        }
        _tas.push_back(_tasTemp) ;
    }

    for(int i = 0 ;i < testcaseNO; i++) {
        _possibleOrNot(_tas[i], ammount[i]) ;
    }

    return 0;
}
