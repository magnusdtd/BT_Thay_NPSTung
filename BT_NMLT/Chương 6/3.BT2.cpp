// Liệt kê các dòng có chứa số 0
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

bool checkZero(int a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                return true;
            }
        }
    }

    return false;
}

void printRowHave0(int a[][100], int m, int n)
{
    if (checkZero(a, m, n))
    {
        cout << "Cac dong chua so 0 la: ";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 0)
                {
                    cout << i + 1 << " ";
                    break;
                }
            }
        }
    }
    else
    {
        cout << "Mang da cho khong co dong nao chua so 0.\n";
    }
}

int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    printRowHave0(a, m, n);
    system("pause");
    return 0;
}