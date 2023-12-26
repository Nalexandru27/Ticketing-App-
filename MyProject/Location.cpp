#include "Location.h"
#include <iostream>
#include <string>
#include "ManagementApp.h"



void Location::setAddress(const char* newAddress) {
	if (newAddress == nullptr) {
		throw std::exception("You didn't provide an adrress");
	}
	else {
		if (this->address != nullptr) {
			delete[] this->address;
			this->address = nullptr;
		}
		this->address = new char[strlen(newAddress) + 1];
		strcpy_s(this->address, strlen(newAddress) + 1, newAddress);
	}
}

char* Location::getAddress() {
	if (this->address == nullptr) {
		throw std::exception("There is no address yet");
	}
	else {
		char* copy = new char[strlen(this->address) + 1];
		strcpy_s(copy, strlen(this->address) + 1, this->address);
		return copy;
	}
}


Location::Location() {
	ManagementApp::incrementNumLocations();
}
}
}


Location::Location(int noRows, int* seatsPerRow, const char* address, int maxNoSeats,std::string* zones,int noZones) {
	setNoRows(noRows);
	setSeatsPerRow(seatsPerRow);
	setAddress(address);
	setMaxNoSeats(maxNoSeats);
	setZones(zones, noZones);
	ManagementApp::incrementNumLocations();
}

Location::Location(int noRows, int* seatsPerRow, const char* address, std::string* zones, int noZones) {
	setNoRows(noRows);
	setSeatsPerRow(seatsPerRow);
	setAddress(address);
	for (int i = 0; i < this->noRows; i++) {
		this->maxNoSeats += this->seatsPerRow[i];
	}
	setZones(zones, noZones);
	ManagementApp::incrementNumLocations();
}

Location::Location(const Location& source) {
	setNoRows(source.noRows);
	setSeatsPerRow(source.seatsPerRow);
	setAddress(source.address);
	setMaxNoSeats(source.maxNoSeats);
	setZones(source.zones, source.numZones);
	ManagementApp::incrementNumLocations();
}

Location::~Location() {
	delete[] this->address;
	delete[] this->seatsPerRow;
	delete[] this->zones;
	ManagementApp::decrementNumLocations();
}

//operator =
void Location::operator=(const Location& source) {
	setNoRows(source.noRows);
	setSeatsPerRow(source.seatsPerRow);
	setAddress(source.address);
	setMaxNoSeats(source.maxNoSeats);
	setZones(source.zones, source.numZones);
}

//operator <<
std::ostream& operator<<(std::ostream& out, const Location& location) {
	if (location.address != nullptr) {
		out << "Location address is: " << location.address << std::endl;
	}
	if (location.seatsPerRow != nullptr) {
		out << "Location has: " << location.noRows << " rows" << std::endl;
		for (int i = 0; i < location.noRows; i++) {
			out << "Row " << i + 1 << " has " << location.seatsPerRow[i] << std::endl;
		}
	}
	out << "Location has a maximum seats of: " << location.maxNoSeats << std::endl;
	if (location.zones != nullptr) {
		out << "Locations zones are: " << std::endl;
		for (int i = 0; i < location.numZones; i++) {
			out << location.zones[i] << "   ";
		}
		out << std::endl;
	}
	return out;
}

//operator >>
std::istream& operator>>(std::istream& in, Location& location) {
	std::cout << std::endl << "What is the location Address? Please provide the country, city, street and number of the street:" << std::endl;
	char temp[100] = "";
	in.getline(temp, sizeof(temp));
	if (strlen(temp) < 15) {
		throw std::exception("The address is too short. Please provide more information.");
	}
	else {
		if (location.address != nullptr) {
			delete[] location.address;
			location.address = nullptr;
		}
		location.address = new char[strlen(temp) + 1];
		strcpy_s(location.address, strlen(temp) + 1, temp);
	}
	std::cout << "Enter the number of rows: ";
	int noRows2 = 0;
	in >> noRows2;
	location.setNoRows(noRows2);
	int* seatsPerRow2 = new int[noRows2];
	for (int i = 0; i < noRows2; i++) {
		std::cout << "Please provide the number of seats for row[" << i + 1 << "]=";
		in >> seatsPerRow2[i];
	}
	location.setSeatsPerRow(seatsPerRow2);
	std::cout << "Enter the maxim number of seats for this location: ";
	in >> location.maxNoSeats;
	std::cout << "Enter the number of zones for this location: ";
	in >> location.numZones;
	if (location.numZones > 0) {
		location.zones = new std::string[location.numZones+1];
		in.ignore();
		for (int i = 0; i < location.numZones; i++) {
			std::cout << "Please enter zone[" << i + 1 << "]: ";
			std::string zone;
			std::getline(in, zone);
			location.zones[i] = zone;
		}
	}
	
	return in;
}


//operator[]
int& Location::operator[](int row) {
	if (this->seatsPerRow != nullptr && row <= this->noRows - 1) {
		return this->seatsPerRow[row];
	}
	else {
		throw std::exception("Couldn't provide the value at that index");
	}
}

//operator/ object-int
int Location::operator/(int seats) {
	if (this->noRows > 0) {
		return this->noRows / seats;
	}
	else {
		throw std::exception("Can't divide 0");
	}
}

//operator / int-object
int operator/(int value, Location& location) {
	return value / location.getNoRows();
}


//operator++ pre
Location Location::operator++() {
	++this->noRows;
	return *this;
}

//operator++ post
Location Location::operator++(int) {
	Location copy = *this;
	this->noRows++;
	return copy;
}

//operator!
bool Location::operator!() {
	return !this->address; //return true is address = nullptr, false if address exists
}

//operator<=
bool Location::operator<=(const Location& source) {
	return this->maxNoSeats <= source.maxNoSeats;
}

//operator==
bool Location::operator==(const Location& source) {
	return this->noRows == source.noRows;
}

//operator+=
void Location::operator+=(int value) {
	this->maxNoSeats += value;
}

//operator cast
Location::operator int() {
	return this->getNumZones();
}