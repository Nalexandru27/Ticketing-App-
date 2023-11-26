#include <iostream>
#include <string>
#include "Location.h"
#include "Event.h"
#include "ManagementApp.h"
int main() {

	//testing the class Location
	/*int* array = new int[5];
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
	std::cout << location1 << std::endl;

	Location location2(5, new int[5] {1, 2, 4, 5, 6}, "piata resita", 2024, new std::string[4]{ "Category 1", "Category 2", "Category 3", "VIP" }, 4);
	std::cout << location2;

	Location location3;*/
	//std::cin >> location2;
	//std::cout << std::endl << location2;
	/*std::cout << std::endl << Location::getNoLocations();
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
	Location location4;*/
	//std::cin >> location4;
	//std::cout << std::endl  << location4;
	//end of testing

	/*try {
		Event e1("doi pe o banca", 3, new std::string[3]{ "mihai","ilona","mircea preda" }, 25, 12, 2025);
		std::cout << e1;
	}
	catch (std::exception& e) {
		std::cout << std::endl << e.what();
	}
	catch (...) {
		std::cout << std::endl << "eroare";
	}*/
	//Event e1("doi pe o banca", 3, new std::string[3]{ "mihai","ilona","mircea preda" });
	//std::cout << std::endl << e1;

	//Event e1("doi pe o banca", 3, new std::string[3]{ "mihai","ilona","mircea preda" }, 25, 12, 2025);
	try {
		//int v[3]={30,30,35};
		//Event e2("boxing gala", 3, new std::string[3]{ "moro","stoica","petrisor" }, v);
		//std::cout << e2.getDurationOfTheEvent();
		//int h[3] = { 24,53,16 };
		//e2.setDurationOfEachMoment(h);
		//std::cout << std::endl << e2.getDurationOfTheEvent() << std::endl;
		//const int* g = e2.getDurationOfEachMoment();
		//for (int i = 0; i < e2.getNumMoments(); i++) {
		//	std::cout << g[i] << " ";
		//}
		//std::cout << std::endl << e2;
		////std::cout << std::endl << e2;
		//std::cout << std::endl; std::cout << std::endl;
		Event e3;
		std::cin >> e3;
		std::cout << std::endl << e3;
	}
	catch (std::exception& e) {
		std::cout << std::endl << e.what();
	}
	/*try {
		std::cout << std::endl << 
	}
	catch (std::exception& e) {
		std::cout << std::endl << e.what();
	}
	catch (...) {
		std::cout << std::endl << "eroare";
	}*/
	//std::cout<<std::endl<<ManagementApp::getNumEvents();

	/*std::cin >> e1;
	try {
		std::cout << e1;
	}
	catch (std::exception e) {
		std::cout << std::endl << e.what();
	}*/

	//testing operator += and operator cast for location class
	/*Location location(3, new int[3] {4, 7, 5}, "piata unirii", new std::string[2]{ "normal", "vip" }, 2);
	std::cout << location;
	location += 6;
	std::cout << std::endl << std::endl << location;
	int a = (int)location;
	std::cout << std::endl << a;*/
}