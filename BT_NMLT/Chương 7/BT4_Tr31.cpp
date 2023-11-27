#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<string> Split(string str, string delimiter){
    size_t pos = 0;
    vector<string> s;
    while ((pos = str.find(delimiter)) != string::npos){
        s.push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.size());
    }
    s.push_back(str);
    return s;
}

void printVector(vector<string> s){
    for (int i=0; i<s.size(); i++){
        cout << s[i] << " ";
    }
}

string Solve(vector<string> s){
    string ans;
    ans += s[s.size()-1];
    ans += " ";
    for (int i = 1; i < s.size()-1; i++){
        ans += s[i];
        ans += " ";
    }
    ans += s[0];
    return ans;
}

void NhapChuoi(string &str1){
    cout <<"Nhap chuoi : ";
    getline (cin, str1);
}

int main(){
    string s;
    vector<string> str;
    NhapChuoi(s);
    str = Split(s, " ");
    //printVector(str);
    s = Solve(str);
    cout << "Chuoi sau khi xu li la: " << s;
    return 0;
}