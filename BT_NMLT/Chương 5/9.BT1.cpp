#include<iostream>
using namespace std;

void buildNewArray(int a[], int n, int b[], int m){
    for (int i=n-1, j=0; i>=n/2, j<m; i--, j++){
        b[j] = a[i];
    }
}

void enterArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<"Nhap phan tu thu "<<i+1<<": ";
        cin >> a[i];
    }
}

void exportArray(int a[], int n){
    for (int i=0; i<n; i++){
        cout <<"Phan tu thu "<<i+1<<": "<<a[i]<<"\n";
    }
}


int main(){
    int a[1000];
    int b[1000];
    int n=0;
    cout <<"Nhap n: \n";
    cin >>n;
    int m = n - n/2;
    enterArray(a, n);
    buildNewArray(a, n, b, m);
    exportArray(b, m);
    return 0;
}