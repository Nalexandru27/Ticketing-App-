#include "CinemaCity.h"
#include "ClassUtils.h"
#include "Zones.h"
CinemaCity::CinemaCity(){}

CinemaCity::CinemaCity(std::string name, const char* address, int noZones, Zone* zones, int noMovies, std::string* movies, bool cinemaIsInTheMall, bool hasCaffeLounge):Location(name, address, noZones, zones)
{
	setNoMoviesAndMovies(noMovies, movies);
	this->cinemaIsInTheMall = cinemaIsInTheMall;
	this->hasCaffeLounge = hasCaffeLounge;
}

CinemaCity::CinemaCity(const CinemaCity& c)
{
	setName(c.name);
	setAddress(c.address);
	setNoZonesAndZones(c.noZones, c.zones);
	setNoMoviesAndMovies(c.noMovies, c.movies);
	this->cinemaIsInTheMall = c.cinemaIsInTheMall;
	this->hasCaffeLounge = c.hasCaffeLounge;
}

CinemaCity& CinemaCity::operator=(const CinemaCity& c)
{
	setName(c.name);
	setAddress(c.address);
	setNoZonesAndZones(c.noZones, c.zones);
	setNoMoviesAndMovies(c.noMovies, c.movies);
	this->cinemaIsInTheMall = c.cinemaIsInTheMall;
	this->hasCaffeLounge = c.hasCaffeLounge;
	return *this;
}

CinemaCity::~CinemaCity()
{
	if (this->movies != nullptr) {
		delete[] this->movies;
		this->movies = nullptr;
	}
}

void CinemaCity::setNoMoviesAndMovies(int noMovies, std::string* movies)
{
	if (noMovies > 0 && movies != nullptr) {
		this->noMovies = noMovies;
		if (this->movies != nullptr) {
			delete[] this->movies;
			this->movies = nullptr;
		}
		this->movies = new std::string[this->noMovies];
		for (int i = 0; i < this->noMovies; i++) {
			this->movies[i] = movies[i];
		}
	}
	else {
		throw std::exception("Cannot set the number of movies and their titles");
	}
}

int CinemaCity::getNoMovies()
{
	return this->noMovies;
}

std::string* CinemaCity::getMovies()
{
	if (this->movies != nullptr) {
		std::string* copy = new std::string[this->noMovies];
		for (int i = 0; i < this->noMovies; i++) {
			copy[i] = this->movies[i];
		}
		return copy;
	}
	else {
		throw std::exception("Cannot get the movies titles");
	}
}

void CinemaCity::setCinemaIsInTheMall()
{
	this->cinemaIsInTheMall = true;
}

void CinemaCity::setHasCaffeLounge()
{
	this->hasCaffeLounge = true;
}

void CinemaCity::setCinemaIsNotInTheMall()
{
	this->cinemaIsInTheMall = false;
}

void CinemaCity::setHasNoCaffeLounge()
{
	this->hasCaffeLounge = false;
}

void CinemaCity::displayInfo()
{
	Location::displayInfo();
	std::cout << std::endl << "This cinema has " << this->noMovies <<" movies. The titles are: ";
	for (int i = 0; i < this->noMovies; i++) {
		std::cout << std::endl << i + 1 << "." << this->movies[i];
	}
	if (this->cinemaIsInTheMall) {
		std::cout << std::endl << "This cinema is located inside a mall";
	}
	else {
		std::cout << std::endl << "This cinema is not located inside a mall";
	}
	if (this->hasCaffeLounge) {
		std::cout << std::endl << "This cinema has a caffe lounge";
	}
	else {
		std::cout << std::endl << "This cinema does not have a caffe lounge";
	}
	std::cout << std::endl;
	std::cout << std::endl << "-------Thank you for choosing our services---------";
	std::cout << std::endl << std::endl;

}

void CinemaCity::readData(std::ifstream& file)
{
	if (!file.is_open()) {
		throw std::exception("file is not opened");
	}
	readDataLocation(file);
	file.read((char*)&this->noMovies, sizeof(int));
	if (this->movies != nullptr) {
		delete[] this->movies;
		this->movies = nullptr;
	}
	this->movies = new std::string[this->noMovies];
	for (int i = 0; i < this->noMovies; i++) {
		this->movies[i] = ClassUtils::deserializeString(file);
	}
	file.read((char*)&this->cinemaIsInTheMall, sizeof(bool));
	file.read((char*)&this->hasCaffeLounge, sizeof(bool));
}


void CinemaCity::writeData(std::ofstream& file) {
	if (!file.is_open()) {
		throw std::exception("file is not opened");
	}
	this->saveDataLocation(file);
	file.write((char*)&this->noMovies, sizeof(int));
	for (int i = 0; i < this->noMovies; i++) {
		ClassUtils::serializeString(this->movies[i], file);
	}
	file.write((char*)&this->cinemaIsInTheMall, sizeof(bool));
	file.write((char*)&this->hasCaffeLounge, sizeof(bool));
}






