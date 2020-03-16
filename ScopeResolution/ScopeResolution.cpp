#include<iostream>
using namespace std ;

class ScopeResolution
{
private:

    /* data */
public:
   void pk();
};

void ScopeResolution::pk() {
    cout << "Hi User!" ;
}

int main(int argc, char const *argv[])
{
    ScopeResolution obj;
    obj.pk() ;
    return 0;
}



