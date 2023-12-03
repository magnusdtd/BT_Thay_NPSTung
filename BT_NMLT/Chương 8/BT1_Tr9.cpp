// Tối giản phân số
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return ((b == 0) ? a : gcd(b, a % b));
}

struct PhanSo
{
    int tuSo;
    int mauSo;
};

PhanSo Plus(PhanSo a, PhanSo b)
{
    PhanSo ans;
    ans.tuSo = a.tuSo * b.mauSo + a.mauSo * b.tuSo;
    ans.mauSo = a.mauSo * b.mauSo;
    return ans;
}

PhanSo shorted(PhanSo a)
{
    PhanSo ans;
    ans.tuSo = a.tuSo / gcd(a.tuSo, a.mauSo);
    ans.mauSo = a.mauSo / gcd(a.tuSo, a.mauSo);
    return ans;
}

void input(PhanSo &a)
{
    cout << "Nhap tu so: ";
    cin >> a.tuSo;
    cout << "Nhap mau so: ";
    cin >> a.mauSo;
}

void xuat(PhanSo a)
{
    cout << "Tu so cua phan so tong la " << a.tuSo << endl;
    cout << "Mau so cua phan so tong la " << a.mauSo << endl;
}

int main()
{
    PhanSo a, b;
    cout << "Nhap phan so thu 1" << endl;
    input(a);
    cout << "Nhap phan so thu 2" << endl;
    input(b);
    PhanSo ans = Plus(a, b);
    ans = shorted(ans);
    xuat(ans);
    return 0;
}