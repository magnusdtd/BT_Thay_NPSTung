// Kiểm tra có dòng nào tăng dần hay không.
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

void solve(int a[][100], int m, int n)
{
    bool check = true;
    for (int i = 0; i < m; i++)
    {
        check = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[i][j] >= a[i][j + 1])
            {
                check = false;
                break;
            }
        }
        if (check == true)
        {
            break;
        }
    }

    check ? cout << "Co dong tang dan" : cout << "Khong co dong tang dan";
}
int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    solve(a, m, n);
    system("pause");
    return 0;
}