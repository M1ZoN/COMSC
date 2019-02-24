#include <iostream>
#include "Date.h" // include definition of class Date from Date.h
using namespace std;

// Date constructor (should do range checking)
Date::Date(int m, int d, int y)
{
	setDate(m, d, y);
} // end constructor Date

void Date::setDate(int m, int d, int y)
{
	{
		if ((m > 0 && m <= 12) && (d > 0 && d <= 31) &&
			(y > 0))
		{
			month = m;
			day = d;
			year = y;
		}
		else
			throw invalid_argument("month, day and/or year was out of range");
	}
}

bool isLeap(int year)
{
	return ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)));
}

void Date::nextDay()
{
	day++;
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
	{
		month++;
		day = 1;
	}
	else if (month == 2 && ((day > 28 && !isLeap(year)) || (day == 29 && isLeap(year))))
	{
		month++;
		day = 1;
	}
	else if (day > 31)
	{
			month++;
			day = 1;
	}
	if (month > 12)
	{
		year++;
		month = 1;
	}
}

// print Date in the format mm/dd/yyyy
void Date::print()
{
	cout << month << '/' << day << '/' << year;
} // end function print

