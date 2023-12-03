// Nhap 3 diem toa do 3 dinh tam giac, tinh chu vi, dien tich, toa do trong tam
#include <iostream>
#include <math.h>
using namespace std;

struct Diem
{
    double x;
    double y;
};

struct TamGiac
{
    Diem a;
    Diem b;
    Diem c;
};

// dis = distance = khoang cach
double dis(Diem a, Diem b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool ktraTamGiac(TamGiac tg)
{
    double dis_a = dis(tg.a, tg.b);
    double dis_b = dis(tg.b, tg.c);
    double dis_c = dis(tg.c, tg.a);
    if ((dis_a + dis_b <= dis_c) || (dis_b + dis_c <= dis_a) || (dis_b + dis_c <= dis_a))
        return false;
    return true;
}

double chuVi(TamGiac tg)
{
    double dis_a = dis(tg.a, tg.b);
    double dis_b = dis(tg.b, tg.c);
    double dis_c = dis(tg.c, tg.a);
    return dis_a + dis_b + dis_c;
}

double dienTich(TamGiac tg)
{
    double p = chuVi(tg) / 2; // p = nua chu vi
    double dis_a = dis(tg.a, tg.b);
    double dis_b = dis(tg.b, tg.c);
    double dis_c = dis(tg.c, tg.a);
    return sqrt(p * (p - dis_a) * (p - dis_b) * (p - dis_c));
}

Diem toaDoG(TamGiac tg)
{
    Diem ans;
    ans.x = (tg.a.x + tg.b.x + tg.c.x) / 3;
    ans.y = (tg.a.y + tg.b.y + tg.c.y) / 3;
    return ans;
}

void input(TamGiac &tg)
{
    cout << "Nhap toa do dinh A: ";
    cin >> tg.a.x >> tg.a.y;
    cout << "Nhap toa do dinh B: ";
    cin >> tg.b.x >> tg.b.y;
    cout << "Nhap toa do dinh C: ";
    cin >> tg.c.x >> tg.c.y;
}

void xuatDiem(Diem a)
{
    cout << "Toa do x cua diem: ";
    cout << a.x;
    cout << endl;
    cout << "Toa do y cua diem: ";
    cout << a.y;
}

int main()
{
    TamGiac tg; // tg = tamgiac
    input(tg);
    if (!ktraTamGiac(tg))
    {
        cout << "Day khong phai la 1 tam giac";
        return 0;
    }
    cout << "Chu vi tam giac la: " << chuVi(tg) << endl;
    cout << "Dien tich tam giac la: " << dienTich(tg) << endl;
    cout << "Toa do trong tam cua tam giac la: " << endl;
    xuatDiem(toaDoG(tg));
    return 0;
}