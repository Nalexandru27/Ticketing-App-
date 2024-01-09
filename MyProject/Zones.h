#pragma once
#include <string>

class Zone{
	std::string name = "";
	int noRows = 0;
	int* seatsPerRow = nullptr;
	std::string category = "";
	float price = 0.0f;
public:
	//set,get Name
	void setName(std::string name);
	std::string getName();

	//set, get NoRows and SeatsPerRow
	void setNoRowsAndSeatsPerRow(int noRows, int* seatsPerRow);
	int getNoRows();
	int* getSeatsPerRows();

	//set, get Category
	void setCategory(std::string category);
	std::string getCategory();

	//set, get Price
	void setPrice(float price);
	float getPrice();

	//get number of seats in the zone
	int getZoneNoSeats();

	//constructors
	Zone();
	Zone(std::string name, int noRows, int* seatsPerRow, std::string category, float price);

	//destructor
	~Zone();

	//copy constructor
	Zone(const Zone& z);

	//operator=
	Zone& operator=(Zone z);

	//operator<<
	friend std::ostream& operator<<(std::ostream& out, const Zone& zone);

	//operator>>
	friend std::istream& operator>>(std::istream& in, Zone& zone);

	void writeZoneData(std::ofstream& file);
	static Zone readDataZone(std::ifstream& file); //? &
};

