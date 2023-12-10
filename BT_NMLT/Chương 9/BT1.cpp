#include<iostream>
#include<fstream>
using namespace std;

int main(){
	fstream input;
	fstream output;
	int a=0, b=0;
	input.open("input1.txt", ios::in);
	output.open("output1.txt", ios::out);
	if (input.fail())
		cout <<"Doc khong thanh cong";
	else 
	{
		input >> a >> b;
		output << a+b;
	}
	
	input.close();
	output.close();
	return 0;
}
