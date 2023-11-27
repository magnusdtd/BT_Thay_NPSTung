#include <iostream>
typedef long long LL;
using namespace std;

void Nhap(LL a[][100], int& r, int& c){
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

void Xuat(LL a[][100], int r, int c){
     for (int i=0; i<r; i++){
          for (int j=0; j<c; j++){
               cout << a[i][j] <<" ";
          }
          cout<<"\n";
     }
}

void KhoiTao(LL a[][100], int& r, int& c){
     cout<<"Nhap so dong: ";
     cin>>r;
     cout<<"Nhap so dong: ";
     cin>>c;
     int sum=0;
     
     for (int i=0; i<r; i++){
          for (int j=0; j<c; j++){
               if (i==0 && j==0){
                    a[0][0]=1;
               } else if (j==0){
                    sum+=a[i-1][c-1];
                    a[i][j]=sum;
               } else{
                    sum+=a[i][j-1];
                    a[i][j]=sum;
               }
          }
     }
}


int main(){
     LL a[100][100];
     int r=0, c=0;
     KhoiTao(a, r, c);

     
     Xuat(a, r, c);



     return 0;
}