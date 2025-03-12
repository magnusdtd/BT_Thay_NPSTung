#include <iostream>
using namespace std;

class CThoiGian {
private:
    int hour, minute, second;
    void normalize();
public:
    CThoiGian();
    CThoiGian(int hour, int minute, int second);
    CThoiGian(const CThoiGian& t);
    bool operator >= (CThoiGian t);
    bool operator != (CThoiGian t);
    CThoiGian operator + (CThoiGian t);
    CThoiGian operator - (CThoiGian t);
    CThoiGian operator ++ ();
    CThoiGian operator -- ();
    friend ostream& operator << (ostream& os, const CThoiGian& t);
    friend istream& operator >> (istream& os, CThoiGian& t);
};

void CThoiGian::normalize() {
    if (second >= 60) {
        minute += second / 60;
        second %= 60;
    } else if (second < 0) {
        minute -= (abs(second) / 60) + 1;
        second = 60 - abs(second) % 60;
    }

    if (minute >= 60) {
        hour += minute / 60;
        minute %= 60;
    } else if (minute < 0) {
        hour -= (abs(minute) / 60) + 1;
        minute = 60 - abs(minute) % 60;
    }

    if (hour < 0) hour = 0; // Không cho phép giờ âm
}

CThoiGian::CThoiGian(): hour(0), minute(0), second(0) {}

CThoiGian::CThoiGian(int hour, int minute, int second): hour(hour), minute(minute), second(second) {
    normalize();
}

CThoiGian::CThoiGian(const CThoiGian& t) {
    hour = t.hour;
    minute = t.minute;
    second = t.second;
}

bool CThoiGian::operator >= (CThoiGian t) {
    return  (hour > t.hour) 
            || (hour == t.hour && minute > t.minute) 
            || (hour == t.hour && minute == t.minute && second >= t.second);
}

bool CThoiGian::operator != (CThoiGian t) {
    return !(hour == t.hour && minute == t.minute && second == t.second);
}

CThoiGian CThoiGian::operator + (CThoiGian t) {
    return CThoiGian(hour + t.hour, minute + t.minute, second + t.second);
}

CThoiGian CThoiGian::operator - (CThoiGian t) {
    int totalSec1 = hour * 3600 + minute * 60 + second;
    int totalSec2 = t.hour * 3600 + t.minute * 60 + t.second;

    if (totalSec1 < totalSec2)
        return CThoiGian(0, 0, 0);
    int diff = totalSec1 - totalSec2;
    return CThoiGian(diff / 3600, (diff % 3600) / 60, diff % 60);
}

// Toán tử tăng trước (++t)
CThoiGian CThoiGian::operator ++ () {
    ++second;
    normalize();
    return *this;
}

// Toán tử giảm trước (--t)
CThoiGian CThoiGian::operator -- () {
    --second;
    normalize();
    return *this;
}

ostream& operator << (ostream& os, const CThoiGian& t) {
    os << t.hour << "h " << t.minute << "m " << t.second << "s\n";
    return os;
}

istream& operator >> (istream& is, CThoiGian& t) {
    is >> t.hour >> t.minute >> t.second;
    return is;
}

int main() {
    CThoiGian time1, time2;
    cin >> time1 >> time2;
    cout << time1 - time2 << "\n"; // Co van de voi so am
}