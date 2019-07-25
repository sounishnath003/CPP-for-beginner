#include<iostream>
using namespace std ;

class LengthOfStringPTR
{
private:
public:
    int stringLen(char *p) {
        int count = 0;
        while (*p != '\0')
        {
            count++;
            p ++ ;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    LengthOfStringPTR obj ;
    int r = obj.stringLen("123") ;
    cout << r << endl ;
    return 0;
}
