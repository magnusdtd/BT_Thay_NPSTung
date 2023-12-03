#include<iostream>
using namespace std;

struct Point {
	float x, y;

	float getDistance() {
		return sqrt(x * x + y * y);
	}
};
Point a[100];
int n = 0;

void input(Point a[], int& n) {
	cout << "Nhap so luong diem: ";
	cin >> n;
	cout << "Nhap toa do (x;y) cua diem: \n";
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
}

void output(Point a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "(" << a[i].x << ";" << a[i].y << ")\n";
	}
}

int getMaxDistance(Point a[], int n) {
	int index = 0;
	float max = a[0].getDistance();
	for (int i = 0; i < n; i++) {
		if (max < a[i].getDistance()) {
			index = i;
			max = a[i].getDistance();
		}
	}
	return index;
}

int main() {
	input(a, n);
	//output(a, n);
	int ans = getMaxDistance(a, n);
	cout << "Diem cach xa goc toa do nhat la: (" << a[ans].x << ";" << a[ans].y << ")";
	return 0;
}