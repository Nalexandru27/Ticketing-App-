//#include "Event.h"
//#include <string>
//#include <iostream>
//#include "ManagementApp.h"
//
////set name
//void Event::setName(const char* name) {
//	if (name != nullptr) {
//		if (this->name != nullptr) {
//			delete[] this->name;
//			this->name = nullptr;
//		}
//		this->name = new char[strlen(name) + 1];
//		strcpy_s(this->name, strlen(name) + 1, name);
//	}
//	else {
//		throw std::exception("No name provided for the event");
//	}
//}
////get name
//char* Event::getName() const{
//	if (this->name != nullptr) {
//		char* copy = new char[strlen(this->name) + 1];
//		strcpy_s(copy, strlen(this->name) + 1, this->name);
//		return copy;
//	}
//	else {
//		throw std::exception("No name of the event yet");
//	}
//}
//
////set duration of each moment
//void Event::setDurationOfEachMoment(const int duration[]) {
//	if (this->numMoments > 0 && this->moments != nullptr) {
//		for (int i = 0; i < this->numMoments; i++) {
//			this->durationOfEachMoment[i] = duration[i];
//		}
//	}
//	else {
//		throw std::exception("Could not set the duration of each moment because there are no moments planned yet!");
//	}
//}
//
////get duration of each moment
//const int* Event::getDurationOfEachMoment() const{
//	return durationOfEachMoment;
//}
//
////get duration of the whole event
//int Event::getDurationOfTheEvent() const{
//	int sum = 0;
//	for (int i = 0; i < this->getNumMoments(); i++) {
//		sum += this->durationOfEachMoment[i];
//	}
//	return sum;
//}
//
////set the number of moments
//void Event::setNumMoments(int newNumMoments) {
//	if (newNumMoments > 0) {
//		this->numMoments = newNumMoments;
//	}
//	else {
//		throw std::exception("Provide a positive number of moments!");
//	}
//}
//
////get number of moments
//int Event::getNumMoments() const{
//	return this->numMoments;
//}
//
////set moments of the event
//void Event::setMoments(const std::string* newMoments, int noMoments) {
//	setNumMoments(noMoments);
//	if (newMoments != nullptr) {
//		if (this->moments != nullptr) {
//			delete[]this->moments;
//			this->moments = nullptr;
//		}
//		this->moments = new std::string[this->numMoments];
//		for (int i = 0; i < this->numMoments; i++) {
//			this->moments[i] = newMoments[i];
//		}
//	}
//	else {
//		throw std::exception("No moments provided");
//	}
//}
//
////get moments of the event
//std::string* Event::getMoments() const{
//	if (this->moments != nullptr && this->numMoments > 0) {
//		std::string* copy = new std::string[this->numMoments];
//		for (int i = 0; i < this->numMoments; i++) {
//			copy[i] = this->moments[i];
//		}
//		return copy;
//	}
//	else {
//		throw std::exception("No moments yet");
//	}
//}
//
//
////constructors
//Event::Event() {
//	ManagementApp::incrementNumEvents();
//}
//
//
//
////destructor
//Event::~Event() {
//	delete[] this->name;
//	delete[] this->moments;
//	ManagementApp::decrementNumEvents();
//}
//
//Event::Event(const Event& e) {
//	this->setName(e.getName());
//	this->setNumMoments(e.getNumMoments());
//	this->setMoments(e.getMoments(), this->numMoments);
//	this->setDurationOfEachMoment(e.getDurationOfEachMoment());
//	this->location = e.location;
//	this->dateTime = e.dateTime;
//	ManagementApp::incrementNumEvents();
//}
//
////operator <<
//std::ostream& operator<<(std::ostream& out, const Event& e) {
//	out << std::endl << std::endl << "------------------------" <<std::endl;
//
//	out << std::endl << "WELCOME TO THE: " << e.getName();
//
//	out << std::endl<<  "Number of moments: " << e.getNumMoments();
//
//	std::string* temp = e.getMoments();
//	for (int i = 0; i < e.getNumMoments(); i++) {
//		out << std::endl << i + 1 << ". " << e.moments[i];
//	}
//	delete[] temp;
//	out << std::endl << "Duration of each moment is: ";
//	const int* aux = e.getDurationOfEachMoment();
//	for (int i = 0; i < e.getNumMoments(); i++) {
//		out << aux[i] << "min/ ";
//	}
//
//	out << std::endl << "Duration of whole event is: " << e.getDurationOfTheEvent();
//
//	if(e.dateTime.getDay() > 0 && e.dateTime.getMonth() > 0 && e.dateTime.getYear() > 0 ){
//		out << std::endl << "Date(dd/mm/yyyy): " << e.dateTime.getDay() << "/";
//		if (e.dateTime.getMonth() < 10) {
//			out << "0" << e.dateTime.getMonth() << "/";
//		}
//		else {
//			out << e.dateTime.getMonth() << "/";
//		}
//		out << e.dateTime.getYear();
//	}
//	
//	if(e.dateTime.getMinute() >= 0 && e.dateTime.getHour() > 0){
//		out << std::endl << "Time: " << e.dateTime.getHour();
//		if (e.dateTime.getMinute() < 10) {
//			out << ":0" << e.dateTime.getMinute();
//		}
//		else {
//			out << ":" << e.dateTime.getMinute();
//		}
//	}
//	out << std::endl << std::endl << "------------------------" << std::endl << std::endl;
//	return out;
//}
//
////operator >>
//std::istream& operator>>(std::istream& in, Event& e) {
//	char buffer[100]="";
//	std::cout << std::endl << "Name of event: ";
//	in.getline(buffer, 100);
//	if (buffer != "") {
//		if (e.name != nullptr) {
//			delete[] e.name;
//			e.name = nullptr;
//		}
//		e.name = new char[strlen(buffer) + 1];
//		strcpy_s(e.name, strlen(buffer) + 1, buffer);
//	}
//	int temp;
//	std::cout << std::endl << "Number of moments: ";
//	in >> temp;
//	e.setNumMoments(temp); 
//	std::string aux;
//	if (e.moments != nullptr) {
//		delete[] e.moments;
//		e.moments = nullptr;
//	}
//	e.moments = new std::string[temp];
//	in.ignore();
//	for (int i = 0; i < e.numMoments; i++) {
//		std::cout << std::endl << "Moment " << i + 1 << ": ";
//		std::getline(in,aux);
//		if (aux.size() > 2 && aux.size() <= 30) {
//			e.moments[i] = aux;
//		}
//	}
//	std::cout << std::endl << "Duration of each moment(minutes):" ;
//	for (int i = 0; i < e.numMoments; i++) {
//		std::cout << std::endl << i+1 <<". ";
//		in >> temp;
//		if (temp > 0 && temp <= 180) {
//			e.durationOfEachMoment[i] = temp;
//		}
//	}
//	std::cout << std::endl << "Enter the date and time of the event ( ex: 6(day)7(month)2023(year) 18(hour) 5(minute); enter each on a line )";
//	std::cout << std::endl << "Day:";
//	in >> temp;
//	e.dateTime.setDay(temp);
//	std::cout << std::endl << "Month:";
//	in >> temp;
//	e.dateTime.setMonth(temp);
//	std::cout << std::endl << "Year:";
//	in >> temp;
//	e.dateTime.setYear(temp);
//	std::cout << std::endl << "Hour:";
//	in >> temp;
//	e.dateTime.setHour(temp);
//	std::cout << std::endl << "Minute:";
//	in >> temp;
//	e.dateTime.setMinute(temp);
//	return in;
//}
//
////operator=
//Event& Event::operator=(const Event& source) {
//	if (this != &source) {
//		if (source.name != nullptr) {
//			this->setName(source.name);
//		}
//		else {
//			throw std::exception("source object has no valid name field");
//		}
//		this->setNumMoments(source.getNumMoments());
//		this->setMoments(source.getMoments(), this->numMoments);
//		this->setDurationOfEachMoment(source.getDurationOfEachMoment());
//		this->dateTime.setDay(source.dateTime.getDay());
//		this->dateTime.setMonth(source.dateTime.getMonth());
//		this->dateTime.setYear(source.dateTime.getYear());
//		this->dateTime.setHour(source.dateTime.getHour());
//		this->dateTime.setMinute(source.dateTime.getMinute());
//	}
//	return *this;
//}
//
////operator[]
//int Event::operator[](int index) {
//	if (index >= 0 && index < this->getNumMoments()) {
//		return this->durationOfEachMoment[index];
//	}
//	else {
//		throw std::exception("Invalid index");
//	}
//}
////operator+
//int Event::operator+(int value) {
//	if (value <= 3) {
//		return this->dateTime.getHour() + value;
//	}
//	else {
//		throw std::exception("Change too big for the hour of the event, maximum 3 hours of delay!");
//	}
//}
//int operator+(int value, Event& e) {
//	if (value <= 3) {
//		return e.dateTime.getHour() + value;
//	}
//	else {
//		throw std::exception("Change too big for the hour of the event, maximum 3 hours of delay!");
//	}
//}
//
////operator-- predecrementation
//Event Event::operator--() {
//	--this->durationOfEachMoment[this->getNumMoments() - 1];
//	return *this;
//}
//
////operator-- postdecrementation
//Event Event::operator--(int) {
//	if (this->numMoments == 0) {
//		return *this;
//	}
//	Event temp = *this;
//	this->numMoments--;
//	std::string* newMomentsArray = new std::string[this->numMoments];
//	for (int i = 0; i < this->numMoments; i++) {
//		newMomentsArray[i] = temp.moments[i];
//	}
//	delete[] this->moments;
//	this->moments = newMomentsArray;
//	return temp;
//}
//
//
////operator cast (int)
//Event::operator int() {
//	return this->getNumMoments();
//}
//
////operator!
//bool Event::operator!() {
//	return this->numMoments > 0;
//}
//
////operator<=
//void Event::operator<=(const Event& e) {
//	if (this->getDurationOfTheEvent() <= e.getDurationOfTheEvent()) {
//		std::cout << std::endl << "First event takes less or the same time as second one";
//	}
//	else {
//		std::cout << std::endl << "Second event takes longer";
//	}
//}
//
//bool Event::operator==(const Event& e) {
//	return e.dateTime.getDay() == this->dateTime.getDay();
//}