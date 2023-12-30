#include "Event.h"
#include <string>
#include <iostream>
using namespace std;


Event::Event():name("none"){}

Event::Event(const char* name, int duration, int noTickets, Ticket* tickets, Location l, DateTime dt):name(name)
{
	setDuration(duration);
	if (noTickets > 0 && noTickets < 100001 && tickets != nullptr) {
		this->noTickets = 
	}
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




