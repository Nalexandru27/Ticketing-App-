#include "Event.h"
#include <string>
#include <iostream>
#include "ManagementApp.h";

void Event::setName(const char* name) {
	if (name != nullptr) {
		if (this->name != nullptr) {
			delete[]name;
			this->name = nullptr;
		}
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
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
		throw std::exception("No artists provided");
	}
}

std::string* Event::getArtists() const{
	if (this->artists != nullptr) {
		std::string* copy = new std::string[this->getNumArtists()];
		for (int i = 0; i < this->getNumArtists(); i++) {
			copy[i] = this->artists[i];
		}
		return copy;
	}
	else {
		throw std::exception("No artists yet");
	}
}
Event::Event() {
	ManagementApp::incrementNumEvents();
}

Event::Event(const char* name, int numArtists, std::string* artists) {
	setName(name);
	setArtists(artists, numArtists);
	delete[] artists;
	ManagementApp::incrementNumEvents();
}

Event::Event(const char* name, int day, int month, int year, int hour, int minute) {
	setName(name);
	setDay(day);
	setMonth(month);
	setYear(year);
	setHour(hour);
	setMinute(minute);
	ManagementApp::incrementNumEvents();
}

Event::Event(const char* name, int day, int month, int year) {
	setName(name);
	setDay(day);
	setMonth(month);
	setYear(year);
	ManagementApp::incrementNumEvents();
}

Event::Event(const char* name, int numArtists, std::string* artists, int day, int month, int year) {
	setName(name);
	setArtists(artists, numArtists);
	delete[] artists;
	setDay(day);
	setMonth(month);
	setYear(year);
	ManagementApp::incrementNumEvents();
}

Event::Event(const char* name, int numArtists, std::string* artists, int day, int month, int year, int hour, int minute) {
	setName(name);
	setArtists(artists, numArtists);
	delete[] artists;
	setDay(day);
	setMonth(month);
	setYear(year);
	setHour(hour);
	setMinute(minute);
	ManagementApp::incrementNumEvents();
}

Event::~Event() {
	delete[] name;
	delete[] artists;
	ManagementApp::decrementNumEvents();
}

std::ostream& operator<<(std::ostream& out, const Event& e) {
	out << std::endl << std::endl << "------------------------" <<std::endl;

	out << std::endl << "Name of the event: " << e.getName();

	out << std::endl<<  "Number of artists: " << e.getNumArtists();

	std::string* temp = e.getArtists();
	for (int i = 0; i < e.getNumArtists(); i++) {
		out << std::endl << i + 1 << ". " << e.artists[i];
	}
	delete[] temp;

	if(e.getDay() > 0 && e.getMonth() > 0 && e.getYear() > 0 ){
		out << std::endl << "Date(dd/mm/yyyy): " << e.getDay() << "/";
		if (e.getMonth() < 10) {
			out << "0" << e.getMonth() << "/";
		}
		else {
			out << e.getMonth() << "/";
		}
		out << e.getYear();
	}
	
	if(e.getMinute() >= 0 && e.getHour() > 0){
		out << std::endl << "Time: " << e.getHour();
		if (e.getMinute() < 10) {
			out << ":0" << e.getMinute();
		}
		else {
			out << ":" << e.getMinute();
		}
	}

	out << std::endl << std::endl << "------------------------" << std::endl << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Event& e) {
	char buffer[100]="";
	std::cout << std::endl << "Name of event: ";
	in.getline(buffer, 100);
	if (buffer != "") {
		if (e.name != nullptr) {
			delete[] e.name;
			e.name = nullptr;
		}
		e.name = new char[strlen(buffer) + 1];
		strcpy_s(e.name, strlen(buffer) + 1, buffer);
	}
	int temp;
	std::cout << "Number of artists: ";
	in >> temp;
	e.setNumArtists(temp);
	return in;
}

