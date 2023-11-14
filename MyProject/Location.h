#pragma once
#include <iostream>
#include <string>


class Location {
private:
	int noRows = 0;
	int* seatsPerRow = nullptr;
	char* address = nullptr;
	int maxNoSeats = 0;
	//zones?
	static int noLocations;
	std::string* zones = nullptr;
	int numZones = 0;
public:
	//setters & getters
	void setNoRows(int newNoRows);
	int getNoRows();

	void setSeatsPerRow(int* seatsPerRow);
	int* getSeatsPerRow();

	void setAddress(const char* newAddress);
	char* getAddress();

	void setMaxNoSeats(int newMaxNoSeats);
	int getMaxNoSeats();

	void setZones(const std::string* newZones,int size);
	std::string* getZones();

	int getNumZones();

	int static getNoLocations();

	//constructors
	Location();
	Location(int noRows, int* seatsPerRow, const char* address, int maxNoSeats, std::string* zones, int noZones);
	Location(int noRows, int* seatsPerRow, const char* address, std::string* zones, int noZones);

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
	int& operator[](int row);

	//operator/
	int operator/(int seats);

	//operator++
	void operator++();

	void operator++(int);

	//operator!
	bool operator!();

	//operator<=
	bool operator<=(const Location& source);

	//operator==
	bool operator==(const Location& source);
};
