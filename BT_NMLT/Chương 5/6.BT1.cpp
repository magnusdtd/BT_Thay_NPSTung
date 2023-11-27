#include<iostream>
#include<math.h>
using namespace std;

void enterArray(int a[], int &n){
    cout <<"Nhap n: ";
    cin >>n;
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

bool Prime(int n){
    if (n <=1){
        return false;
    }
    if (n == 2){
        return true;
    }
    for (int i = 2; i < sqrt(n)+1; i++)
    {
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

void sort(int a[], int &n){
    for (int i = 0; i < n; i++)
    {
        if(Prime(a[i]) == 1){
            for (int j = i+1; j < n; j++)
            {
                if (Prime(a[j]) == 1 && a[i] > a[j]){
                    swap(a[i],a[j]);
                }
            }
        }
        
        
    }
    
}

int main(){
    int a[1000];
    int n=0;
    enterArray(a, n);
    cout << "Mang truoc khi sap xep: \n";
    exportArray(a, n);
    sort(a, n);
    cout << "Mang sau khi sap xep: \n";
    exportArray(a, n);
    return 0;
}