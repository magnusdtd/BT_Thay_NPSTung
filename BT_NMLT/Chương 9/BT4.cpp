#include<iostream>
#include<fstream>
using namespace std;

int main(){
	fstream input;
	fstream output;
	fstream file("input4.txt", ios::in);
	string line, maxline;
	
	input.open("input4.txt", ios::in);
	output.open("output4.txt", ios::out);
	
	if (input.fail()){
		cout <<"Doc khong thanh cong";
	} else {
		while (getline(file, line)){
			if (maxline.size() < line.size()) maxline = line;
		}
		output << maxline <<" " << maxline.size();	
	}
	input.close();
	output.close();
	return 0;
}
