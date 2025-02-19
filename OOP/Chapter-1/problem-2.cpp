#include <iostream>
#include <math.h>
using namespace std;

class Point{
    double x, y;
public: 
    Point(double x, double y) : x(x), y(y) {}
    double distanceTo(Point p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

int main() {
    int x1, y1, x2, y2;
    cout << "== INPUT 2 POINTS, OUTPUT ITS DISTANCE ==" << "\n";
    cout << "Enter 2 points: ";
    cin >> x1 >> y1 >> x2 >> y2;
    Point p1(x1, y1), p2(x2, y2);
    cout << "Distance of two point: " << p1.distanceTo(p2) << "\n";
}