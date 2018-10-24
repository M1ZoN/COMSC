#include <iostream>
#include <string>
#include <vector>
#include<cmath>
#include<sstream>
#include<random>
#include<fstream>
#include"windows.h"

using namespace std;

void clearScreen(void) {
	system("cls");
}

string getRandomWord() {
	ifstream dict;
	string input, randomword;
	int count = 0, index = 0;

	dict.open("dictionary.txt");
	if (!dict)
		cout << "error loading your file" << endl;

	while (getline(dict, input)) {
		count += 1;
	}

	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> distribution(0, count);
	index = distribution(generator);


	dict.seekg(0, ios::beg);
	for (int x = 0; x <= count; x++) {
		getline(dict, input);
		randomword = input;
	}

	return randomword;
}

int main()
{
	vector<string>vec(9);
	vec.at(0) = "+---------+";
	vec.at(1) = "    |     |";
	vec.at(2) = "    |     |";
	vec.at(3) = "          |";
	vec.at(4) = "          |";
	vec.at(5) = "          |";
	vec.at(6) = "          |";
	vec.at(7) = "          |";
	vec.at(8) = "+---------+";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << endl;
	}
	bool flag = true;
	string str;
	char c = 'x';
	string key = getRandomWord();
	string output =(key.size(),"*") ;
	
	int counter = 0;
	do {
		cout << "Please input yor letter: ";
		getline(cin,str);
		stringstream(str) >> c;
		clearScreen();

		if (key.find(c) == string::npos) {
			counter++;
		}
		else {
			output.at(key.find(c)) = key.at(key.find(c));
		}
		switch (counter)
		{
		case 1: vec.at(3).at(4) = 'O'; break;
		case 2: vec.at(4).at(4) ='|'; break;
		case 3: vec.at(4).at(3)='\\'; break;
		case 4: vec.at(4).at(5) = '/'; break;
		case 5: vec.at(5).at(4)='|'; break;
		case 6: vec.at(6).at(3) ='/'; break;
		case 7: vec.at(6).at(5)='\\'; break;
		default:
			break;
		}
		for (int i = 0; i < vec.size(); i++) {
			cout << vec.at(i) << endl;
		}
		cout << output << endl;

		
	} while (counter < 8 && (output != key));

	counter == 8 ? (cout << "you lost") : (cout << "you won");
	cout << endl;
	
	return 0;
}