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

// Toán tử tăng sau (t++)
CNgay CNgay::operator++(int) {
    CNgay temp = *this;
    day++;
    normalize();    
    return temp;
}

// Toán tử giảm sau (t--)
CNgay CNgay::operator--(int) {
    CNgay temp = *this;
    day--;
    normalize();
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

}