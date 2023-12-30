#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
const int generateRandomId() {
	srand((unsigned)time(nullptr));
	int lowerLimit = 1000000;
	int upperLimit = 10000000;
	const int random = rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
	return random;
}

class Ticket{
	const int id;
	int row;
	int seat;
	std::string category;
	std::string zoneName;
	float price;
public:
	Ticket();
	Ticket(int row, int seat, std::string zone, std::string category, float price);
	//id
	const int getId();

	//row
	int getRow();
	void setRow(int row);

	//seat
	int getSeat();
	void setSeat(int seat);

	//category
	std::string getCategory();

	//price
	float getPrice();

	//constructor
	Ticket(int id, int row, int seat, std::string category, float price);

	//copy constructor
	Ticket(const Ticket& t);

	//operator=
	Ticket& operator=(const Ticket& t);

};

