#include<bits/stdc++.h>

using namespace std ;

inline int _sumOfFactors(int num1){
    int sum1 = 0;
    for(int i = 1; i<= (int)num1/2; i++) {
        if(num1 % i == 0) {
            sum1 = sum1 + i ;
        }
    }
    return sum1;
}


void _isAmicable(int num1, int num2) {
    int sum1, sum2 ;
    sum1 = sum2 = 0 ;
    
    sum1 = _sumOfFactors(num1);
    sum2 = _sumOfFactors(num2);

    if(num1 == sum2 and num2 == sum1){
        cout << "pair of amicable numbers " << num1 << ", " << num2 ;
    }else {
        cout << "unfortunately numbers are not amicable to each other!!" << endl ;
    }
}

void _amicableRange(int range) {
    bool amicable = false ;
    for(int i = 2000; i<= range; i++) {
        for(int j = range ; j >= 1; j--){
            if ((_sumOfFactors(i) == j) and (_sumOfFactors(j) == i) and (_sumOfFactors(i) != _sumOfFactors(j)) and (i != j)) {
                cout << i << ", " << j << endl ;
            }
        }
    }
}


bool _regexMartch(const string str){
    static regex e("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}");
    return regex_match(str, e);
}

void _checkIp(string str) {
    if(_regexMartch(str)){
        std::cout << str << " its an ip" << std::endl ;
    }else {
        std::cout << str << " not an ip" << std::endl ;
    }
}

int main(int argc, char const *argv[])
{
    _checkIp("127.0.89.1") ;
    return 0;
}

