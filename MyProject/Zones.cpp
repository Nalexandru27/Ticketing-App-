#include "Zones.h"
#include <iostream>
#include <fstream>
#include "ClassUtils.h"
void Zone::setName(std::string name)
{
	if (name.size() > 3 && name.size() < 25) {
		this->name = name;
	}
	else {
		throw std::exception("Zone name is not valid");
	}
}

std::string Zone::getName()
{
	return this->name;
}

void Zone::setNoRowsAndSeatsPerRow(int noRows, int* seatsPerRow)
{
	if (noRows > 0 && noRows < 100 && seatsPerRow != nullptr) {
		this->noRows = noRows;
		if (this->seatsPerRow != nullptr) {
			delete[] this->seatsPerRow;
			this->seatsPerRow = nullptr;
		}
		this->seatsPerRow = new int[this->noRows];
		for (int i = 0; i < this->noRows; i++) {
			this->seatsPerRow[i] = seatsPerRow[i];
		}
	}
	else {
		throw std::exception("Invalid number of rows or seats per row");
	}
}

int Zone::getNoRows()
{
	return this->noRows;
}

int* Zone::getSeatsPerRows()
{
	int* copy = new int[this->noRows];
	for (int i = 0; i < this->noRows; i++) {
		copy[i] = this->seatsPerRow[i];
	}
	return copy;
}

void Zone::setCategory(std::string category)
{
	if (category.size() > 0 && category.size() < 12) {
		this->category = category;
	}
	else {
		throw std::exception("Invalid category");
	}
}

std::string Zone::getCategory()
{
	return this->category;
}

void Zone::setPrice(float price)
{
	if (price > 0) {
		this->price = price;
	}
	else {
		throw std::exception("Enter a positive value for the price");
	}
}

float Zone::getPrice()
{
	return this->price;
}

int Zone::getZoneNoSeats() {
	int s = 0;
	for (int i = 0; i < this->noRows; i++) {
		s += this->seatsPerRow[i];
	}
	return s;
}

Zone::Zone(){}

Zone::Zone(std::string name, int noRows, int* seatsPerRow, std::string category, float price)
{
	setName(name);
	setNoRowsAndSeatsPerRow(noRows, seatsPerRow);
	setCategory(category);
	setPrice(price);
}

Zone::~Zone()
{
	if (this->seatsPerRow != nullptr) {
		delete[] this->seatsPerRow;
	}
}

Zone::Zone(const Zone& z)
{
	setName(z.name);
	setNoRowsAndSeatsPerRow(z.noRows, z.seatsPerRow);
	setCategory(z.category);
	setPrice(z.price);
}

Zone& Zone::operator=(Zone z)
{
	setName(z.name);
	setNoRowsAndSeatsPerRow(z.noRows, z.seatsPerRow);
	setCategory(z.category);
	setPrice(z.price);
	return *this;
}

void Zone::writeZoneData(std::ofstream& file)
{
	if (!file.is_open()) {
		throw std::exception("file is not opened");
	}
	int nameSize = strlen(this->name.c_str())+1;
	file.write((char*)&nameSize, sizeof(int));
	file.write(this->name.c_str(), sizeof(char) * nameSize);
	file.write((char*)&this->noRows, sizeof(int));
	for (int i = 0; i < this->noRows; i++) {
		file.write((char*)&this->seatsPerRow[i], sizeof(int));
	}
	int categorySize = strlen(this->category.c_str()) + 1;
	file.write((char*)&categorySize, sizeof(int));
	file.write(this->category.c_str(), sizeof(char) * categorySize);
	file.write((char*)&this->price, sizeof(float));
}

Zone Zone::readDataZone(std::ifstream& file)
{
	if (!file.is_open()) {
		throw std::exception("file is not opened");
	}
	Zone temp;
	temp.name = ClassUtils::deserializeString(file);
	file.read((char*)&temp.noRows, sizeof(int));
	temp.seatsPerRow = new int[temp.noRows];
	for (int i = 0; i < temp.noRows; i++) {
		file.read((char*)&temp.seatsPerRow[i], sizeof(int));
	}
	temp.category = ClassUtils::deserializeString(file);
	file.read((char*)&temp.price, sizeof(float));
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Zone& zone)
{
	out << std::endl << "Name of the zone is: " << zone.name;
	out << std::endl << zone.name << " has " << zone.noRows << " rows";
	for (int i = 0; i < zone.noRows; i++) {
		out << std::endl << "Row " << i + 1 << " has: " << zone.seatsPerRow[i] << " seats";
	}
	out << std::endl << "Zone category is: " << zone.category;
	out << std::endl << "Price for a seat in this zone is: " << zone.price << " ron";
	out << std::endl << "------------------------------------------";
	return out;
}

std::istream& operator>>(std::istream& in,Zone& zone) {
	std::cout << std::endl << "Name of the zone is: ";
	std::string aux;
	std::getline(in, aux);
	zone.setName(aux);
	int temp;
	std::cout << std::endl << "How many rows does this zone have: ";
	in >> temp;
	if (temp > 0) {
		zone.noRows = temp;
		if (zone.seatsPerRow != nullptr) {
			delete[] zone.seatsPerRow;
			zone.seatsPerRow = nullptr;
		}
		zone.seatsPerRow = new int[temp];
		for (int i = 0; i < zone.noRows; i++) {
			std::cout << "How many seats has row no " << i << " ? ";
			in >> temp;
			if (temp > 0) {
				zone.seatsPerRow[i] = temp;
			}
		}
	}
	std::cout << std::endl << "What category this zone is? ";
	in.ignore();
	std::getline(in, aux);
	zone.setCategory(aux);
	float a;
	std::cout << std::endl << "What's the price for a seat in this zone?";
	in >> a;
	zone.setPrice(a);
	in.ignore();
	std::cout << std::endl << std::endl;
	return in;
}
