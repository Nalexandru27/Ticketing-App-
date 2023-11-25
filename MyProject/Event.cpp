#include "Event.h"
#include <string>
#include <iostream>
#include "ManagementApp.h";

//set name
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
//get name
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

//set duration of each moment
void Event::setDurationOfEachMoment(int duration[]) {
	if (numMoments > 0) {
		for (int i = 0; i < numMoments; i++) {
			this->durationOfEachMoment[i] = duration[i];
		}
	}
	else {
		throw std::exception("Could not set the duration of each moment because there are no moments planned yet!");
	}
}

//get duration of each moment
const int* Event::getDurationOfEachMoment() const{
	return durationOfEachMoment;
}

//get duration of the whole event
int Event::getDurationOfTheEvent() {
	int sum = 0;
	for (int i = 0; i < this->getNumMoments(); i++) {
		sum += this->durationOfEachMoment[i];
	}
	return sum;
}

//set the number of moments
void Event::setNumMoments(int newNumMoments) {
	if (newNumMoments > 0) {
		this->numMoments = newNumMoments;
	}
	else {
		throw std::exception("Provide a positive number of moments!");
	}
}

//get number of moments
int Event::getNumMoments() const{
	if (this->numMoments > 0) {
		return this->numMoments;
	}
	else {
		throw std::exception("No moments yet");
	}
}

//set moments of the event
void Event::setMoments(const std::string* newMoments, int noMoments) {
	setNumMoments(noMoments);
	if (newMoments != nullptr && noMoments >= 0) {
		if (this->moments != nullptr) {
			delete[]this->moments;
			this->moments = nullptr;
		}
		this->moments = new std::string[noMoments];
		for (int i = 0; i < noMoments; i++) {
			this->moments[i] = newMoments[i];
		}
	}
	else {
		throw std::exception("No artists provided");
	}
}

//get moments of the event
std::string* Event::getMoments() const{
	if (this->moments != nullptr) {
		std::string* copy = new std::string[this->getNumMoments()];
		for (int i = 0; i < this->getNumMoments(); i++) {
			copy[i] = this->moments[i];
		}
		return copy;
	}
	else {
		throw std::exception("No artists yet");
	}
}


//constructors
Event::Event() {
	ManagementApp::incrementNumEvents();
}

Event::Event(const char* name, int numMoments, std::string* moments, int durationOfEachMoment[]) {
	setName(name);
	setMoments(moments, numMoments);
	delete[] moments;
	setDurationOfEachMoment(durationOfEachMoment);
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

Event::Event(const char* name, int numMoments, std::string* moments, int day, int month, int year) {
	setName(name);
	setMoments(moments, numMoments);
	delete[] moments;
	setDay(day);
	setMonth(month);
	setYear(year);
	ManagementApp::incrementNumEvents();
}

Event::Event(const char* name, int numMoments, std::string* artists, int durationOfEachMoment[], int day, int month, int year, int hour, int minute) {
	setName(name);
	setMoments(moments, numMoments);
	delete[] artists;
	setDurationOfEachMoment(durationOfEachMoment);
	setDay(day);
	setMonth(month);
	setYear(year);
	setHour(hour);
	setMinute(minute);
	ManagementApp::incrementNumEvents();
}

//destructor
Event::~Event() {
	delete[] name;
	delete[] moments;
	ManagementApp::decrementNumEvents();
}

//operator <<
std::ostream& operator<<(std::ostream& out, const Event& e) {
	out << std::endl << std::endl << "------------------------" <<std::endl;

	out << std::endl << "Name of the event: " << e.getName();

	out << std::endl<<  "Number of artists: " << e.getNumMoments();

	std::string* temp = e.getMoments();
	for (int i = 0; i < e.getNumMoments(); i++) {
		out << std::endl << i + 1 << ". " << e.moments[i];
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

//operator >>
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
	e.setNumMoments(temp);
	return in;
}

