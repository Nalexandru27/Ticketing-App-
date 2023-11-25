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
	int durationOfEachMoment[];
public:
	Event();
	Event(const char* name, int numMoments, std::string* moments, int durationOfEachMoments[50]);
	Event(const char* name, int numMoments, std::string* moments, int durationOfEachMoments[50], int day, int month, int year, int hour, int minute);
	Event(const char* name, int numMoments, std::string* moments, int day, int month, int year);
	Event(const char* name, int day, int month, int year, int hour, int minute);
	Event(const char* name, int day, int month, int year);
	
	~Event();

	void setDurationOfEachMoment(int duration[]);
	const int* getDurationOfEachMoment() const;

	int getDurationOfTheEvent();

	void setName(const char* name);
	char* getName() const;

	int getNumMoments() const;
	void setNumMoments(int numMoments);

	void setMoments(const std::string* newMoments,int noMoments);
	std::string* getMoments() const;


	friend std::ostream& operator<<(std::ostream& out, const Event& e);
	friend std::istream& operator>>(std::istream& in, Event& e);

	//add operators

};




