/*
Viết chương trình đếm số luần xuất hiện của một kí tự người dùng nhập vào từ bàn phím.
*/
#include <iostream>
#include <string>
using namespace std;

int countChar(string s, char c)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
            count++;
    }
    return count;
}

int main()
{
    string s;
    char c;
    cout << "Nhap chuoi: ";
    getline(cin, s);
    cout << "Nhap ki tu can kiem tra: ";
    cin >> c;
    cout << "So lan xuat hien ki tu " << c << " trong chuoi " << s << " la: " << countChar(s, c);
    return 0;
}