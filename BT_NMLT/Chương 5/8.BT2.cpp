#include<iostream>
#include<unordered_map>
#include<math.h>
using namespace std;

void printMap(unordered_map<int, int> map){
    for (auto x: map){
        cout<<x.first<<" "<<x.second<<"\n";
    }
}
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

void deleteEle(int a[], int &n){
    unordered_map<int, int> umap;

    for (int i=0; i<n; i++){
        if (umap.find(a[i]) == umap.end()){
            umap[a[i]]=1;
        } else{
            umap[a[i]]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(umap[a[i]] != 1){
            for (int j = i; j < n; j++)
            {
                a[j] = a[j+1];
            }
            n--;
            i--;
        }
    }
}

int main(){
    int a[1000];
    int n=0;
    enterArray(a, n);
    cout << "Mang truoc khi sap xep: \n";
    exportArray(a, n);
    deleteEle(a, n);
    cout << "Mang sau khi sap xep: \n";
    exportArray(a, n);
    return 0;
}