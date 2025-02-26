#include <iostream>
#include <string>

using namespace std;

class Date{
    int day, month, year;
public:
    Date() : day(1), month(1), year(2000) {}
    Date(int d, int m, int y){
        day = d;
        month = m;
        year = y;
    }

    int getYear(){
        return year;
    }
};

class Human{
    string name;
    Date birthday;
    string address;
public:
    Human(string n, Date b, string a){
        name = n;
        birthday = b;
        address = a;
    }
    int getAge(){
        return 2025 - birthday.getYear();
    }
};

int main() {
    cout << "== INPUT INFORMATION OF A HUMAN, OUTPUT THE AGE ==" << endl;
    cout << "Enter name: ";
    string name;
    getline(cin, name);
    cout << "Enter birthday (dd mm yyyy): ";
    int d, m, y;
    cin >> d >> m >> y;
    cout << "Enter address: ";
    string address;
    cin.ignore();
    getline(cin, address);

    Date birthday(d, m, y);
    Human human(name, birthday, address);
    cout << "Age: " << human.getAge() << endl;
    return 0;
}