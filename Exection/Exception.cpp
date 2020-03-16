#include<iostream>
#include<string>
using namespace std ;


int main(int argc, char const *argv[])
{
    try
    {
        throw(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
