#include<iostream>
#include<vector>
using namespace std ;

template<typename T>
void printVector(vector<T> n) {
    for (auto &&i : n)
    {
        cout << i << "  ";
    }
    cout << endl ;
    
}

class Fibonacci
{
private:
    double series = 0;
    vector<double> store;
public:
    void getTheFibonacciUpto(int x) {
        int a = 0, b = 1;
        for (size_t i = 1; i <= x; i++)
        {
            store.push_back(series);
            series = a + b;
            a = b;
            b = series;
        }
        printVector(store);
    }

};

int main(int argc, char const *argv[])
{
    Fibonacci obj ;
    obj.getTheFibonacciUpto(20);
    return 0;
}
