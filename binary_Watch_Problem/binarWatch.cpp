#include <bits/stdc++.h>
using namespace std;

// problem 1
void binaryWatch(int &n)
{
    for (int hour = 0; hour < 12; hour++)
    {
        for (int minute = 0; minute < 60; minute++)
        {
            bitset<8> h(hour);
            bitset<8> m(minute);
            int set_hour_bit = h.count();
            int set_minute_bit = m.count();
            if (set_hour_bit + set_minute_bit == n)
            {
                char buffer[100];
                sprintf(buffer, "%d:%.02d", hour, minute);
                std::cout << buffer << "  ";
            }
        }
    }
}

int main(int argc, char const *argv[]){
    
    int n = 1 ;
    binaryWatch(n) ;
    return 0;
}

