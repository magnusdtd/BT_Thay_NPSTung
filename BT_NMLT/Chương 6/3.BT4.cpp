// Tìm dòng chứa nhiều số chẵn nhất
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

void rowMaxEven(int a[][100], int m, int n)
{
    int even = 0;
    int max = 0;
    int count = 0;
    int b[100];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] % 2 == 0)
            {
                even++;
            }
        }
        if (even > max)
        {
            max = even;
            count = 0;
            b[count] = i;
            count++;
        }
        else if (even == max)
        {
            b[count] = i;
            count++;
        }
        even = 0;
    }
    cout << "Dong chua nhieu so chan nhat la: ";
    for (int i = 0; i < count; i++)
    {
        cout << b[i] + 1 << " ";
    }
}
int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    rowMaxEven(a, m, n);
    system("pause");
    return 0;
}