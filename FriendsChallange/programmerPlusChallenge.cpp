#include <bits/stdc++.h>
using namespace std;

// challange 1
inline int factorial(int x)
{
    if (x <= 0)
    {
        return 1;
    }
    return x * factorial(x - 1);
}

void fiboncciSequence(int X)
{
    long double sum = 0;
    for (size_t i = 0; i <= X; i++)
    {
        if (i & 1)
        {
            sum += pow(-1, i) * (pow(X, i) / factorial(i));
        }
    }

    cout << sum << endl;
}

// challenge 2
// 1, 5, 3, 4, 3.5

double mean(double &a, double &b)
{
    return ((double)((a + b) / 2));
}

void _secondChallenge(int N)
{
    vector<double> v{1, 5};

    for (size_t i = 2; i <= N; i++)
    {
        v.push_back(mean(v[i - 2], v[i - 1]));
    }

    for (auto &&i : v)
    {
        std::cout << i << "    ";
    }
    std::cout << std::endl;
}

// challenge 4

void _incresedSequenceLetter(string str)
{
    string r = "";
    for (size_t i = 1; i < str.length(); i++)
    {
        if (((str[i] - '0') - (str[i - 1] - '0')) >= 1)
        {
            r.push_back((char)((str[i] - 1)));
        }
    }
    std::cout << r << std::endl;
}

// challenge 5

void _thirdLongest(vector<string> &v)
{
    sort(begin(v), end(v), greater<string>());
    std::cout << v[2] << std::endl;
}

// challenge 6

int _isPrime(int Nth)
{
    bool tt = true;
    for (int i = 2; i <= (int)(Nth / 2); ++i)
    {
        if (Nth % i == 0)
        {
            tt = false;
            break;
        }
    }
    if (tt)
        return Nth;
}

void NthPrime(int n)
{
    vector<int> v;
    for (int i = 1; i <= n * 4; i++)
    {
        if (_isPrime(i) != 0)
        {
            v.push_back(_isPrime(i));
        }
    }

    std::cout << v[n - 1] << std::endl;
}

int main(int argc, char const *argv[])
{
    _incresedSequenceLetter("acg");
    return 0;
}
