#include "Ticket.h"

const int Ticket::generateRandomId()
{
	srand((unsigned)time(nullptr));
	int lowerLimit = 1000000;
	int upperLimit = 10000000;
	const int random = rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
	return random;
}

Ticket::Ticket():id(generateRandomId()){}

Ticket::Ticket(int row, int seat, std::string zoneName, std::string category, float price) :id(generateRandomId()) {
	setRow(row);
	setSeat(seat);
	setCategory(category);
	setPrice(price);
	setZoneName(zoneName);
}

void Ticket::setRow(int row) {
	if (row > 0) {
		this->row = row;
	}
	else {
		throw std::exception("Cannot set the row value");
	}
}

void Ticket::setSeat(int seat) {
	if (seat > 0) {
		this->seat = seat;
	}
	else {
		throw std::exception("Cannot set the seat value");
	}
}

void Ticket::setCategory(std::string category) {
	if (category.size() > 0) {
		this->category = category;
	}
	else {
		throw std::exception("Cannot set the category value");
	}
}

float Ticket::getPrice()
{
	return this->price;
}

void Ticket::setPrice(float price) {
	if (price > 0) {
		this->price = price;
	}
	else {
		throw std::exception("Cannot set the price value");
	}
}

void Ticket::setZoneName(std::string zoneName) {
	if (zoneName.size() > 0) {
		this->zoneName = zoneName;
	}
	else {
		throw std::exception("Cannot set the zone name value");
	}
}

Ticket& Ticket::operator=(const Ticket& t) {
	if (t.row != 0) {
		this->row = t.row;
	}
	else {
		throw std::exception("Cannot assign the row value");
	}
	if (t.seat != 0) {
		this->seat = t.seat;
	}
	else {
		throw std::exception("Cannot assign the seat value");
	}
	if (t.category.size() > 0) {
		this->category = t.category;
	}
	else {
		throw std::exception("Cannot assign the category value");
	}
	if (t.zoneName.size() > 0) {
		this->zoneName = t.zoneName;
	}
	else {
		throw std::exception("Cannot assign the zone name value");
	}
	if (t.price > 0) {
		this->price = t.price;
	}
	else {
		throw std::exception("Cannot assign the price value");
	}
	return *this;
}


std::ostream& operator<<(std::ostream& out, Ticket t) {
	out << std::endl << "Ticket id is: " << t.id;
	out << std::endl << "Ticket row " << t.row << " and seat " << t.seat;
	out << std::endl << "Ticket zone is " << t.category << " and zone " << t.zoneName;
	out << std::endl << "Ticket price is: " << t.price;
	return out;
}
