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

bool SoHoanThien(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	if (sum<=n) return true;
     else return false;
}

int SoHoanThienBien(int a[][100], int r, int c){
     int tong=0, ans=0;
     for (int i=0; i<r; i++){
          for (int j=0; j<c; j++){
               if (i==0 || i==r-1 || j==0 || j== c-1){
                    if (SoHoanThien(a[i][j])){
                         ans=a[i][j];
                    }
               }
          }
     }
     return ans;
}


int main(){
     int a[100][100];
     int r=0, c=0;
     Nhap(a, r, c);
     Xuat(a, r, c);

     int s=SoHoanThienBien(a, r, c);
     cout<<s;



     return 0;
}