#include<iostream>
using namespace std;

struct Staff {
	string id;
	int yearOfBirth;
};
Staff a[100];
int n = 0;

void input(Staff a[], int& n) {
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	cout << "Nhap lan luot ma so, nam sinh cua nhan vien: \n";
	for (int i = 0; i < n; i++) {
		cin >> a[i].id >> a[i].yearOfBirth;
	}
}

void output(Staff a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "(" << a[i].id << ";" << a[i].yearOfBirth << ")\n";
	}
}

int getMaxAge(Staff a[], int n) {
	int index = 0;
	float max = a[0].yearOfBirth;
	for (int i = 0; i < n; i++) {
		if (max > a[i].yearOfBirth) {	//nguoi co nam sinh nho nhat la nguoi gia nhat :))
			index = i;
			max = a[i].yearOfBirth;
		}
	}
	return index;
}

int main() {
	input(a, n);
	//output(a, n);
	int ans = getMaxAge(a, n);
	cout << "Nguoi lon tuoi nhat cong ty la: " << a[ans].id << " " << a[ans].yearOfBirth;
	return 0;
}
