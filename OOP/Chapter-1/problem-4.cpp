#include <iostream>

using namespace std;

class Date {
    private:
        int day, month, year;
    public:
        Date(int d, int m, int y) {
            day = d;
            month = m;
            year = y;
        }
        bool isLeapYear() {
            if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                return true;
            }
            return false;
        }
        Date nextDay() {
            int d = day, m = month, y = year;
            if(m == 2) {
                if(isLeapYear()) {
                    if(d == 29) {
                        d = 1;
                        m++;
                    } else {
                        d++;
                    }
                } else {
                    if(d == 28) {
                        d = 1;
                        m++;
                    } else {
                        d++;
                    }
                }
            } else if(m == 4 || m == 6 || m == 9 || m == 11) {
                if(d == 30) {
                    d = 1;
                    m++;
                } else {
                    d++;
                }
            } else {
                if(d == 31) {
                    d = 1;
                    m++;
                    if(m == 13) {
                        m = 1;
                        y++;
                    }
                } else {
                    d++;
                }
            }
            return Date(d, m, y);
        }
        void display() {
            cout << day << "/" << month << "/" << year << endl;
        }
};

int main(){
    cout << "== INPUT A DATE, OUTPUT THE NEXT DAY ==" << endl;
    cout << "Input a date (dd mm yyyy): ";
    int d, m, y;
    cin >> d >> m >> y;
    Date date(d, m, y);
    Date nextDate = date.nextDay();
    nextDate.display();
    return 0;

}