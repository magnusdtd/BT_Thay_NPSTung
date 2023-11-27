#include <iostream>
using namespace std;

void Nhap(int a[][100], int& r, int& c){
     cout<<"Nhap so dong: ";
     cin>>r;
     cout<<"Nhap so dong: ";
     cin>>c;
     for (int i=0; i<r; i++){
          for (int j=0; j<c; j++){
               cin >>a[i][j];
          }
     }
}

void Xuat(int a[][100], int r, int c){
     for (int i=0; i<r; i++){
          for (int j=0; j<c; j++){
               cout << a[i][j] <<" ";
          }
          cout<<"\n";
     }
}

int TongBien(int a[][100], int r, int c){
     int tong=0;
     for (int i=0; i<r; i++){
          for (int j=0; j<c; j++){
               if (i==0 || i==r-1 || j==0 || j== c-1){
                    tong+=a[i][j];
               }
          }
     }
     return tong;
}


int main(){
     int a[100][100];
     int r=0, c=0;
     Nhap(a, r, c);
     Xuat(a, r, c);

     int s=TongBien(a, r, c);
     cout<<s;



     return 0;
}