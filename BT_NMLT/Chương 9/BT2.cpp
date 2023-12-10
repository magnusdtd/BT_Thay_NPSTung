#include<iostream>
#include<fstream>
using namespace std;

int main(){
	fstream input;
	fstream output;
	int n=0;
	int a[100];
	int sum=0;
	
	input.open("input2.txt", ios::in);
	output.open("output2.txt", ios::out);
	
	if (input.fail()){
		cout <<"Doc khong thanh cong";
	} else {
		input >> n;
		for (int i=0; i<n;i++){
			input >> a[i];
			sum += a[i];
		}
		output << sum;
	}	
	input.close();
	output.close();
	return 0;

}

