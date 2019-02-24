#include "DateAndTime.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	DateAndTime t(23, 59, 53, 12, 31, 2018);

	for (int i = 0; i < 10; i++)
	{
		t.printStandard();
		cout << "          ";
		t.printUniversal();
		t.tick();
		cout << endl;
	}

}
