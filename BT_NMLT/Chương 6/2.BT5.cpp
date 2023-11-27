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
void SortVector(vector<int>& v){
     for (int i=0; i<v.size()-1; i++){
          for (int j=i+1; j<v.size(); j++){
               if (v[i]> v[j]){
                    swap(v[i], v[j]);
               }
          }
     }
}
void printVector(vector<int> v){
     for (int i=0; i<v.size(); i++){
          cout<<v[i]<<" ";
     }
}

void SapXepBien(int a[][100], int r, int c){
     vector<int> v;
     for (int j=0; j<c; j++){
          v.push_back(a[0][j]);
     }
     for (int i=1; i<r; i++){
          v.push_back(a[i][c-1]);
     }
     for (int j=c-2; j>=0; j--){
          v.push_back(a[r-1][j]);
     } 
     for (int i=r-2; i>0; i--){
          v.push_back(a[i][0]);
     }
     SortVector(v);
     int t=0;
     for (int j=0; j<c; j++){
          a[0][j] = v[t];
          t++;
     }
     for (int i=1; i<r; i++){
          a[i][c-1] = v[t];
          t++;
     }
     for (int j=c-2; j>=0; j--){
          a[r-1][j] = v[t];
          t++;
     } 
     for (int i=r-2; i>0; i--){
          a[i][0] = v[t];
          t++;
     }
}


int main(){
     int a[100][100];
     int r=0, c=0;
     Nhap(a, r, c);

     
     Xuat(a, r, c);

     SapXepBien(a, r, c);
     Xuat(a, r, c);

     return 0;
}
