#include "DateAndTime.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

DateAndTime::DateAndTime(int h, int m, int s, int mnth, int dy, int yr)
{
	setDate(mnth, dy, yr);
	setTime(h, m, s);
}

void DateAndTime::setDate(int m, int d, int y)
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

void DateAndTime::nextDay()
{
	day++;
	if (day > 31)
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

// set new Time value using universal time
void DateAndTime::setTime(int h, int m, int s)
{
	setHour(h); // set private field hour
	setMinute(m); // set private field minute
	setSecond(s); // set private field second
} // end function setTime

// set hour value
void DateAndTime::setHour(int h)
{
	if (h >= 0 && h < 24)
		hour = h;
	else
		throw invalid_argument("hour must be 0-23");
} // end function setHour

// set minute value
void DateAndTime::setMinute(int m)
{
	if (m >= 0 && m < 60)
		minute = m;
	else
		throw invalid_argument("minute must be 0-59");
} // end function setMinute

// set second value
void DateAndTime::setSecond(int s)
{
	if (s >= 0 && s < 60)
		second = s;
	else
		throw invalid_argument("second must be 0-59");
} // end function setSecond

// return hour value
unsigned int DateAndTime::getHour() const
{
	return hour;
} // end function getHour
// return minute value
unsigned DateAndTime::getMinute() const
{
	return minute;
} // end function getMinute
// return second value
unsigned DateAndTime::getSecond() const
{
	return second;
} // end function getSecond

void DateAndTime::printStandard() const
{
	cout << month << '/' << day << '/' << year << " " << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0') << setw(2) << getMinute()
		<< ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
} // end function printStandard

void DateAndTime::printUniversal() const
{
	cout << month << '/' << day << '/' << year << " " << setfill('0') << setw(2) << getHour() << ":"
		<< setw(2) << getMinute() << ":" << setw(2) << getSecond();
}

void DateAndTime::tick()
{
	second++;
	if (second > 59)
	{
		minute++;
		second = 0;
	}

	if (minute > 59)
	{
		hour++;
		minute = 0;
	}
	if (hour > 23)
	{
		nextDay();
		hour = 0;
	}
}
