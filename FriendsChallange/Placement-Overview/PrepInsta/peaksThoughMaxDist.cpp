#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

vector<int> v{5, 10, 5, 7, 3, 2, 4, 5};

bool isPeaks(int num, int prev, int forwd) {
    if ((prev >= 0 and v[prev] > num) or (forwd < v.size() and v[forwd] > num))
        return false;
    return true ;
}

bool isThrogh(int num, int prev, int forwd) {
    if ( (prev >= 0 and v[prev] < num) or (forwd < v.size() and v[forwd] < num ) )
        return false ;
    return true ;
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    int pD = 0, tD = 0;
    vector<int> peaks, throghs ;

    for (int i = 0; i < v.size() ; i++ ) {
        if (isPeaks(v[i], i-1, i+1)) {
            peaks.push_back(i) ;
        }
        if (isThrogh(v[i], i-1, i+1)){
            throghs.emplace_back(i) ;
        }
    }
    pD = abs(peaks[peaks.size()-1] - peaks[peaks.size()-2]);
    tD = abs(throghs[throghs.size()-1] - throghs[throghs.size()-2]);

    cout << max(pD, tD) << endl ;

    return 0;
}
