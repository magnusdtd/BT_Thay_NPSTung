#include <iostream>
using namespace std;

class Date {
    int day, month, year;
    const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysInMonth() {
        /* Helper function to get days in month */
        if (month == 2 && this->isLeapYear()) return 29;
        return days[month - 1];
    }
public:
    Date(int d, int m, int y): day(d), month(m), year(y) {}
    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? true : false;
    }
    Date getNextDay() {
        int d = day + 1;
        int m = month;
        int y = year;
        
        if (d > daysInMonth()) {
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        
        return Date(d, m, y);
    }
    void display() {
        cout << day << "/" << month << "/" << year << "\n";
    }
};

int main(){
    cout << "== INPUT A DATE, OUTPUT THE NEXT DAY ==" << "\n";
    cout << "Input a date (dd mm yyyy): ";
    int d, m, y;
    cin >> d >> m >> y;
    Date date(d, m, y);
    Date nextDate = date.getNextDay();
    nextDate.display();
    return 0;

}