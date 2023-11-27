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

vector<double> CotToanAm(int a[][100], int r, int c){
     vector<double> v;
     double t=0;
     bool check = true;
     for (int j=0; j<c; j++){
          for (int i=0; i<r; i++){
               t+=(double) a[i][j];
          }
          t/=r;
          v.push_back(t);
          t=0;
     }
     
     return v;
}

void printVector(vector<double> v){
     for (int i=0; i<v.size(); i++){
          cout<<v[i]<<" ";
     }
}



int main(){
     int a[100][100];
     int r=0, c=0;
     Nhap(a, r, c);

     
     Xuat(a, r, c);
     vector<double> v;
     v=CotToanAm(a, r, c);
     cout<<"Trung binh cong cua tung cot trong ma tran:\n";
     printVector(v);

     return 0;
}
