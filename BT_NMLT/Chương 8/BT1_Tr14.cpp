#include<iostream>
using namespace std;
const int MAX = 100;

int GCD(int a, int b) {
    return (b == 0) ? a : GCD(b, a % b);
}

struct Fraction {
    int Tu, Mau;
    bool operator < (Fraction& p) {
        if (Mau < 0) {
            Tu = -Tu;
            Mau = -Mau;
        }
        if (p.Mau < 0) {
            p.Mau = -p.Mau;
            p.Tu = -p.Tu;
        }
        if (Tu * p.Mau < Mau * p.Tu) return true;
        else return false;
    }
};
int n = 0;
Fraction a[MAX];

void input(Fraction a[], int &n) {
    int T, M;
    cout << "Nhap so luong phan tu mang: ";
    cin >> n;
    cout << "Nhap lan luot tu va mau cua phan so: \n";
    for (int i = 0; i < n; i++) {
        while (true) {
            cin >> T >> M;
            a[i].Tu = T, a[i].Mau = M;
            if (M != 0) break;
            else cout << "Mau phai khac khong, nhap lai\n";
        } 
    }
}

void output(Fraction a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i].Tu << "/" << a[i].Mau << "\n";
    }
}

Fraction findMaxFraction(Fraction a[], int n) {
    Fraction max = a[0];
    for (int i = 1; i < n; i++) {
        if (max < a[i]) max = a[i];
    }
    return max;
}

int main() {
    input(a, n);
    Fraction max=findMaxFraction(a, n);
    cout << "Mang co phan so lon nhat la: " << max.Tu << "/" << max.Mau;
    return 0;
}