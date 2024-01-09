#pragma once
#include "Zones.h"
#include <iostream>
#include <string>


class Location {
protected:
	std::string name = "";
	char* address = nullptr;
	int noZones = 0;
	Zone* zones = nullptr;

public:
	//setters & getters

	void setAddress(const char* newAddress);
	char* getAddress() const;

	void setName(std::string name);
	std::string getName() const;

	void setNoZonesAndZones(int noZones,Zone* zones);
	int getNoZones() const;
	Zone* getZones() const;

	int getLocationNoSeats() const;
	
	virtual void displayInfo();

	void saveDataLocation(std::ofstream& file);
 
	//constructors
	Location();
	Location(std::string name, const char* address, int noZones, Zone* zones);

	//copy constructor
	Location(const Location& source);

	//destructor
	~Location();

	//operator=
	void operator=(const Location& source);

	//operator<<,>>
	friend std::ostream& operator<<(std::ostream& out, const Location& location);
	friend std::istream& operator>>(std::istream& in, Location& location);

	//operator[]
	int operator[](int zoneIndex);


	//operator/ object-int
	int operator/(int row);

	//operator int-object
	friend int operator/(int value, Location& location);

	//operator++ pre
	Location operator++();

	//operator++ post
	Location operator++(int);

	//operator!
	bool operator!();

	//operator<=
	bool operator<=(const Location& source);

	//operator==
	bool operator==(const Location& source);

	//operator+=
	void operator+=(int value);

	//operator cast
	explicit operator int();
};

