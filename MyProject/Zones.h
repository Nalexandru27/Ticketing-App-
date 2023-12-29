#pragma once
#include <string>

class Zone{
	std::string name = "";
	int noRows = 0;
	int* seatsPerRow = nullptr;
	std::string category = "";
	float price = 0.0f;
public:
	void setName(std::string name);
	std::string getName();

	void setNoRowsAndSeatsPerRow(int noRows, int* seatsPerRow);
	int getNoRows();
	int* getSeatsPerRows();

	void setCategory(std::string category);
	std::string getCategory();

	void setPrice(float price);
	float getPrice();

	//constructors
	Zone();
	Zone(std::string name, int noRows, int* seatsPerRow, std::string category, float price);

	//destructor
	~Zone();

	//copy constructor
	Zone(const Zone& z);

	//operator=
	void operator=(const Zone& z);

	//operator<<
	friend std::ostream& operator<<(std::ostream& out, const Zone& zone);

	//operator>>
	friend std::istream& operator>>(std::istream& in, Zone& zone);
};

