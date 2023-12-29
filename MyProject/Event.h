#pragma once
#include <iostream>
#include <string>
#include "Location.h"
#include "DateTime.h"
#include "ManagementApp.h"

class Event{
private:
	char* name=nullptr;
	int numMoments = 0;
	std::string* moments = nullptr;
	int durationOfEachMoment[100] = {0};
	Location location;
	DateTime dateTime;
public:
	Event(){}
	/*Event(const char* name, )*/
	Event(const Event& e);

	~Event();


	void setDurationOfEachMoment(const int duration[]);
	const int* getDurationOfEachMoment() const;

	int getDurationOfTheEvent() const;

	void setName(const char* name);
	char* getName() const;

	int getNumMoments() const;
	void setNumMoments(int numMoments);

	void setMoments(const std::string* newMoments,int noMoments);
	std::string* getMoments() const;


	friend std::ostream& operator<<(std::ostream& out, const Event& e);
	friend std::istream& operator>>(std::istream& in, Event& e);

	//operator=
	Event& operator=(const Event& source);

	//operator[]
	int operator[](int index);

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
	void operator<=(const Event& e);

	//operator==
	bool operator==(const Event& e);
};




