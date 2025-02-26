#include <iostream>
#include <cassert>
using namespace std;

#define POSITIVE 1
#define NEGATIVE -1
#define ZERO 0

class Fraction {
    int numerator, denominator;
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
        assert(denominator != 0);
    }
    int getTypeOfFraction() {
        return (!numerator) ? ZERO : (numerator * denominator > 0) ? POSITIVE : NEGATIVE;
    }
};

int main() {
    int numerator, denominator;
    cout << "== INPUT A FRACTION, OUTPUT ITS TYPE(ZERO, NEGATIVE, POSITIVE) ==\n";
    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;
    Fraction a(numerator, denominator);
    int type = a.getTypeOfFraction();
    cout << ((type == ZERO) ? "ZERO" : (type == POSITIVE) ? "POSITIVE" : "NEGATIVE") << "\n";
}