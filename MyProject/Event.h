#pragma once
#include <iostream>
#include <string>
#include "Location.h"
#include "DateTime.h"
#include "ManagementApp.h"
#include "Ticket.h"

class Event{
private:
	const char* name = nullptr;
	int duration = 0;
	int noTickets = 0;
	Ticket* tickets = nullptr;
	Location location;
	DateTime dateTime;
public:
	//default constructor
	Event();
	
	//constructor
	Event(const char* name, int duration, Location l, DateTime dt);

	//copy constructor
	Event(const Event& e);

	//destructor
	~Event();

	//get name
	char* getName() const;

	//get, set duration
	int getDuration();
	void setDuration(int duration);

	//get, set tickets
	int getNoTickets();
	Ticket* getTickets();
	void setNoTicketsAndTickets(int noTickets,Ticket* tickets);

	friend std::ostream& operator<<(std::ostream& out,const Event& e);
	friend std::istream& operator>>(std::istream& in, Event& e);

	//operator=
	Event& operator=(const Event& e);

	//operator[]
	float operator[](int index);

	//operator+
	int operator+(int value);
	friend int operator+(int value, Event& e);

	//operator-- predecrementation
	Event operator--();

	//operator-- postdecrementation
	Event operator--(int);

	//operator cast (int)
	operator int();

	//operator!
	bool operator!();

	//operator<=
	bool operator<=(const Event& e);

	//operator==
	bool operator==(const Event& e);
};




