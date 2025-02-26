#include <iostream>
using namespace std;

class Date{
    private:
        int day, month, year;
    public:
        Date(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }
        bool isLeapYear(){
            if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
                return true;
            }
            return false;
        }
};

int main(){
    cout << "== INPUT DATE, CHECK LEAP YEAR ==" << endl;
    cout << "Enter day, month, year: ";
    int d, m, y;
    cin >> d >> m >> y;
    Date date(d, m, y);
    if(date.isLeapYear()){
        cout << "Leap year" << endl;
    }else{
        cout << "Not leap year" << endl;
    }
    return 0;
}