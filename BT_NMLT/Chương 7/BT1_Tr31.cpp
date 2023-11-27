#include<iostream>
#include<string>
using namespace std;

void NhapChuoi(string &str1){
    cout <<"Nhap chuoi : ";
    getline (cin, str1);
}

int Solve(string str){
    int count=0;
    for (int i=0; i<str.size(); i++){
        if (isdigit(str[i])) count++;
    }
    return count;
}

int main(){
    string str;
    NhapChuoi(str);
    int s = Solve(str);
    cout << "Co tat ca "<<s <<" ky tu la so";
    return 0;
}