/*
Trong
mặt phẳng Oxy cho tọa độ 3 đỉnh của tam giác
ABC Viết chương trình nhập vào tam giác ABC Tính
Chu Vi, Diện Tích và tọa độ trọng tâm của tam giác ABC
*/
#include <iostream>
#include <math.h>
using namespace std;

class Point {
private:
    double x, y;
public:
    Point();
    Point(double x, double y);
    friend class Triangle;
    friend double getDistance(Point A, Point B);
    friend ostream& operator<<(std::ostream& os, const Point& p);
};

Point::Point() {
    x = 0, y = 0;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

double getDistance(Point A, Point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

class Triangle {
private:
    Point A, B, C;
public:
    Triangle();
    Triangle(Point A, Point B, Point C);
    double getCircumference();
    double getArea();
    Point getCentroid();
};

Triangle::Triangle() {}

Triangle::Triangle(Point A, Point B, Point C): A(A), B(B), C(C) {}

double Triangle::getCircumference() {
    return 2 * (getDistance(A, B) + getDistance(B, C) + getDistance(C, A));
}

double Triangle::getArea() {
    return 0.5 * abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

Point Triangle::getCentroid() {
    return Point((A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3);
}

int main() {
    int xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA >> xB >> yB >> xC >> yC;
    Triangle ABC(Point(xA, yA), Point(xB, yB), Point(xC, yC));

    cout << ABC.getCircumference() << "\n";
    cout << ABC.getArea() << "\n";
    cout << ABC.getCentroid() << "\n";
}
