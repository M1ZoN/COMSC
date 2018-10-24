/***************************************************************
Problem: #3 Checking Palindromes
Description: Checking if the given word is palindrome
Name: Mukhammadnozim Islamov
ID: 1668193
Date: 09/12/2018
Status: (complete )
****************************************************************/
#include <iostream>
#include<sstream>
#include<string>



using namespace std;

bool isPal(string input) {
	string pal(input.rbegin(), input.rend());
	return (pal == input);
}

int main()
{

	string input;

	cout << "Enter a string: ";
	getline(cin, input);
	cout << input << " is" << (isPal(input) ? "" : " not") << " a palindrome." << endl;


	return 0;
}


