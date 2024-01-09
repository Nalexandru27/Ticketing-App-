#include "Location.h"
#include <iostream>
#include <string>
#include "ManagementApp.h"
#include <fstream>
#include "ClassUtils.h"
//set adrress
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

//get address
char* Location::getAddress() const{
	if (this->address == nullptr) {
		throw std::exception("There is no address yet");
	}
	else {
		char* copy = new char[strlen(this->address) + 1];
		strcpy_s(copy, strlen(this->address) + 1, this->address);
		return copy;
	}
}

//set name
void Location::setName(const std::string name)
{
	if (name.size() > 3 && name.size() < 25) {
		this->name = name;
	}
	else {
		throw std::exception("Zone name is not valid");
	}
}

//get name
std::string Location::getName() const
{
	return this->name;
}

//set number of zones and the zones
void Location::setNoZonesAndZones(int noZones, Zone* zones)
{
	if (noZones > 0 && noZones <= 20 && zones != nullptr) {
		this->noZones = noZones;
		if (this->zones != nullptr) {
			delete[] this->zones;
			this->zones = nullptr;
		}
		this->zones = new Zone[this->noZones];
		for (int i = 0; i < this->noZones; i++) {
			this->zones[i] = zones[i];
		}
	}
}

//get number of zones
int Location::getNoZones() const
{
	return this->noZones;
}

//get zones
Zone* Location::getZones() const
{
	if (this->zones != nullptr && this->noZones > 0) {
		Zone* temp = new Zone[this->noZones];
		for (int i = 0; i < this->noZones; i++) {
			temp[i] = this->zones[i];
		}
		return temp;
	}
	else {
		throw std::exception("Cannot return zones of this location");
	}
}

int Location::getLocationNoSeats() const {
	int s = 0;
	for (int i = 0; i < this->noZones; i++) {
		s += this->zones[i].getZoneNoSeats();
	}
	return s;
}

void Location::displayInfo()
{
	std::cout << std::endl << "Name of the location: " << this->name;
	std::cout << std::endl << "Adrress of the location: " << this->address;
	std::cout << std::endl << "The location has " << this->noZones << " zones:";
	for (int i = 0; i < this->noZones; i++) {
		std::cout << std::endl << this->zones[i];
	}
}

void Location::saveDataLocation(std::ofstream& file)
{
	if (!file.is_open()) {
		throw std::exception("file is not opened");
	}
	int nameSize = strlen(this->name.c_str()) + 1;
	file.write((char*)&nameSize, sizeof(int));
	file.write(this->name.c_str(), sizeof(char) * nameSize);
	int addressSize = strlen(this->address) + 1;
	file.write((char*)&addressSize, sizeof(int));
	file.write(this->address, sizeof(char) * addressSize);
	file.write((char*)&this->noZones, sizeof(int));
	this->zones->writeZoneData(file);
}

int Location::operator[](int zoneIndex) {
	if (zoneIndex > 0 && zoneIndex <= this->noZones) {
		return zones[zoneIndex].getZoneNoSeats();
	}
	else {
		throw std::exception("Cannot return the number of seats for this zone");
	}
}

//constructors
Location::Location() {
	ManagementApp::incrementNumLocations();
}

Location::Location(std::string name, const char* address, int noZones, Zone* zones)
{
	setName(name);
	setAddress(address);
	setNoZonesAndZones(noZones, zones);
	ManagementApp::incrementNumLocations();
}

//copy constructor
Location::Location(const Location& source)
{
	setName(source.name);
	setAddress(source.address);
	setNoZonesAndZones(source.noZones, source.zones);
	ManagementApp::incrementNumLocations();
}

//destructor
Location::~Location()
{
	if (this->zones != nullptr) {
		delete[] this->zones;
		this->zones = nullptr;
	}
	if (this->address != nullptr) {
		delete[] this->address;
		this->address = nullptr;
	}
}

//operator=
void Location::operator=(const Location& source)
{
	setName(source.name);
	setAddress(source.address);
	setNoZonesAndZones(source.noZones, source.zones);
}

//operator <<
std::ostream& operator<<(std::ostream& out, const Location& location) {
	out << std::endl << "Name of the location: " << location.name;
	out << std::endl << "Adrress of the location: " << location.address;
	out << std::endl << "The location has " << location.noZones << " zones:";
	for (int i = 0; i < location.noZones; i++) {
		out << std::endl << location.zones[i];
	}
	return out;
}


//operator >>
std::istream& operator>>(std::istream& in, Location& location) {
	std::cout << std::endl << "What is the name of the location? ";
	std::string s;
	in.ignore();
	std::getline(in, s);
	location.setName(s);
	std::cout << std::endl << "What is the address of the location? ";
	char a[100];
	in.getline(a, 100);
	location.setAddress(a);
	std::cout << std::endl << "How many zones has this location? ";
	int z;
	in >> z;
	if (z > 0) {
		location.noZones = z;
		if (location.zones != nullptr) {
			delete[] location.zones;
			location.zones = nullptr;
		}
		location.zones = new Zone[location.noZones];
		for (int i = 0; i < location.noZones; i++) {
			std::cout << "Details for zone " << i << ": ";
			//cin >> location.zones[i]
		}
	}
	return in;
}

////operator/ object-int
int Location::operator/(int row) {
	if (this->getLocationNoSeats() > 0) {
		return this->getLocationNoSeats() / row;
	}
	else {
		throw std::exception("Can't divide 0");
	}
}

//operator / int-object
int operator/(int value, Location& location) {
	return value / location.getNoZones();
}


//operator++ pre
Location Location::operator++() {
	++this->noZones;
	return *this;
}

//operator++ post
Location Location::operator++(int) {
	Location copy = *this;
	this->noZones++;
	return copy;
}

//operator!
bool Location::operator!() {
	return !this->address; //return true if address = nullptr, false if address exists
}

//operator<=
bool Location::operator<=(const Location& source) {
	return this->noZones <= source.noZones;
}

//operator==
bool Location::operator==(const Location& source) {
	return this->noZones == source.noZones;
}

//operator+=
void Location::operator+=(int value) {
	this->noZones += value;
}

//operator cast
Location::operator int() {
	return this->noZones;
}

