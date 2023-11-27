#include<iostream>
#include<unordered_map>
using namespace std;

void printMap(unordered_map<int, int> map){
    for (auto x: map){
        cout<<x.first<<" "<<x.second<<"\n";
    }
}

int coutN(int a[], int n){
    unordered_map<int, int> umap;

    for (int i=0; i<n; i++){
        if (umap.find(a[i]) == umap.end()){
            umap[a[i]]=1;
        } else{
            umap[a[i]]++;
        }
    }
    return umap.size();
    
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
    int s;
    s=coutN(a, n);
    cout<<"So cac phan tu co gia tri khac nhau la: "<<s;
    return 0;
}