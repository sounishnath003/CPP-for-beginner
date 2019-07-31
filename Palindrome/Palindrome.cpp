#include<iostream>
#include<string>
using namespace std ;

class Palindrome
{
private:
    /* data */
public:
    template<typename T>
    void isPalindrome(T n) {
        T res =0 , tem = n;
        while (n!=0)
        {
            res = res*10 + n%10;
            n = n/10;
        }
        cout << tem << "    " ;
        if (tem==res) {
            cout << "Palindrome" << endl;
        }else {
            cout << "not Palindrome" << endl;
        }
    }

    // overloaded function for string
    void isPalindrome(string str) {
        int low = 0, high = str.length() -1 ;
        while(high > low) {
            if (str[low++] != str[high--]){
                cout << str << " is not Palindrome" << endl;
                return ;
            }
        }
        cout << str << " Palindrome" ;
    }
};

int main(int argc, char const *argv[])
{
    Palindrome obj;string c = "aba";
    obj.isPalindrome(123321);
    obj.isPalindrome(646);
    obj.isPalindrome(786);
    obj.isPalindrome(c);
    return 0;
}

