#include<iostream>
#include<time.h>
using namespace std;

void RandomArray(int a[], int n){
    for (int i=0; i<n; i++){
        a[i] = rand();
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
    srand((int) time(0)); //Truyen seed time cho rand
    int a[1000];
    int n=0;
    cout <<"Nhap so phan tu n: \n";
    cin >>n;
    RandomArray(a, n);
    exportArray(a, n);
    return 0;
}