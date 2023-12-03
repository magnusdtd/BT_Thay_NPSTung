// Nhap vao ngay/thang/nam, ktra nam nhuan
#include <iostream>
using namespace std;

struct Ngay
{
    int ngay;
    int thang;
    int nam;
};

bool namNhuan(Ngay a)
{
    if (a.nam % 4 == 0 && a.nam % 100)
    {
        return true;
    }
    else if (a.nam % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check(Ngay a)
{
    if (a.thang == 1 || a.thang == 3 || a.thang == 5 || a.thang == 7 || a.thang == 8 || a.thang == 10 || a.thang == 12)
    {
        if (a.ngay > 0 && a.ngay <= 31)
            return true;
        else
            return false;
    }
    else if (a.thang == 2)
    {
        if (a.ngay > 0)
            if (namNhuan(a))
                if (a.ngay <= 29)
                    return true;
                else
                    return false;
            else if (a.ngay <= 28)
                return true;
            else
                return false;
        else
            return false;
    }
    else if (a.thang == 4 || a.thang == 6 || a.thang == 9 || a.thang == 11)
    {
        if (a.ngay > 0 && a.ngay <= 30)
            return true;
        else
            return false;
    }
    else
        return true;
}

void input(Ngay &a)
{
    cout << "Nhap ngay: ";
    cin >> a.ngay;
    cout << "Nhap thang: ";
    cin >> a.thang;
    cout << "Nhap nam: ";
    cin >> a.nam;
}

int main()
{
    Ngay a;
    input(a);
    if (!check(a))
        cout << "Ngay nhap vao khong ton tai.";
    else
        ((namNhuan(a)) ? (cout << "Nam nhuan") : (cout << "Khong phai nam nhuan"));
    return 0;
}