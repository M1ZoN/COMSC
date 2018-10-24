/***************************************************************
Problem: #1 Display pyramid 
Description: Function to create a pyramid of numbers
Name: Mukhammadnozim Islamov
ID: 1668193
Date: 09/12/2018
Status: (complete )
****************************************************************/
#include<iostream>
#include<string>
#include<sstream>

using namespace std;


int main() {
	int num;
	string a;

	cout << "Pyramid Builders International" << endl;
	cout << "Please input number of lines of the pyramid: ";
	getline(cin, a);
	stringstream(a) >> num;

	int outp = 1;
	int spaces = num;
	
	int mid = num;
	for (int i = 0; i < num; i++) {
		string output(spaces*2, ' ');
		cout << output;
		
		for (int j = 0,counter=i+1; j < outp; j++,counter--) {
			counter -= (counter == 0)*2;
			cout << abs(counter) << " ";
		}

		cout << endl;
		outp = outp + 2;
		spaces = spaces - 1;
		
	}

	return 0;
}