#include "DateTime.h"
#include <iostream>

//set Day of event
void DateTime::setDay(int day) {
	if (day >= 1 && day <= 31) {
		this->day = day;
	}
	else {
		throw std::exception("Invalid day");
	}
}
//get Day of event
int DateTime::getDay()  const {
	if (this->day) {
		return this->day;
	}
	else {
		throw std::exception("The exact date was not decided yet. Date and time will be announced soon!");
	}
		
}

//set Month of event
void DateTime::setMonth(int month) {
	if (month >= 1 && month <= 12) {
		this->month = month;
	}
	else {
		throw std::exception("Invalid month");
	}
};
//get Month of event
int DateTime::getMonth()  const {
	if (this->month) {
		return this->month;
	}
	else {
		throw std::exception("The exact date was not decided yet. Date and time will be announced soon!");
	}
};

//set Year of event
void DateTime::setYear(int year) {
	if (year >= 2023 && year <= 2033) {
		this->year = year;
	}
	else {
		throw std::exception("Event should be placed with maximum 10 years in the future from the current year");
	}
};
//get Year of event
int DateTime::getYear()  const {
	if (this->year) {
		return this->year;
	}
	else {
		throw std::exception("The exact date was not decided yet. Date and time will be announced soon!");
	}
};

//set Hour of event
void DateTime::setHour(int hour) {
	if (hour >= 10 && hour <= 24) {
		this->hour = hour;
	}
	else {
		throw std::exception("Invalid hour. Should be between 10:00am and 0:00pm");
	}
};
//get Hour of event
int DateTime::getHour()  const {
	if (this->hour) {
		return this->hour;
	}
	else {
		throw std::exception("The exact date was not decided yet. Date and time will be announced soon!");
	}
};

//set Minute of event
void DateTime::setMinute(int minute) {
	if (minute >= 0 && minute <= 59) {
		this->minute = minute;
	}
	else {
		throw std::exception("Invalid minute. Should be between :0 and :59");
	}
};
//get Minute of event
int DateTime::getMinute()  const {
	if (this->minute>=0) {
		return this->minute;
	}
	else {
		throw std::exception("The exact time was not decided yet");
	}
};


DateTime::DateTime() {

}

DateTime::DateTime(int day, int month, int year, int hour, int minute) {
	setDay(day);
	setMonth(month);
	setYear(year);
	setHour(hour);
	setMinute(minute);
}
