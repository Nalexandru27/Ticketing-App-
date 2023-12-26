#include "Ticket.h"

const int Ticket::getId()
{
	return this->id;
}

int Ticket::getRow()
{
	return this->row;
}

int Ticket::getSeat()
{
	return this->seat;
}

std::string Ticket::getCategory()
{
	return this->category;
}

float Ticket::getPrice()
{
	return this->price;
}

Ticket::Ticket(int id, int row, int seat, std::string category, float price):id(generateRandomId)
{

}
