#include <bits/stdc++.h>
using namespace std;

int n = 4;
int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}};
int VISITED_ALL = (1 << n) - 1;

int tsp(int mask, int pos)
{

    if (mask == VISITED_ALL)
    {
        return dist[pos][0];
    }

    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
    {

        if ((mask & (1 << city)) == 0)
        {

            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return ans;
}

int main()
{
    clock_t t1 = clock() ;
    cout << "Travelling Saleman Distance is " << tsp(1, 0) << endl ;
    clock_t t2 = clock() ;

    cout << "function takes " << 1000.0*(t2-t1)/CLOCKS_PER_SEC << " millisec(s)";

    return 0;
}
