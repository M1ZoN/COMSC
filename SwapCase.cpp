/***************************************************************
Problem: #4 Swap case
Description: Changes letter if its upper to lower and vice versa
Name: Mukhammadnozim Islamov
ID: 1668193
Date: 09/12/2018
Status: (complete )
****************************************************************/
#include <iostream>
#include<sstream>
#include<string>


using namespace std;

string SwapCase(const string& s)
{
	string output = "";
	for (int i = 0; i<s.size(); i++) {
		(isalpha(s.at(i))) ? output += (((!isupper(s.at(i)))*(toupper(s.at(i)))) + ((!islower(s.at(i)))*(tolower(s.at(i))))) : output += (s.at(i));
	}

	return output;
}

int main() {

	string str;
	cout << "Enter a string: ";
	getline(cin, str);


	cout << "This is new string: " << SwapCase(str) << endl;
	return 0;
}

