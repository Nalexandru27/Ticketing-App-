#include <iostream>
#include <string>
#include "Location.h"

int main() {

	//testing the class Location
	int* array = new int[5];
	array[0] = 4;
	array[1] = 10;
	array[2] = 5;
	array[3] = 2;
	array[4] = 7;
	Location location1;
	location1.setAddress("piata romana");
	location1.setMaxNoSeats(205);
	location1.setNoRows(5);
	location1.setSeatsPerRow(array);
	location1.setZones(new std::string[3]{ "Category 1", "Category 2", "Category 3" }, 3);
	std :: cout << location1 << std::endl;

	Location location2(5, new int[5] {1, 2, 4, 5, 6}, "piata resita", 2024, new std::string[4]{ "Category 1", "Category 2", "Category 3", "VIP"}, 4);
	std::cout << location2;

	Location location3;
	//std::cin >> location2;
	//std::cout << std::endl << location2;
	std::cout << std:: endl<< Location::getNoLocations();
	std::cout << std::endl << location2[4];
	if (!location1) {
		std::cout << std::endl << "Location1 has no address";
	}
	else {
		std::cout << std::endl << "Location1 address is: " << location1.getAddress();
	}
	if (location1 <= location2) {
		std::cout << std::endl << "Location1 has less seats than Location2";
	}
	else {
		std::cout << std::endl << "Location2 has less seats than Location1";
	}
	if (location1 == location2) {
		std::cout << std::endl << "Location1 has the same no of rows as Location2";
	}
	else {
		std::cout << std::endl << "Location1 has not  the same no of rows as Location2";
	}
	std::cout << std::endl << std::endl;
	Location location4;
	std::cin >> location4;
	std::cout << std::endl  << location4;
	//end of testing

}