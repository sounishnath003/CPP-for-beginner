#include<iostream>

using namespace std ;

template<typename... T>
void print(T&... args){
    ((cout << args << endl), ...);
}

class SingleInheritence
{
protected:
    int a, b;
public:
    SingleInheritence() {
        print("Base class Initiated");
    }
};

class Child : public SingleInheritence
{
private:
    int c;
public:
    Child() {
        this->a = 0;
        this->c = 0;
        this->b = 0;
        
        print("Child base Initiated");
    }

    Child(int a, int b){
        this->a = a;
        this->b = b;
        print("Child base Initiated");
    }

    void sum() {
        this->c = this->a + this-> b ;
        print("sum is: ", c);
    }
};



int main(int argc, char const *argv[])
{
    Child obj(10,15);
    obj.sum();
    return 0;
}
