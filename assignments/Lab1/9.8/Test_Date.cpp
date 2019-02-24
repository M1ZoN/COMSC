#include <iostream>
#include "Date.h" // include definition of class Date from Date.h
using namespace std;

int main()
{
	Date d(11, 30, 2019);
	for (int i = 0; i < 33; i++)
	{
		d.nextDay();
		d.print();
		cout << endl;
	}
} // end main
