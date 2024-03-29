#include "Event.h"
#include <string>
#include <iostream>
#include <fstream>
#include "ClassUtils.h"

Event::Event(){}


Event::~Event() {
	if (this->name != nullptr) {
		delete[] this->name;
		this->name = nullptr;
	}
	if (this->tickets != nullptr) {
		delete[]this->tickets;
		this->tickets = nullptr;
	}
}

Event::Event(const char* name, int duration, Location& l, DateTime& dt)
{
	if (name != nullptr) {
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	setDuration(duration);
	this->location = l;
	//take the no of zones and for each zone take the number of rows and for every seat set the price 
	//every seat must have a ticket with a unique id
	//tickets from a zone have the same zoneName, category and price and a unique seat from a row
	if (l.getLocationNoSeats() > 0 && l.getZones()!=nullptr) {
		this->noTickets = l.getLocationNoSeats();
		this->tickets = new Ticket[this->noTickets];
		Zone* temp = l.getZones();
		for (int i = 0; i < l.getNoZones(); i++) {
			int* aux = temp[i].getSeatsPerRows();
			for (int j = 0; j < temp[i].getNoRows(); j++) {
				for (int k = 0; k < aux[j]; k++) {
					this->tickets[i].setZoneName(temp[i].getName());
					this->tickets[i].setSeat(k + 1);
					this->tickets[i].setRow(j + 1);
					this->tickets[i].setCategory(temp[i].getCategory());
					this->tickets[i].setPrice(temp[i].getPrice());
				}
			}
			delete[] aux;
		}
		delete[] temp;
	}
	else {
		throw std::exception("Cannot set the tickets in the constructor");
	}
	this->dateTime = dt;
}

char* Event::getName() const{
	if (this->name != nullptr) {
		char* copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);
		return copy;
	}
	else {
		throw std::exception("Cannot get the name of the event because it wasnt announced yet");
	}
}

void Event::setDuration(int duration) {
	if (duration >= 10 && duration <= 300) {
		this->duration = duration;
	}
	else {
		throw std::exception("Cannot set duration of the event because the value is invalid");
	}
}

void Event::setName(const char* name)
{
	if (name != nullptr) {
		if (this->name != nullptr) {
			delete[]this->name;
			this->name = nullptr;
		}
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	else {
		throw std::exception("Cannot set the name");
	}
}

int Event::getDuration() {
	return this->duration;
}

int Event::getNoTickets() {
	return this->noTickets;
}

void Event::setNoTicketsAndTickets(int noTickets, Ticket* tickets){
	if (noTickets > 0 && noTickets < 100001 && tickets != nullptr) {
		this->noTickets = noTickets;
		if (this->tickets != nullptr) {
			delete[] this->tickets;
			this->tickets = nullptr;
		}
		this->tickets = new Ticket[this->noTickets];
		for (int i = 0; i < noTickets; i++) {
			this->tickets[i] = tickets[i];
		}
	}
}

std::ostream& operator<<(std::ostream& out,const Event& e) {
	out << std::endl << "Event name is: " << e.name;
	out << std::endl << "Duration of the event is: " << e.duration <<"min";
	out << std::endl << "The event will take place at " << e.location.getName() << ", address: " << e.location.getAddress();
	out << e.dateTime;
	out << std::endl << "The event has available " << e.noTickets << " tickets.";
	return out;
}

int operator+(int value, Event& e)
{
	if (value > 0) {
		return value + e.duration;
	}
	else {
		throw std::exception("cannot make the addition, must add a positive value");
	}
}

Event::Event(const Event& e){
	setName(e.name);
	setDuration(e.duration);
	setNoTicketsAndTickets(e.noTickets, e.tickets);
	this->location = e.location;
	this->dateTime = e.dateTime;
}

Event& Event::operator=(const Event& e) {
	setName(e.name);
	setDuration(e.duration);
	setNoTicketsAndTickets(e.noTickets, e.tickets);
	this->location = e.location;
	this->dateTime = e.dateTime;
	return *this;
}

float Event::operator[](int index)
{
	if (this->tickets != nullptr && index > 0 && index <= noTickets) {
		return this->tickets[index].getPrice();
	}
	else {
		throw std::exception("cannot return the value at that index");
	}
}

int Event::operator+(int value)
{
	if (value > 0) {
		return this->duration + value;
	}
	else {
		throw std::exception("cannot make the addition, must add a positive value");
	}
}

Event Event::operator--()
{
	--this->noTickets;
	return *this;
}

Event Event::operator--(int)
{
	Event copy = *this;
	this->noTickets--;
	return copy;
}

Event::operator int()
{
	return this->duration;
}

bool Event::operator!()
{
	return !this->name;
}

bool Event::operator<=(const Event& e)
{
	return this->noTickets <= e.noTickets;
}

bool Event::operator==(const Event& e)
{
	return this->duration == e.duration;
}


void Event::saveEventData(std::ofstream& file) 
{
	if (!file.is_open()) {
		throw std::exception("file is not opened");
	}
	int nameSize = strlen(this->name)+1;
	file.write((char*)&nameSize, sizeof(int));
	file.write(this->name, sizeof(char) * nameSize);
	file.write((char*)&this->duration, sizeof(int));
	file.write((char*)&this->noTickets, sizeof(int));
	for (int i = 0; i < this->noTickets; i++) {
		tickets[i].saveTicketData(file);
	}
	location.saveDataLocation(file);
	dateTime.saveDateTime(file);
}

void Event::getEventData(std::ifstream& file) {
	if (!file.is_open()) {
		throw std::exception("file is not opened");
	}
	int nameSize = 0;
	file.read((char*)&nameSize, sizeof(int));
	if (this->name != nullptr) {
		delete[]this->name;
		this->name = nullptr;
	}
	this->name = new char[nameSize];
	file.read(this->name, sizeof(char) * nameSize);
	file.read((char*)&this->duration, sizeof(int));
	file.read((char*)&this->noTickets, sizeof(int));
	if (this->tickets != nullptr) {
		delete[] this->tickets;
		this->tickets = nullptr;
	}
	this->tickets = new Ticket[this->noTickets];
	for (int i = 0; i < this->noTickets; i++) {
		this->tickets[i].getTicketRaport(file);
	}
	this->location.readDataLocation(file);
	this->dateTime.readDateTime(file);
}







