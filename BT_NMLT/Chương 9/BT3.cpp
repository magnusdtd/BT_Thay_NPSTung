#include<iostream>
#include<fstream>
using namespace std;

int GCD(int a, int b){
	return (b==0) ? a: GCD(b, a%b);
}

struct Fraction {
		int x, y;
		Fraction(){}
		Fraction(int x, int y): x(x), y(y) {}
		Fraction shorten() {
			return Fraction(x/GCD(x, y), y/GCD(x, y));
		}	
		Fraction operator + (Fraction f){
			return Fraction(x*f.y+y*f.x, y*f.y).shorten();
		}
	};

int main(){
	fstream input;
	fstream output;
	Fraction a[100];
	int i=0;
	Fraction sum;
	
	fstream file("input3.txt", ios::in);
	string line;
	
	input.open("input3.txt", ios::in);
	output.open("output3.txt", ios::out);
	
	if (input.fail()){
		cout <<"Doc khong thanh cong";
	} else {
		while (getline(file, line)){
			input >> a[i].x >> a[i].y;
			if (i==0) sum = a[i];
			else {
				sum = sum + a[i];
			}
			cout << "sum: " << sum.x << "/" << sum.y << "\n";
			i++;
		}
	}

	input.close();
	output.close();
	return 0;
}
