#include<bits/stdc++.h>
using namespace std ;

// 7 - 17
// [ {8, 10}, {12, 15} ]
// [ {10, 11}, {14, 16} ]

// => [{7, 8}, {11, 12}, {16, 17}]

pair<int, int> allDayLimit{7, 17} ;
// vector<pair<int, int>> t1{
//     {12, 15},
//     {8, 10}
// };
// vector<pair<int, int>> t2{
//     {10, 11},
//     {14, 16}
// };
vector<pair<int, int>> t1{
    {9, 10},
    {12, 13},
    {14, 16}
};
vector<pair<int, int>> t2{
    {8, 10},
    {13, 15}
};
void _printOneTable(vector<pair<int, int>> &t1){
    std::cout << "print timetable " << std::endl;
    for (auto &&i : t1) {
        std::cout << i.first << " - " << i.second << std::endl;
    }
}

void _timeTable(vector<pair<int, int>> &t1, vector<pair<int, int>> &t2, pair<int, int> allDayLimit) {
    sort(t1.begin(), t1.end(), [](pair<int, int > a, pair<int, int> b) {return a.first < b.second ;}) ;
    sort(t2.begin(), t2.end(), [](pair<int, int > a, pair<int, int> b) {return a.first < b.second ;}) ;

    // resultant new sessions
    vector<pair<int, int>> resultantTimes;

    // sorted & merged combainedList
    vector<pair<int, int>> combainedList((t1.size() + t2.size()), make_pair(0, 0));
    merge(begin(t1), end(t1), begin(t2), end(t2), begin(combainedList)) ;
    
    int secondTime = allDayLimit.second ;

    // checking for new session
    if (1 && (allDayLimit.first < combainedList[0].first)){
        pair<int, int> _tempStoreSession(make_pair(allDayLimit.first, combainedList[0].first));
        resultantTimes.push_back(_tempStoreSession);
        allDayLimit.first = combainedList[0].second;
        _tempStoreSession = {0, 0};
    }
    for (int i = 1; i < combainedList.size() ; i++) {
        if((combainedList[i].second < combainedList[i + 1].first)) {
            pair<int, int> _ttmpSession(make_pair(combainedList[i].second, combainedList[i+1].first)) ;
            resultantTimes.push_back(_ttmpSession) ;
            _ttmpSession = {0,0} ;
        }

        if (i == (combainedList.size() -1)) {
            if (combainedList[i].second < secondTime) {
                resultantTimes.push_back(make_pair(combainedList[i].second, secondTime)) ;
            }
        }
    }

    // printing resultant sessions
    _printOneTable(resultantTimes) ;
}

int main(int argc, char const *argv[]) {
    
    _timeTable(t1, t2, allDayLimit) ;
    return 0;
}
