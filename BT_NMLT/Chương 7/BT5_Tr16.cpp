/*
Viết chương trình đếm kí tự phân biệt trong chuỗi theo 2 cách:
- phân biệt hoa - thường
- không phân biệt hoa thường.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int AsciiArr[256];

void countElement(string s)
{
    int j = 0;
    while (s[j] != '\0')
    {
        int ascii = (int)s[j];
        AsciiArr[ascii]++;
        j++;
    }
}

void printResult(string s)
{
    countElement(s);
    vector<int> v;
    for (int i = 0; i < 255; i++)
    {
        if (AsciiArr[i] != 0)
            v.push_back(i);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << "Ki tu: ";
        cout << (char)v[i] << " So lan xuat hien: " << AsciiArr[v[i]] << endl;
    }
    for (int i = 0; i < 255; i++)
    {
        AsciiArr[i] = 0;
    }
}

int main()
{
    string s, s1;
    cout << "Nhap chuoi: ";
    getline(cin, s);
    s1 = s;
    for (auto &c : s1)
        c = toupper(c);
    cout << "Phan biet hoa thuong: \n";
    printResult(s);
    cout << "Khong phan biet hoa thuong: \n";
    printResult(s1);
    return 0;
}