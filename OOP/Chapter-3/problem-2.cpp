#include <iostream>
using namespace std;

class CNgay {
private:
    int day;
    void normalize();
public:
    CNgay();
    CNgay(int day);
    bool operator < (CNgay t);
    bool operator == (CNgay t);
    CNgay operator ++ ();
    CNgay operator -- ();
    CNgay operator ++ (int);
    CNgay operator -- (int);
    friend istream& operator >> (istream& is, CNgay& t);
    friend ostream& operator << (ostream& os, const CNgay& t);
};

void CNgay::normalize() {
    if (day < 0) day = 0;
}

CNgay::CNgay(): day(0) {}

CNgay::CNgay(int day): day(day) {}

bool CNgay::operator < (CNgay t) {
    return day < t.day;
}

bool CNgay::operator == (CNgay t) {
    return day == t.day;
}

CNgay CNgay::operator ++ () {
    ++day;
    normalize();
    return *this;
}

CNgay CNgay::operator -- () {
    --day;
    normalize();
    return *this;
}

// Toán tử tăng sau (t++)
CNgay CNgay::operator++(int) {
    CNgay temp = *this; // Lưu trạng thái cũ
    ++(*this); // Gọi toán tử tăng trước
    return temp;
}

// Toán tử giảm sau (t--)
CNgay CNgay::operator--(int) {
    CNgay temp = *this; // Lưu trạng thái cũ
    --(*this); // Gọi toán tử giảm trước
    return temp;
}

istream& operator >> (istream& is, CNgay& t) {
    is >> t.day;
    return is;
}

ostream& operator << (ostream& os, const CNgay& t) {
    os << t.day;
    return os;
}


int main() {
    CNgay day1, day2; cin >> day1 >> day2;
    cout << day1 << " " << day2 << "\n";
    cout << (day1 < day2 ? "True\n" : "False\n");
}