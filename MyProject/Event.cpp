#include "Event.h"
#include <string>
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
}
char* Event::getName() const{
	if (this->name != nullptr) {
		char* copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);
		return copy;
	}
	else {
		throw std::exception("No name of the event yet");
	}
}

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

void Event::setNumArtists(int newNoArtists) {
	if (newNoArtists > 0) {
		this->numArtists = newNoArtists;
	}
	else {
		throw std::exception("Provide a positive number of artists!");
	}
}
int Event::getNumArtists() const{
	if (this->numArtists > 0) {
		return this->numArtists;
	}
	else {
		throw std::exception("No artists yet");
	}
}

void Event::setArtists(const std::string* newArtists, int noArtists) {
	setNumArtists(noArtists);
	if (newArtists != nullptr && noArtists >= 0) {
		if (this->artists != nullptr) {
			delete[]this->artists;
			this->artists = nullptr;
		}
		this->artists = new std::string[noArtists];
		for (int i = 0; i < noArtists; i++) {
			this->artists[i] = newArtists[i];
		}
	}
	else {
		throw std::exception("No artists yet");
	}
}

std::string* Event::getArtists() const{
	if (this->artists != nullptr) {
		std::string* copy = new std::string[getNumArtists()];
		memcpy(copy, this->artists, getNumArtists());
		return copy;
	}
}

std::ostream& operator<<(std::ostream& out, const Event& e) {
	out << "Name of the event: "; // why I can t use the getter?

	return out;
}

std::istream& operator>>(std::istream& in, Event& e) {
	e.
}

