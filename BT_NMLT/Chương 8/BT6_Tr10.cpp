// Nhap toa do tam va ban kinh, tra ve chu vi dien tich
#include <iostream>
#include <math.h>
using namespace std;

struct Diem
{
    double x;
    double y;
};

struct DuongTron
{
    Diem tam;
    double bankinh;
};

double chuVi(DuongTron dt)
{
    return dt.bankinh * 2 * 3.14;
}

double dienTich(DuongTron dt)
{
    return dt.bankinh * dt.bankinh * 3.14;
}

void input(DuongTron &dt)
{
    cout << "Nhap toa do tam: ";
    cin >> dt.tam.x >> dt.tam.y;
    cout << "Nhap ban kinh duong tron: ";
    cin >> dt.bankinh;
}

int main()
{
    DuongTron dt; // dt = duong tron
    input(dt);
    cout << "Duong tron nhap vao co tam la "
         << "(" << dt.tam.x << ", " << dt.tam.y << ")" << endl;
    cout << "Chu vi cua duong tron la: " << chuVi(dt) << endl;
    cout << "Dien tich cua duong tron la: " << dienTich(dt);
    return 0;
}