#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void mergeFreqSort(vector<int> &v, vector<int> &w)
{
    unordered_map<int, int> _unmp;

    for (auto &&i : v)
    {
        _unmp[i]++;
    }

    for (auto &&i : w)
    {
        if (_unmp.find(i) != _unmp.end())
        {
            unordered_map<int, int>::iterator itr = _unmp.find(i);
            for (int i = 0; i < itr->second; i++)
            {
                std::cout << itr->first << "  ";
            }
            _unmp.erase(itr);
        }
    };

    for (auto &&i : _unmp)
    {
        std::cout << i.first << "  ";
    }
}

int main(int argc, char const *argv[]) {
    vector<int> A{3, 6, 13, 3, 9, 10, 14, 6, 9, 13};
    vector<int> B{6, 3, 9, 13, 10};
    mergeFreqSort(A, B);
    return 0;
}
