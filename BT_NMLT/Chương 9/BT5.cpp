#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

struct Player{
	string name;
	int day, month, year;
};

void Process(Player &p, string line){
	int i=0;
	while ( !isdigit(line[i]) ){
		i++;
	}
	p.name = line.substr(0, i);
	string date = line.substr(i, line.size() - i);
	p.day = atoi(date.substr(0, 2).c_str());
	p.month = atoi(date.substr(3, 2).c_str());
	p.year = atoi(date.substr(6, 4).c_str());
}

vector<int> findTheOldest(Player a[], int n){
	vector<int> v;
	int minYear = a[0].year;
	for (int i=0; i<n; i++){
		if (a[i].year < minYear) minYear = a[i].year;
	}
	cout <<minYear;
	for (int i=0; i<n; i++){
		if (a[i].year == minYear) v.push_back(i);
	}
	return v;
}

int main(){
	fstream input;
	fstream output;
	fstream file("input5.txt", ios::in);
	string line;
	Player a[100];
	
	input.open("input5.txt", ios::in);
	output.open("output5.txt", ios::out);
	
	if (input.fail()){
		cout <<"Doc khong thanh cong";
	} else {
		int n=0;
		while (getline(file, line)){
			Process(a[n], line);
			n++;
		}
		vector<int> v = findTheOldest(a, n);
		for (int i=0; i<v.size(); i++){
			output << a[v[i]].name <<"\n";
		}
	}
	input.close();
	output.close();
	return 0;
}
