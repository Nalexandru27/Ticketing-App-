#pragma once
#include <iostream>

class DateTime {
private:
	int day = 0;
	int month = 0;
	int year = 0;
	int hour = 0;
	int minute = -1 ;
public:
	DateTime();
	DateTime(int day, int month, int year, int hour, int minute);

	void setDay(int day);
	int getDay();

	void setMonth(int month);
	int getMonth();

	void setYear(int year);
	int getYear();

	void setHour(int hour);
	int getHour();

	void setMinute(int minute);
	int getMinute();
	
};

