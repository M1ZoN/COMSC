#pragma once
#ifndef DATE_H
#define DATE_H

// class Date definition
class Date
{
public:
	explicit Date(int = 1, int = 1, int = 2000); // default constructor
	void setDate(int, int, int);
	void nextDay();
	void print();
private:
	unsigned int month;
	unsigned int day;
	unsigned int year;
}; // end class Date

#endif
