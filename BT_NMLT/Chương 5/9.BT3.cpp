#include<iostream>
#include<time.h>
using namespace std;

int random(int minN, int maxN){
	return minN + rand() % (maxN + 1 - minN);
}

void RandomArray(int a[], int n, int min, int max){
    for (int i=0; i<n; i++){
        a[i] = random(min, max);
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
    int n=0, min=0, max=0;
    cout <<"Nhap so phan tu n: \n";
    cin >>n;
    cout<<"Nhap doan [min, max]: \n";
    cin >>min >>max;
    RandomArray(a, n, min, max);
    exportArray(a, n);
    return 0;
}