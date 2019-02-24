#pragma once
#ifndef DATEANDTIME_H
#define DATEANDTIME_H

class DateAndTime
{
public:
	explicit DateAndTime(int, int, int, int = 1, int = 1, int = 2000); // default constructor
	void setDate(int, int, int);
	void nextDay();
	void setTime(int, int, int); // set hour, minute, second
	void setHour(int); // set hour (after validation)
	void setMinute(int); // set minute (after validation)
	void setSecond(int); // set second (after validation)
	unsigned int getHour() const; // return hour
	unsigned int getMinute() const; // return minute
	unsigned int getSecond() const; // return second
	void printStandard() const; // output time in standard-time format
	void printUniversal() const;
	void tick();
private:
	unsigned int month;
	unsigned int day;
	unsigned int year;
	unsigned int hour; // 0 - 23 (24-hour clock format)
	unsigned int minute; // 0 - 59
	unsigned int second; // 0 - 59
};
#endif // !DATEANDTIME_H
