#include "Location.h"
#include <iostream>
#include <string>

int Location::noLocations = 0;

void Location::setNoRows(int newNoRows) {
	if (newNoRows > 0) {
		this->noRows = newNoRows;
	}
	else {
		throw std::exception("Invalid number of rows. Must be greater than 0.");
	}
}

int Location::getNoRows() {
	return this->noRows;
}

void Location::setSeatsPerRow(int* seatsPerRow) {
	if (seatsPerRow == nullptr) {
		throw std::exception("Invalid number of seats per row.");
	}
	else {
		if (this->seatsPerRow != nullptr) {
			delete[] this->seatsPerRow;
			this->seatsPerRow = nullptr;
		}
		this->seatsPerRow = new int[this->noRows];
		for (int i = 0; i < this->noRows; ++i) {
			this->seatsPerRow[i] = seatsPerRow[i];
		}
	}
}

int* Location::getSeatsPerRow() {
	if (this->seatsPerRow == nullptr || this->noRows == 0) {
		throw std::exception("Can't provide number of seats per row because their is missing data");
	}
	else {
		int* copy = new int[this->noRows];
		memcpy(copy, this->seatsPerRow, noRows);
		return copy;
	}
}


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


void Location::setMaxNoSeats(int newMaxNoSeats) {
	if (newMaxNoSeats > 0) {
		this->maxNoSeats = newMaxNoSeats;
	}
	else {
		throw std::exception("Invalid number of max seats. Must be greater than 0.");
	}
}

int Location::getMaxNoSeats() {
	return this->maxNoSeats;
}

int Location::getNoLocations() {
	return Location::noLocations;
}

Location::Location() {
	this->noLocations++;
}

void Location::setZones(const std::string* newZones,int size) {
	if (newZones == nullptr) {
		throw std::exception("Provide data for the Zones/Areas of the location!");
	}
	else {
		if (this->zones != nullptr) {
			delete[]zones;
			this->zones = nullptr;
		}
		if (size > 0) {
			this->numZones = size;
		}
		else {
			throw std::exception("Invalid number of zones for location");
		}
		this->zones = new std::string[size];
		for (size_t i = 0; i < size; i++) {
			this->zones[i] = newZones[i];
		}
	}
}

std::string* Location::getZones() {
	if (this->zones == nullptr) {
		throw std::exception("No data available for zones.");
	}
	else {
		std::string* copy = new std::string[getNumZones()];
		for (int i = 0; i < getNumZones(); i++) {
			copy[i] = this->zones[i];
		}
		return copy;
	}
}

int Location::getNumZones() {
	return this->numZones;
}

Location::Location(int noRows, int* seatsPerRow, const char* address, int maxNoSeats,std::string* zones,int noZones) {
	this->noLocations++;
	setNoRows(noRows);
	setSeatsPerRow(seatsPerRow);
	setAddress(address);
	setMaxNoSeats(maxNoSeats);
	setZones(zones, noZones);
}

Location::Location(int noRows, int* seatsPerRow, const char* address, std::string* zones, int noZones) {
	this->noLocations++;
	setNoRows(noRows);
	setSeatsPerRow(seatsPerRow);
	setAddress(address);
	for (int i = 0; i < this->noRows; i++) {
		this->maxNoSeats += this->seatsPerRow[i];
	}
	setZones(zones, noZones);
}

Location::Location(const Location& source) {
	this->noLocations++;
	setNoRows(source.noRows);
	setSeatsPerRow(source.seatsPerRow);
	setAddress(source.address);
	setMaxNoSeats(source.maxNoSeats);
	setZones(source.zones, source.numZones);
}

Location::~Location() {
	this->noLocations--;
	delete[] this->address;
	delete[] this->seatsPerRow;
	delete[] this->zones;
}


void Location::operator=(const Location& source) {
	setNoRows(source.noRows);
	setSeatsPerRow(source.seatsPerRow);
	setAddress(source.address);
	setMaxNoSeats(source.maxNoSeats);
	setZones(source.zones, source.numZones);
}


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

//operator/
int Location:: operator/(int seats) {
	if (this->noRows > 0) {
		return this->noRows / seats;
	}
	else {
		throw std::exception("Can't divide 0");
	}
}

//operator++
void Location::operator++() {
	++this->noRows;
}

void Location::operator++(int) {
	this->noRows++;
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
