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

int XuLi(int a[][100], int r, int c){
     int t=0, temp=0, max=INT_MIN;
     for (int j=0; j<c; j++){ //??
          for (int i=0; i<r; i++){
               if (a[i][j] % 2 == 0){
                    temp++;
               }
          }
          if (max<temp) {
               max = temp;
               t=j;
               temp=0;
          }
     }
     return t;
}




int main(){
     int a[100][100];
     int r=0, c=0;
     Nhap(a, r, c);

     
     Xuat(a, r, c);
     int t=XuLi(a, r, c);
     cout<<"Cot chua nhieu so chan nhat la: "<<t+1;
    
     return 0;
}
