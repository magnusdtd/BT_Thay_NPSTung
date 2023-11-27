#include<iostream>
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


void DaoNguoc(int arr[], int start, int end){
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){
    int a[1000];
    int n=0;
    enterArray(a, n);
    cout << "Mang truoc khi sap xep: \n";
    exportArray(a, n);
    
    DaoNguoc(a, 0, n/2);

    cout << "Mang sau khi sap xep: \n";
    exportArray(a, n);
    return 0;
}