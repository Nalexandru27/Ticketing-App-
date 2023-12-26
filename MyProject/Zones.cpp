#include "Zones.h"

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

void Zone::setPrice(int price)
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

Zone Zone::operator=(const Zone& z)
{
	setName(z.name);
	setNoRowsAndSeatsPerRow(z.noRows, z.seatsPerRow);
	setCategory(z.category);
	setPrice(z.price);
}


