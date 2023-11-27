//Dem so phan tu chan trong mang
#include <iostream>
using namespace std;

void Nhap(int a[][100], int &m, int &n){
    cout << "Nhap so dong m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << "a[" << i << "][" << j << "]: ";
            cin>>a[i][j];
        }
    }
}

void Xuat(int a[][100], int m, int n){

    cout << "---- Noi dung cua mang 2 chieu ----"<<endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j]<<" ";
        }
        cout << endl;
    }
}

int countEven(int a[][100], int m, int n){
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] % 2 == 0)
            {
                count++;
            }
            
        }
        
    }
    return count;
    
}

int main(){
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    cout << "So phan tu chia het cho 2 trong mang la: " << countEven(a, m, n);
    system("pause");
    return 0;
}