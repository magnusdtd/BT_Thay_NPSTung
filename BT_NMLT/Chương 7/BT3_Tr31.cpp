#include<iostream>
#include<string>
using namespace std;

void NhapChuoi(string &str1){
    cout <<"Nhap chuoi : ";
    getline (cin, str1);
}

string Reverse(string str){
    string ans;
    for (int i=0; i<str.size(); i++){
        ans += str[str.size()-i-1]; 
    }
    return ans;
}

int main(){
    string str;
    NhapChuoi(str);
    str = Reverse(str);
    cout << "Chuoi sau khi dao nguoc la: " << str;
    return 0;
}