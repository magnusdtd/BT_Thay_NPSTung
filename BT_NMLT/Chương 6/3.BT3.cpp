// Tìm max của từng dòng
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

void maxValueOfRow(int a[][100], int m, int n)
{
    cout << "Cac gia tri lon nhat tren tung dong la. \n";
    int max = a[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
        cout << "Gia tri lon nhat cua dong " << i + 1 << " la: " << max << "\n";
        max = a[i + 1][0];
    }
}

int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    maxValueOfRow(a, m, n);
    system("pause");
    return 0;
}