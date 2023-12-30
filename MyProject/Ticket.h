#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>


class Ticket{
	const int id;
	int row = 0;
	int seat = 0;
	std::string category = "";
	std::string zoneName = "";
	float price = 0.0f;
public:

	static const int generateRandomId();

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
	void setCategory(std::string category);

	//price
	float getPrice();
	void setPrice(float price);

	//zone name
	void setZoneName(std::string zoneName);

	//constructor
	Ticket(int id, int row, int seat, std::string category, float price);

	//copy constructor
	Ticket(const Ticket& t);

	//operator=
	Ticket& operator=(const Ticket& t);

};

