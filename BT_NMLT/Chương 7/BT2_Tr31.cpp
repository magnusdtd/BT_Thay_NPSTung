#include<iostream>
#include<string>
using namespace std;

void NhapChuoi(string &str1){
    cout <<"Nhap chuoi : ";
    getline (cin, str1);
}

void Solve(string str, int& countUpper, int& countLower ){
    for (int i=0; i<str.size(); i++){
        if (isupper(str[i])) countUpper++;
        if (islower(str[i])) countLower++;
    }
}

int main(){
    string str;
    NhapChuoi(str);
    int U=0, L=0;
    Solve(str, U, L);
    cout << "Co tat ca "<< U <<" ky tu viet hoa\n";
    cout << "Co tat ca "<< L <<" ky tu viet thuong";
    return 0;
}