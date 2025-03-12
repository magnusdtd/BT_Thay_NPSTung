#include <iostream>
using namespace std;

class CDonThuc {
private:
    double heSo;
    int soMu;
public:
    CDonThuc();
    CDonThuc(double heSo, int soMu);
    CDonThuc(const CDonThuc& other);
    CDonThuc operator + (const CDonThuc& other);
    CDonThuc operator - (const CDonThuc& other);
    CDonThuc operator * (const CDonThuc& other);
    CDonThuc operator/(const CDonThuc& other);
    bool operator>(const CDonThuc& other);
    bool operator<(const CDonThuc& other);
    bool operator==(const CDonThuc& other);
    bool operator>=(const CDonThuc& other);
    bool operator<=(const CDonThuc& other);
    bool operator!=(const CDonThuc& other);
    CDonThuc operator!();
    CDonThuc operator~();
    friend istream& operator >> (istream& is, CDonThuc& dt);
    friend ostream& operator << (ostream& os, const CDonThuc& dt);
};

CDonThuc::CDonThuc(): heSo(0), soMu(0) {}
CDonThuc::CDonThuc(double heSo, int soMu) : heSo(heSo), soMu(soMu) {}
CDonThuc::CDonThuc(const CDonThuc& other) {
    heSo = other.heSo;
    soMu = other.soMu;
}

CDonThuc CDonThuc::operator + (const CDonThuc& other) {
    if (soMu == other.soMu)
        return CDonThuc(heSo + other.heSo, soMu);
    throw invalid_argument("Cannot add monomials with different exponents.");
}

CDonThuc CDonThuc::operator - (const CDonThuc& other) {
    if (soMu == other.soMu)
        return CDonThuc(heSo - other.heSo, soMu);
    throw invalid_argument("Cannot subtract monomials with different exponents.");
}

CDonThuc CDonThuc::operator * (const CDonThuc& other) {
    return CDonThuc(heSo * other.heSo, soMu + other.soMu);
}

CDonThuc CDonThuc::operator/(const CDonThuc& other) {
    if (other.heSo == 0) throw invalid_argument("Division by zero.");
    return CDonThuc(heSo / other.heSo, soMu - other.soMu);
}

// Toán tử so sánh
bool CDonThuc::operator>(const CDonThuc& other) { return soMu > other.soMu; }
bool CDonThuc::operator<(const CDonThuc& other) { return soMu < other.soMu; }
bool CDonThuc::operator==(const CDonThuc& other) { return heSo == other.heSo && soMu == other.soMu; }
bool CDonThuc::operator>=(const CDonThuc& other) { return *this > other || *this == other; }
bool CDonThuc::operator<=(const CDonThuc& other) { return *this < other || *this == other; }
bool CDonThuc::operator!=(const CDonThuc& other) { return !(*this == other); }

CDonThuc CDonThuc::operator!() { // Đạo hàm
    if (soMu == 0) return CDonThuc(0, 0);
    return CDonThuc(heSo * soMu, soMu - 1);
}

CDonThuc CDonThuc::operator~() { // Nguyên hàm
    return CDonThuc(heSo / (soMu + 1), soMu + 1);
}

ostream& operator << (ostream& os, const CDonThuc& dt) {
    os << dt.heSo << "x^" << dt.soMu;
    return os;
}

istream& operator >> (istream& is, CDonThuc& dt) {
    is >> dt.heSo >> dt.soMu;
    return is;
}


int main() {
    CDonThuc dt1(3, 2), dt2(4, 2);

    cout << "dt1: " << dt1 << "\n";
    cout << "dt2: " << dt2 << "\n";

    cout << "dt1 + dt2: " << (dt1 + dt2) << "\n";
    cout << "dt1 - dt2: " << (dt1 - dt2) << "\n";
    cout << "dt1 * dt2: " << (dt1 * dt2) << "\n";
    cout << "dt1 / dt2: " << (dt1 / dt2) << "\n";

    cout << "Derivative of dt1: " << !dt1 << "\n";
    cout << "Integral of dt1: " << ~dt1 << "\n";

}