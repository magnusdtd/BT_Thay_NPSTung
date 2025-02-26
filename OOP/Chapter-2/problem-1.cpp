#include <iostream>
using namespace std;

#define PI 3.14159265354

class Circle{
    double radius;
    double x, y;
public:
    Circle(double r = 1.0, double x = 0.0, double y = 0.0) : radius(r), x(x), y(y) {}
    double getRadius() const { return radius; }
    void setRadius(double r) { radius = r; }
    double getArea() const { return PI * radius * radius; }
    double getCircumference() const { return 2 * PI * radius; }
};

int main(){
    cout << "== INPUT RADIUS AND CENTRE I(x, y), OUTPUT AREA, CIRCUMFERENCE OF CIRCLE ==" << "\n";
    double r, x, y;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter y: ";
    cin >> y;

    cout << "Enter radius: ";
    cin >> r;
    
    Circle c(r);
    cout << "Area: " << c.getArea() << "\n";
    cout << "Circumference: " << c.getCircumference() << "\n";

}