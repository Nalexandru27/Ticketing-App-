#pragma once
#include "Location.h"
#include <string>
#include "ManagementApp.h"
#include <fstream>
class CinemaCity :public Location
{private:
	int noMovies=0;
	std::string* movies=nullptr;
	bool cinemaIsInTheMall=false;
	bool hasCaffeLounge=false;
public:
	CinemaCity();
	CinemaCity(std::string name, const char* address, int noZones, Zone* zones, int noMovies, std::string* Movies, bool cinemaIsInTheMall, bool hasCaffeLounge);

	CinemaCity(const CinemaCity& c);
	CinemaCity& operator=(const CinemaCity& c);
	~CinemaCity();

	void setNoMoviesAndMovies(int noMovies, std::string* movies);
	int getNoMovies();
	std::string* getMovies();

	void setCinemaIsInTheMall();
	void setHasCaffeLounge();
	void setCinemaIsNotInTheMall();
	void setHasNoCaffeLounge();
	
	void displayInfo();

	void readData(std::ifstream& file);
	void writeData(std::ofstream& file);
};

