#include<iostream>
using namespace std ;

void pascalRev(int n) {
    int count = 0 ;
            for (int i = -1; i < n-2; i++) {

            for (int j = n - i; j > 1; j--) {
                cout << (" ");
            }
            for (int j = 0; j <= i; j++) {
                cout << ("* ");
            }

            // ending line after each row
            cout << endl;
            count ++ ;
        }
            for (int i = count-1; i >=0; i--) {

            for (int j = n - i; j > 1; j--) {
                cout << (" ");
            }
            for (int j = 0; j <= i; j++) {
                cout << ("* ");
            }

            // ending line after each row
            cout << endl;
        }
  }


int main(int argc, char const *argv[])
{
    pascalRev(5);
    return 0;
}
