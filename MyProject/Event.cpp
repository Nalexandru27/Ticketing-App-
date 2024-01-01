#include "Event.h"
#include <string>
#include <iostream>

Event::Event():name("none"){}

Event::~Event() {
	if (this->tickets != nullptr) {
		delete[] this->tickets;
		this->tickets = nullptr;
	}
}

Event::Event(const char* name, int duration, Location l, DateTime dt) :name(name)
{
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
			for (int j = 0; j < temp[i].getNoRows(); j++) {
				int* aux = temp[i].getSeatsPerRows();
				for (int k = 0; k < aux[j]; k++) {
					this->tickets[i].setZoneName(temp[i].getName());
					this->tickets[i].setSeat(k + 1);
					this->tickets[i].setRow(j + 1);
					this->tickets[i].setCategory(temp[i].getCategory());
					this->tickets[i].setPrice(temp[i].getPrice());
				}
			}
		}
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
	if (duration >= 30 && duration <= 300) {
		this->duration = duration;
	}
	else {
		throw std::exception("Cannot set duration of the event because the value is invalid");
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
}

Event::Event(const Event& e):name(e.name) {
	setDuration(e.duration);
	setNoTicketsAndTickets(e.noTickets, e.tickets);
	this->location = e.location;
	this->dateTime = e.dateTime;
}

Event& Event::operator=(const Event& e) {
	setDuration(e.duration);
	setNoTicketsAndTickets(e.noTickets, e.tickets);
	this->location = e.location;
	this->dateTime = e.dateTime;
	return *this;
}

int Event::operator[](int index)
{
	if (this->tickets != nullptr && index > 0 && index <= noTickets) {
		return this->tickets[index].getPrice();
	}
}

int Event::operator+(int value)
{
	if (value > 0) {
		return this->duration + value;
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








