/***************************************************************
Problem: #2 Count uppercase letters 
Description: This is counting uppercase characters program
Name: Mukhammadnozim Islamov
ID: 1668193
Date: 09/12/2018
Status: (complete )
****************************************************************/
#include <iostream>
#include<sstream>
#include<string>

using namespace std;


int main()
{

	string input;
	int count = 0;

	
	cout << "Enter a string: ";
	getline(cin, input);
	cout << endl;
	for (int i = 0; i < input.size(); i++) {
		count += isupper(input.at(i));
	}

	cout << "The number of uppercase letters is " << count << endl;

	return 0;
}


