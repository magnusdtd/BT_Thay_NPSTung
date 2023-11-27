#include<iostream>
using namespace std;

int findIndexOfMax(int a[], int n){
    int s=0, max=INT_MIN;
    for (int i=0; i<n; i++){
        if (max <a[i]){
            max = a[i];
            s=i;
        }
    }
    return s;
}



void AddElement( int a [], int &n , int val , int pos ){
    for (int i=n; i>pos+1; i--){
        a[i] = a[i-1];
    }
    a[pos+1] = val;
    n++;
}
void KTCucTieu(int a[], int n){
    bool check = 0;
    for (int i = 1; i < n-1; i++)
    {
        if(a[i] < a[i-1] && a[i] < a[i+1]){
            check = 1;
            AddElement(a, n, 999, i+1);
        }
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
    int n=0;
    cout <<"Nhap n: \n";
    cin >>n;
    enterArray(a, n);
    int x=0;
    cout<<"Nhap phan tu x muon them vao mang: ";
    cin>>x;
    int s;
    s=findIndexOfMax(a, n);
    AddElement(a, n, x, s);
    cout<<"Mang sau khi them phan tu la: \n";
    exportArray(a, n);
    return 0;
}