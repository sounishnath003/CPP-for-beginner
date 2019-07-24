#include<iostream>
using namespace std ;

class AreaOfFigures
{
protected:
    int height ;
    int width ;
public:
    void setHeightWidth(double h, double w){
        height = h ;
        width = w ;
    }

    virtual int getArea() = 0 ;
};

class Triangle: public AreaOfFigures
{
private:
    
public:
    int getArea() {
        return (width * height)/2;
    }
};

int main(int argc, char const *argv[])
{
    Triangle obj;
    obj.setHeightWidth(110, 10) ;
    int a = obj.getArea();
    cout << a << endl ;
    return 0;
}
