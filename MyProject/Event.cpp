#include "Event.h"
#include <iostream>

void Event::setName(const char* name) {
	if (name != nullptr) {
		if (this->name != nullptr) {
			delete[]name;
			this->name = nullptr;
		}
		else {
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
	}
	else {
		throw std::exception("No name provided for the event");
	}
};
char* Event::getName() {
	if (this->name != nullptr) {
		char* copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);
		return copy;
	}
	else {
		throw std::exception("No name of the event yet");
	}
};

Event::Event(const char* name, int day, int month, int year, int hour, int minute) {
	setDay(day);
	setMonth(month);
	setYear(year);
	setHour(hour);
	setMinute(minute);
}

Event::Event(const char* name, int day, int month, int year) {
	setDay(day);
	setMonth(month);
	setYear(year);
}



