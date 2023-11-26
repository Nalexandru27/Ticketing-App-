#pragma once
#include <iostream>
#include <string>
#include "DateTime.h"
#include "ManagementApp.h"

class Event : public DateTime {
private:
	char* name=nullptr;
	int numMoments = 0;
	std::string* moments = nullptr;
	int durationOfEachMoment[100] = {0};
public:
	Event();
	Event(const char* name, int numMoments, std::string* moments, int durationOfEachMoments[]);
	Event(const char* name, int numMoments, std::string* moments, int durationOfEachMoments[], int day, int month, int year, int hour, int minute);
	Event(const char* name, int numMoments, std::string* moments, int day, int month, int year);
	Event(const char* name, int day, int month, int year, int hour, int minute);
	Event(const char* name, int day, int month, int year);
	
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

	//add operators
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
};




