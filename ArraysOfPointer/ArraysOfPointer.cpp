#include<iostream>
using namespace std ;

class ArraysOfPointer
{
private:
 /* data */

public:
    void createArr(double arr[], int n) {
        for (size_t i = 0; i < n; i++)
        {
            arr[i] = rand();
        }
    }

    void prntArr(double arr[], int n) {
        for (size_t i = 0; i < n; i++)
        {
            cout << arr[i] << endl ;
        }
        
    }
};


int main(int argc, char const *argv[])
{
    double arr[6], n = 6 ;
    double *parr[6];
    ArraysOfPointer obj ;
    obj.createArr(arr, n);
    obj.prntArr(arr, n) ;

    cout << "\n\n == Arrays of pointer == \n\n" << endl ;

    for (size_t i = 0; i < n; i++)
    {
        parr[i] = &arr[i] ;
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << endl ;
    }
    
    
    return 0;
}

