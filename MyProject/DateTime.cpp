#include "DateTime.h"
#include <iostream>

void DateTime::setDay(int day) {
	if (day >= 1 && day <= 31) {
		this->day = day;
	}
	else {
		throw std::exception("Invalid day");
	}
}

DateTime::DateTime() {

}
DateTime::DateTime(int day, int month, int year, int hour, int minute):day(day),month(month),year(year),hour(hour),minute(minute) {

}

//set Day of event
void DateTime::setDay(int day) {
	if (day >= 1 && day <= 31) {
		this->day = day;
	}
	else {
		throw std::exception("Invalid day");
	}
};
//get Day of event
int DateTime::getDay() {
	if (this->day) {
		return this->day;
	}
	else {
		throw std::exception("Day was not decided yet");
	}
		
};

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
int DateTime::getMonth() {
	if (this->month) {
		return this->month;
	}
	else {
		throw std::exception("Month was not decided yet");
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
int DateTime::getYear() {
	if (this->year) {
		return this->year;
	}
	else {
		throw std::exception("Year was not decided yet");
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
int DateTime::getHour() {
	if (this->hour) {
		return this->hour;
	}
	else {
		throw std::exception("Hour was not decided yet");
	}
};

//set Minute of event
void DateTime::setMinute(int minute) {
	if (minute >= 0 && hour <= 59) {
		this->hour = hour;
	}
	else {
		throw std::exception("Invalid minute. Should be between :0 and :59");
	}
};
//get Minute of event
int DateTime::getMinute() {
	if (this->hour>=0) {
		return this->minute;
	}
	else {
		throw std::exception("Minute was not decided yet");
	}
};