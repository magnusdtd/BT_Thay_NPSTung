#include <iostream>
using namespace std;

class Circle{
    double radius;
    double x, y;
public:
    Circle(double r = 1.0, double x = 0.0, double y = 0.0){
        radius = r;
        this->x = x;
        this->y = y;
    }
    double getRadius(){
        return radius;
    }
    void setRadius(double r){
        radius = r;
    }
    double getArea(){
        return 3.14 * radius * radius;
    }
    double getCircumference(){
        return 2 * 3.14 * radius;
    }
};

int main(){
    cout << "== INPUT RADIUS AND CENTRE I(x, y), OUTPUT AREA, CIRCUMFERENCE OF CIRCLE ==" << endl;
    double r;
    double x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << "Enter radius: ";
    cin >> r;
    Circle c(r);
    cout << "Area: " << c.getArea() << endl;
    cout << "Circumference: " << c.getCircumference() << endl;
    return 0;
}