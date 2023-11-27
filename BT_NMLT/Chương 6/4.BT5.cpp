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

bool XuLi(int a[][100], int r, int c){
     bool check;
     for (int j=0; j<c; j++){ //??
          for (int i=0; i<r-1; i++){
               if (a[i][j] > a[i+1][j]){
                    check = false;
               }
          }
          if (check) return true;
          check=true;
     }
     return false;
}




int main(){
     int a[100][100];
     int r=0, c=0;
     Nhap(a, r, c);

     
     Xuat(a, r, c);
     if (XuLi(a, r, c)){
          cout<<"Yes";
     } else{
          cout<<"No";
     }
     
    
     return 0;
}
