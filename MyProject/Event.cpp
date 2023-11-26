#include "Event.h"
#include <string>
#include <iostream>
#include "ManagementApp.h"

//set name
void Event::setName(const char* name) {
	if (name != nullptr) {
		if (this->name != nullptr) {
			delete[] this->name;
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
	if (this->numMoments > 0 && this->moments != nullptr) {
		for (int i = 0; i < this->numMoments; i++) {
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
int Event::getDurationOfTheEvent() const{
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
	if (newMoments != nullptr) {
		if (this->moments != nullptr) {
			delete[]this->moments;
			this->moments = nullptr;
		}
		this->moments = new std::string[this->numMoments];
		for (int i = 0; i < this->numMoments; i++) {
			this->moments[i] = newMoments[i];
		}
	}
	else {
		throw std::exception("No moments provided");
	}
}

//get moments of the event
std::string* Event::getMoments() const{
	if (this->moments != nullptr && this->numMoments > 0) {
		std::string* copy = new std::string[this->numMoments];
		for (int i = 0; i < this->numMoments; i++) {
			copy[i] = this->moments[i];
		}
		return copy;
	}
	else {
		throw std::exception("No moments yet");
	}
}


//constructors
Event::Event() {
	ManagementApp::incrementNumEvents();
}

Event::Event(const char* name, int numMoments, std::string* moments,int durationOfEachMoment[]) {
	setName(name);
	setMoments(moments, numMoments);
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
	setDay(day);
	setMonth(month);
	setYear(year);
	ManagementApp::incrementNumEvents();
}

Event::Event(const char* name, int numMoments, std::string* artists, int durationOfEachMoment[], int day, int month, int year, int hour, int minute) {
	setName(name);
	setMoments(moments, numMoments);
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
	delete[] this->name;
	delete[] this->moments;
	ManagementApp::decrementNumEvents();
}

//operator <<
std::ostream& operator<<(std::ostream& out, const Event& e) {
	out << std::endl << std::endl << "------------------------" <<std::endl;

	out << std::endl << "WELCOME TO THE: " << e.getName();

	out << std::endl<<  "Number of moments: " << e.getNumMoments();

	std::string* temp = e.getMoments();
	for (int i = 0; i < e.getNumMoments(); i++) {
		out << std::endl << i + 1 << ". " << e.moments[i];
	}
	delete[] temp;
	out << std::endl << "Duration of each moment is: ";
	const int* aux = e.getDurationOfEachMoment();
	for (int i = 0; i < e.getNumMoments(); i++) {
		out << aux[i] << "min/ ";
	}
	out << std::endl << "Duration of whole event is: " << e.getDurationOfTheEvent();
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
	std::cout << std::endl << "Number of moments: ";
	in >> temp;
	e.setNumMoments(temp); 
	std::string aux;
	if (e.moments != nullptr) {
		delete[] e.moments;
		e.moments = nullptr;
	}
	e.moments = new std::string[temp];
	in.ignore();
	for (int i = 0; i < e.numMoments; i++) {
		std::cout << std::endl << "Moment " << i + 1 << ": ";
		std::getline(in,aux);
		if (aux.size() > 2 && aux.size() <= 30) {
			e.moments[i] = aux;
		}
	}
	std::cout << std::endl << "Duration of each moment:" ;
	for (int i = 0; i < e.numMoments; i++) {
		std::cout << std::endl << i+1 <<". ";
		in >> temp;
		if (temp > 0 && temp <= 180) {
			e.durationOfEachMoment[i] = temp;
		}
	}
	std::cout << std::endl << "Enter the date and time of the event ( ex: 6(day)7(month)2023(year) 18(hour) 5(minute); enter each on a line )";
	std::cout << std::endl << "Day:";
	in >> temp;
	e.setDay(temp);
	std::cout << std::endl << "Month:";
	in >> temp;
	e.setMonth(temp);
	std::cout << std::endl << "Year:";
	in >> temp;
	e.setYear(temp);
	std::cout << std::endl << "Hour:";
	in >> temp;
	e.setHour(temp);
	std::cout << std::endl << "Minute:";
	in >> temp;
	e.setMinute(temp);
	return in;
}

