#include <iostream>
#include <stdexcept>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

int main()
{
	Time t(23, 58, 58); // hour, minute and second specified
	for (int i = 0; i < 122; i++)
	{
		t.tick();
		t.printUniversal();
		cout << endl;
	}
} // end main