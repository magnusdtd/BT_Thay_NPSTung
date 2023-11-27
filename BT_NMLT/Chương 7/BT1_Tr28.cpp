#include<iostream>
#include<string>
using namespace std;

void NhapChuoi(string &str1){
    cout <<"Nhap chuoi : ";
    getline (cin, str1);
}

string Solve(string str){
    string ans;
    size_t pos;
    while ((pos = str.find(".")) != string::npos){
        str[pos + 1] -=32;
        ans += str.substr(0, pos+1);
        str.erase(0, pos+1);
    }
    return ans+=str;
}

int main(){
    string str;
    NhapChuoi(str);
    str = Solve(str);
    cout << str;
    return 0;
}