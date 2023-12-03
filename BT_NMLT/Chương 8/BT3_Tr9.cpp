// Nhap gio:phut:giay -> gio tiep theo
#include <iostream>
using namespace std;

struct ThoiGian
{
    int gio;
    int phut;
    int giay;
};

void solve(ThoiGian &a)
{
    if (a.gio != 23)
    {
        a.gio += 1;
    }
    else
    {
        a.gio = 0;
    }
}

void input(ThoiGian &a)
{
    cout << "Nhap gio: ";
    cin >> a.gio;
    cout << "Nhap phut: ";
    cin >> a.phut;
    cout << "Nhap giay: ";
    cin >> a.giay;
}

void xuat(ThoiGian a)
{
    cout << "Gio tiep theo la " << a.gio << ":" << a.phut << ":" << a.giay;
}

int main()
{
    ThoiGian a;
    input(a);
    solve(a);
    xuat(a);
    return 0;
}