#include<iostream>

using namespace std ;

class First
{
protected:
    int data ;
public:
    First() {
        cout << "Base class"<< endl;
    }
};

class Second : public First
{
private:
    
public:
    Second() {
        this->data = NULL;
        cout << data << endl;
    }
};

class Third : public Second
{
private:
    
public:
    Third(){}
    Third(int data) {
        this->data = data;
    }

    void disp() {
        cout << data << endl;
    }
};

int main(int argc, char const *argv[])
{
    Third ob(56);
    ob.disp();

    Third o;
    o.disp();
    return 0;
}
