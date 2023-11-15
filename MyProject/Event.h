#pragma once
#include <iostream>
#include <string>
#include "DateTime.h"

class Event : public DateTime {
private:
	char* name=nullptr;
	int numArtists = 0;
	std::string* artists = nullptr;
	void setNumArtists(int noArtists);
	static int noEvent; // implement
public:
	Event();
	Event(const char* name, int numArtists, std::string* artists);
	Event(const char* name, int numArtists, std::string* artists, int day, int month, int year, int hour, int minute);
	Event(const char* name, int numArtists, std::string* artists, int day, int month, int year);
	Event(const char* name, int day, int month, int year, int hour, int minute);
	Event(const char* name, int day, int month, int year);
	
	~Event();

	void setName(const char* name);
	char* getName() const;

	int getNumArtists () const;

	void setArtists(const std::string* newArtists,int noArtists);
	std::string* getArtists() const;


	friend std::ostream& operator<<(std::ostream& out, const Event& e);
	friend std::istream& operator>>(std::istream& in, Event& e);
};




