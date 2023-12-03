#include<iostream>
using namespace std;

struct Laptop {
	float weight;
	string code;
};
Laptop a[100];
int n = 0;

void input(Laptop a[], int &n) {
	cout << "Nhap so luong laptop: ";
	cin >> n;
	cout << "Nhap ma so, trong luong cua laptop lan luot: \n";
	for (int i = 0; i < n; i++) {
		cin >> a[i].code >> a[i].weight;
	}
}

void output(Laptop a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i].code << " " << a[i].weight << "\n";
	}
}

int getMaxWeight(Laptop a[], int n) {
	int index = 0;
	float max = a[0].weight;
	for (int i = 0; i < n; i++) {
		if (max < a[i].weight) {
			index = i;
			max = a[i].weight;
		}
	}
	return index;
}

int main() {
	input(a, n);
	//output(a, n);
	int ans = getMaxWeight(a, n);
	cout << "Laptop co trng luong lon nhat la: " << a[ans].code << " " << a[ans].weight << "kg";
	return 0;
}