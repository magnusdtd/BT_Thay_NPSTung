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

string Solve(vector<string> s){
    map<string, int> map;
    for (int i=0; i<s.size(); i++){
        if (map.find(s[i]) == map.end()){
            map[s[i]] = 1;
        } else map[s[i]]++;
    }
    int max = 0;
    string ans;
    for (int i=0; i<s.size(); i++){
        if (max < map[s[i]]) {
            max = map[s[i]];
            ans = s[i];
        }
    }
    return ans;
}

void NhapChuoi(string &str1){
    cout <<"Nhap chuoi : ";
    getline (cin, str1);
}

int main(){
    string str1;
    vector<string> str;
    NhapChuoi(str1);
    str = Split(str1, " ");
    cout << "Tu xuat hien nhieu nhat la: ";
    cout << Solve(str);
    return 0;
}