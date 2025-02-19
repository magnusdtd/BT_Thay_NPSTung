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
    Fraction a(1, -5);
    int type = a.getTypeOfFraction();
    cout << ((type == ZERO) ? "ZERO" : (type == POSITIVE) ? "POSITIVE" : "NEGATIVE") << "\n";
}