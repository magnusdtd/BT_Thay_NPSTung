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

\

void DanhSoMaTran(int a[][100], int r, int c){
     int t=0;
     for (int j=0; j<c; j++){
          a[0][j]=t;
          t++;
     }
     for (int i=1; i<r; i++){
          a[i][c-1]=t;
          t++;
     }
     for (int j=c-2; j>=0; j--){
          a[r-1][j]=t;
          t++;
     } 
     for (int i=r-2; i>0; i--){
          a[i][0]=t;
          t++;
     }   
}


int main(){
     int a[100][100];
     int r=0, c=0;
     Nhap(a, r, c);
     Xuat(a, r, c);

     DanhSoMaTran(a, r, c);
     Xuat(a, r, c);



     return 0;
}