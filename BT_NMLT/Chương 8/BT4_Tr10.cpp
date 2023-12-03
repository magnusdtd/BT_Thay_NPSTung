// Nhap toa do 2 diem, tinh khoang cach 2 diem
#include <iostream>
#include <math.h>
using namespace std;

struct Diem
{
    double x;
    double y;
};

double dis(Diem a, Diem b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void input(Diem &a)
{
    cout << "Nhap toa do x: ";
    cin >> a.x;
    cout << "Nhap toa do y: ";
    cin >> a.y;
}

int main()
{
    Diem a, b;
    cout << "Nhap diem thu 1" << endl;
    input(a);
    cout << "Nhap diem thu 2" << endl;
    input(b);
    double ans = dis(a, b);
    cout << "Khoang cach cua 2 diem la " << ans;
    return 0;
}