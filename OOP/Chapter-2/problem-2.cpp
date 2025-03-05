#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class Date{
private:
    int day, month, year;
public:
    Date();
    Date(int day, int month, int year);
    int getYear();
};

Date::Date() : day(1), month(1), year(2000) {}
Date::Date(int day, int month, int year): day(day), month(month), year(year) {}
int Date::getYear() { return year; }

class Human{
private:
    string name;
    Date birthday;
    string address;
public:
    Human(string name, Date birthday, string address);
    int getAge();
};

Human::Human(string name, Date birthday, string address): name(name), birthday(birthday), address(address) {}
int Human::getAge() { return 2025 - birthday.getYear(); }

int main() {
    cout << "== INPUT INFORMATION OF A HUMAN, OUTPUT THE AGE ==" << "\n";
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
    cout << "Age: " << human.getAge() << "\n";
    return 0;
}