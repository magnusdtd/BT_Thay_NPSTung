/*
Viết chương trình tìm kí tự xuất hiện ít nhất trong chuỗi.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int AsciiArr[256];

int findMinIndex(string s)
{
    // for (int i = 0; i < 255; i++)
    // {
    //     AsciiArr[i] = 0;
    // }

    int j = 0;
    while (s[j] != '\0')
    {
        int ascii = (int)s[j];
        AsciiArr[ascii]++;
        j++;
    }

    int min_index = 256;
    for (int i = 0; i < 255; i++)
    {
        if (i != 32)
        {
            if (AsciiArr[i] < AsciiArr[min_index] && AsciiArr[i] != 0)
            {
                min_index = i;
            }
        }
    }

    return min_index;
}

void printResult(string s)
{
    int index = findMinIndex(s);
    vector<int> v;
    for (int i = 0; i < 255; i++)
    {
        if (AsciiArr[i] == AsciiArr[index])
            v.push_back(i);
    }
    if (v.size() == 1)
    {
        cout << "Ki tu xuat hien it nhat: " << (char)v[0] << endl;
        cout << "So lan xuat hien ki tu: " << AsciiArr[index] << endl;
    }
    else
    {
        cout << "Cac ki tu xuat hien it nhat la: ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << (char)v[i] << " ";
        }
        cout << endl;
        cout << "So lan xuat hien: " << AsciiArr[index] << endl;
    }
}

int main()
{
    string s;
    cout << "Nhap chuoi: ";
    getline(cin, s);
    printResult(s);
    return 0;
}