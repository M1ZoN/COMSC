/***************************************************************
Problem: #5 Phone keypads 
Description: Function that converts word into numeric value
Name: Mukhammadnozim Islamov
ID: 1668193
Date: 09/12/2018
Status: (complete )
****************************************************************/
#include <iostream>
#include<sstream>
#include<string>

using namespace std;

int getNumber(int ch) {
	return ((ch < 3)*2 + (ch >= 3 && ch < 6) * 3 + (ch >= 6 && ch < 9) *4 + (ch >= 9 && ch < 12) * 5 + (ch >= 12 && ch < 15) * 6 + (ch >= 15 && ch < 19) *7 + (ch >= 19 && ch < 22) * 8 + (ch >= 22 && ch < 26) * 9);
}


int main() {
	int a,b;
	string s,c,output;
	cout << "Enter a string: ";
	getline(cin, s);
	stringstream(s) >> a >> b >> c;
	string c1 = c.substr(1, 7);

	cout << a << b << "-" ;
	for (int i = 0; i < c1.size();i++) {
		int ch = (tolower(c1.at(i))-'a');
		cout<<getNumber(ch);
	}
	cout << endl;
	return 0;

}

