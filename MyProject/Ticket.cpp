#include "Ticket.h"

Ticket::Ticket():id(generateRandomId()){}


void Ticket::setRow(int row) {

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

