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

void sort(int a[], int &n){
    int i = 0, j = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i] >= 0)
        {
            for(j = i+1; j < n; j++)
            {
                if(a[j]>=0&&a[i]>a[j])
                {
                    swap(a[i],a[j]);
                }
            }
        }
        if(a[i]<0)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]<0&&a[i]<a[j])
                {
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