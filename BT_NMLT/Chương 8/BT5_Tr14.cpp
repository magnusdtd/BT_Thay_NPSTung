#include<iostream>
using namespace std;

struct Staff {
	string name;
	int age;
};
Staff a[100];
int n = 0;

void input(Staff a[], int& n) {
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	cout << "Nhap lan luot ten, tuoi cua nhan vien: \n";
	for (int i = 0; i < n; i++) {
		cin >> a[i].name >> a[i].age;
	}
}

void output(Staff a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "(" << a[i].name << ";" << a[i].age << ")\n";
	}
}

int getMaxDistance(Staff a[], int n) {
	int index = 0;
	float max = a[0].age;
	for (int i = 0; i < n; i++) {
		if (max < a[i].age) {
			index = i;
			max = a[i].age;
		}
	}
	return index;
}

int main() {
	input(a, n);
	//output(a, n);
	int ans = getMaxDistance(a, n);
	cout << "Diem cach xa goc toa do nhat la: " << a[ans].name << " " << a[ans].age;
	return 0;
}