/*
Nhap vao chuoi, kiem tra xem chuoi co ki tu 'N' khong. Neu co xuat 1, khong xuat 0.
*/
#include <iostream>
#include <string>
using namespace std;

bool checkHaving(string s, char c)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s;
    cout << "Nhap chuoi: ";
    getline(cin, s);
    cout << checkHaving(s, 'N');
    return 0;
}