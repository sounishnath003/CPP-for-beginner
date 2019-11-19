#include<iostream>
using namespace std ;


// template<typename... T>
// void print(T&... args){
//     ((cout << args << " "), ...);
// }


template<typename... T>
void print(T&... args) {
    ((cout << args << " "),...) ;
}

int main(int argc, char const *argv[])
{
    int a = 45, b = -4655, as = 4565621230;
    string c = "Sounish";
    print(a,b,c, "Hi User", as);
    return 0;
}
