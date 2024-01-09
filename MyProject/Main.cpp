#include <iostream>
#include <string>
#include "Location.h"
#include "Event.h"
#include "ManagementApp.h"
#include "CinemaCity.h"
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
	/*try {*/
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
		/*int v[2] = { 45,45 };
		Event e3("steaua-dinamo", 2, new std::string[2]{ "repriza1","repriza2" }, v, 26, 11, 2023, 20, 45);*/
		//std::cin >> e3;
		//std::cout << std::endl << e3;
		//Event e4;
		//e4 = e3;
		/*std::cout << std::endl << e4;
		std::cout << std::endl << e4[1];
		std::cout << std::endl << e4 + 3;
		std::cout << std::endl << 1 + e4;*/
		/*std::cout << std::endl << e3--;
		std::cout << std::endl << e3;*/
		/*Event e6 = e3;*/
		//std::cout << std::endl<<--e3;
		//std::cout << std::endl << e6--;
		//std::cout << std::endl << e6;
		/*int b = e3;
		std::cout << std::endl << b;
		std::cout << std::endl << !e3;
		e3 <= e6;
	}
	catch (std::exception& e) {
		std::cout << std::endl << e.what();
	}
	Location theater1(3, new int[3] {6, 12, 10}, "piata romana", new std::string[3]{ "category 1","category 2","box" }, 3);
	DateTime dateTime1(29, 11, 2023, 19, 30);
	int v[3]{ 80,15,80 };
	Event event1("Doi pe o banca", 3, new std::string[3]{ "scena1","pauza","scena2" }, v, theater1, dateTime1);
	std::cout << event1;*/
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

	//try {
	//	Zone* zone1 = new Zone[2];
	//		for (int i = 0; i < 2; i++) {
	//			std::cin >> zone1[i];
	//		}
	//		/*for (int i = 0; i < 2; i++) {
	//			std::cout << std::endl << zone1[i];
	//		}*/
	//		std::cout << std::endl;
	//		std::cout << std::endl;
	//		Location stadium("Arena Nationala", "Soseaua Pantelimon", 2, zone1);
	//		std::cout << stadium;
	//}
	//catch (std::exception e) {
	//	std::cout << e.what();
	//}


	Zone* zoneTest = new Zone[3];
	zoneTest[0].setName("Hall 1");
	zoneTest[0].setNoRowsAndSeatsPerRow(2, new int[2] {15, 17});
	zoneTest[0].setCategory("standard");
	zoneTest[0].setPrice(20);

	zoneTest[1].setName("Hall 2");
	zoneTest[1].setNoRowsAndSeatsPerRow(3, new int[3] {4, 6, 8});
	zoneTest[1].setCategory("premium");
	zoneTest[1].setPrice(45);

	zoneTest[2].setName("Hall 3");
	zoneTest[2].setNoRowsAndSeatsPerRow(3, new int[3] {6, 6, 6});
	zoneTest[2].setCategory("V.I.P");
	zoneTest[2].setPrice(80);


	std::ofstream report2("zoneReport.bin", std::ios::binary | std::ios::out);
	for (int i = 0; i < 3; i++) {
		zoneTest[i].writeZoneData(report2);
	}
	report2.close();

	std::ifstream getZone("zoneReport.bin", std::ios::binary | std::ios::in);
	Zone* zoneTest2 = new Zone[3];
	for (int i = 0; i < 3; i++) {
		zoneTest2[i] = Zone::readDataZone(getZone);
	}
	for (int i = 0; i < 3; i++) {
		std::cout << zoneTest2[i];
	}

	/*for (int i = 0; i < 3; i++) {
		std::cout << zoneTest[i];
	}*/

	//Location locationTest("Arena Nationala", "Soseauna Pantelimon", 3, zoneTest);

	//std::cout << locationTest;

	//DateTime dateTimeTest(29, 12, 2023, 20, 30);

	/*Event eventTest("Liga 1 FCSB-CFR Cluj", 90, locationTest, dateTimeTest);
	try{
		std::cout << eventTest;
	}
	catch (std::exception e) {
		std::cout << e.what();
	}*/


	CinemaCity cinema1("CinemaCity SunPlaza", "Piata Sudului", 3, zoneTest, 3, new std::string[3]{ "Alba ca zapada","Cenusareasa","Harap Alb" }, true, true);
	cinema1.displayInfo();

	std::ofstream report("cinemaReport.bin", std::ios::binary | std::ios::out);
	cinema1.writeData(report);
	report.close();

	/*CinemaCity cinema2;
	std::ifstream getCinemaData("cinemaReport.bin", std::ios::binary | std::ios::in);
	cinema2.readData(getCinemaData);

	std::cout << std::endl << std::endl << std::endl << std::endl;
	cinema2.displayInfo();
	getCinemaData.close();*/


}