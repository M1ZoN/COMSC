/***************************************************************
Problem: Tower of Hanoi
Description: Shows the step of moving rings in the game Tower of Hanoi
Name: Mukhammadnozim Islamov, Aleksandr Kurakulov
ID: 1668193, 1633897
Date: 10/3/2018
Status: (complete)
****************************************************************/
#include <iostream>
#include<string>
#include<sstream>

using namespace std;

void line(int num, char source, char dest) {
	cout << "Move disk " << num << " from " << source << " to " << dest << endl;
}

void move(int num, char source,char dest, char spare)
{
	
	if (num == 1) {
		line(num,source,dest);
	}
	else{
		move(num - 1, source, spare, dest);
		line(num, source, dest);
		move(num - 1, spare, dest, source);
	}
}

int main()
{
	cout << "Please input the number of disks you want: ";
	int numofDisks;
	string inp;
	getline(cin, inp);
	stringstream(inp) >> numofDisks;

	move(numofDisks, 'A', 'B', 'C');

	return 0;
}
