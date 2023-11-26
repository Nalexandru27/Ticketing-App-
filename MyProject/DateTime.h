#pragma once
#include <iostream>

class DateTime {
private:
	int day = 0;
	int month = 0;
	int year = 0;
	int hour = 0;
	int minute = -1;
public:
	DateTime();
	DateTime(int day, int month, int year, int hour, int minute);

	void setDay(int day);
	int getDay() const;

	void setMonth(int month);
	int getMonth() const;

	void setYear(int year);
	int getYear() const;

	void setHour(int hour);
	int getHour() const;

	void setMinute(int minute);
	int getMinute() const;

	DateTime(const DateTime& dt);

	DateTime& operator=(const DateTime& dt);

	friend std::ostream& operator<<(std::ostream& out, const DateTime& dt);
	friend std::istream& operator>>(std::istream& in, DateTime& dt);

	int operator-(int value);

	bool operator!();

	bool operator>(const DateTime& dt);

	bool operator==(const DateTime& dt);

	DateTime operator++();
	DateTime operator++(int);
};

