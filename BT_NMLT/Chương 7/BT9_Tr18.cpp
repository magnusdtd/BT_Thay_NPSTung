#include<iostream>
#include<string>
using namespace std;

bool Check(string str1, string str2){
    // for (int i=0; i<str2.size()-str1.size()+1; i++){
    //     if (str2.substr(i, str1.size()) == str1) return true;
    // }
    // return false;
    if (str2.find(str1) != string::npos) return true;
    return false;
}

void NhapChuoi(string &str1, string &str2){
    cout <<"Nhap chuoi 1: ";
    getline (cin, str1);
    cout <<"Nhap chuoi 2: ";
    getline (cin, str2);
}

int main(){
    string str1, str2;
    NhapChuoi(str1, str2);
    if (Check(str1, str2)){
        cout << "Chuoi 1 co xuat hien trong chuoi 2";
    } else {
        cout << "Chuoi 1 khong co xuat hien trong chuoi 2";
    }
    return 0;
}