// Chuoi: I would like to buy a motor bike
// -> like a motor buy
// -> sao chep sang chuoi moi: motor bike
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "I would like to buy a motor bike";
    string s1, s2;
    s1 = s;
    s1.erase(1, 8); // Chuoi thanh: like to buy a motor bike
    s1.erase(5, 7); // Chuoi thanh: like a motor bike
    s2 = s.substr(22, 31);
    cout << "Chuoi ban dau: " << s << endl;
    cout << "Chuoi sau khi xoa: " << s1 << endl;
    cout << "Chuoi sao chep sang chuoi moi: " << s2 << endl;
    return 0;
}