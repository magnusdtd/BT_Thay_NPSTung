#include<iostream>
using namespace std;

struct Student {
	string name;
	float math, literature;

	float getAS() {
		return (math + literature) / 2;
	}
};
Student a[100];
int n = 0;

void input(Student a[], int &n) {
	cout << "Nhap so luong hoc sinh: ";
	cin >> n;
	cout << "Nhap lan luot ten, diem toan, diem van cua hoc sinh: \n";
	for (int i = 0; i < n; i++) {
		cin >> a[i].name >> a[i].math >> a[i].literature;
	}
}

void output(Student a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i].name << " " << a[i].math << " " << a[i].literature << "\n";
	}
}

int getHighestAS(Student a[], int n) {
	int index = 0;
	float max = a[0].getAS();
	for (int i = 1; i < n; i++) {
		if (max < a[i].getAS()) {
			max = a[i].getAS();
			index = i;
		}
	}
	return index;
}

int main() {
	input(a, n);
	output(a, n);
	int ans = getHighestAS(a, n);
	cout << "Hoc sinh co diem trung binh nhat la: " << a[ans].name << " " << a[ans].getAS();
	return 0;
}