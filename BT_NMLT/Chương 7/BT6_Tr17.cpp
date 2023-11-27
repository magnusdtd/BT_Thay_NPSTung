// Mo phong ham insert
#include <iostream>
#include <string>
using namespace std;

void Insert(string s, int begin, char c)
{
    s.push_back('0');
    for (int i = s.size() - 2; i >= begin; i--)
    {
        s[i + 1] = s[i];
    }
    s[begin] = c;
    cout << "Chuoi sau khi chen la: " << s;
}

int main()
{
    string s;
    int n = 0;
    char c = 0;
    cout << "Nhap vao chuoi: ";
    getline(cin, s);
    cout << "Nhap vi tri muon chen: ";
    cin >> n;
    cout << "Nhap ki tu muon chen: ";
    cin >> c;
    Insert(s, n, c);
    return 0;
}