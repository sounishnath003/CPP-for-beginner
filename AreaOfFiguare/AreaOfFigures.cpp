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

class Rectangle: public AreaOfFigures
{
private:
    
public:
    int getArea() {
        return (width * height);
    }
};

int main(int argc, char const *argv[])
{
    Triangle tri;
    tri.setHeightWidth(110, 10) ;
    int a = tri.getArea();
    cout << "Triangle area " << a << endl ;

    Rectangle rect ;
    rect.setHeightWidth(20, 30 );
    a = rect.getArea();
    cout << "Rectangle area " << a << endl ;
    return 0;
}
