// Tính tổng từng dòng
#include <iostream>
using namespace std;

void Nhap(int a[][100], int &m, int &n)
{
    cout << "Nhap so dong m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void Xuat(int a[][100], int m, int n)
{

    cout << "---- Noi dung cua mang 2 chieu ----" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void sumRow(int a[][100], int m, int n)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        cout << "Tong cac phan tu dong thu " << i + 1 << " la: " << sum << "\n";
    }
}
int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    sumRow(a, m, n);
    system("pause");
    return 0;
}