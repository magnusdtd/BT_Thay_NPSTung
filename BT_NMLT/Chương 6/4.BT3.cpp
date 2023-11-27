#include <iostream>
#include<vector>
typedef long long LL;
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

void XuLi(int a[][100], int r, int c){
     double t=0;
     bool check = true;
     for (int j=0; j<c; j+=2){ //??
          for (int i=0; i<r; i++){
               a[i][j] = a[0][j];
          }
     }
}




int main(){
     int a[100][100];
     int r=0, c=0;
     Nhap(a, r, c);

     
     Xuat(a, r, c);
     XuLi(a, r, c);
     cout<<"Ma tran sau xu li: \n";
     Xuat(a, r, c);
    
     return 0;
}
