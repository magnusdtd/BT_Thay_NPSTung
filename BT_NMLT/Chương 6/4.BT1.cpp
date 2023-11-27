#include<iostream>
#include<vector>
typedef long long LL;
using namespace std;

void Nhap(int a[][100], int& r, int& c){
     cout<<"Nhap so dong: ";
     cin>>r;
     cout<<"Nhap so cot: ";
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

vector<int> CotToanAm(int a[][100], int r, int c){
     vector<int> v;
     bool t = true;
     for (int j=0; j<c; j++){
          for (int i=0; i<r; i++){
               if (a[i][j]>=0){
                    t=false;
               }
          }
          if (t == true){
               v.push_back(j+1);
          }
          t = true;
     }
     
     return v;
}

void printVector(vector<int> v){
     for (int i=0; i<v.size(); i++){
          cout<<v[i]<<" ";
     }
}



int main(){
     int a[100][100];
     int r=0, c=0;
     Nhap(a, r, c);

     
     Xuat(a, r, c);
     vector<int> v;
     v=CotToanAm(a, r, c);
     printVector(v);

     return 0;
}
