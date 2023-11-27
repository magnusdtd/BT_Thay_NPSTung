// Kiểm tra kí tự không có trong chuỗi "Nhap mon lap trinh"

#include <iostream>
#include <string>
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

void printCharNotInString(string s)
{
    countElement(s);
    cout << "Cac ki tu khong co trong chuoi la: ";
    for (int i = 0; i < 255; i++)
    {
        if (i >= 65 && i <= 90 || i >= 97 && i <= 122)
        {
            if (AsciiArr[i] == 0)
            {
                cout << (char)i << " ";
            }
        }
    }
}

int main()
{
    string s = "Nhap mon lap trinh";
    cout << "Ta xu li tren chuoi: " << s << endl;
    printCharNotInString(s);
    return 0;
}