#include <iostream>
#include <string>


class Location {
private:

	int noRows = 0;
	int* seatsPerRow = nullptr;
	char* address = nullptr;
	int maxNoSeats = 0;
	//zones?
	static int noLocations;
public:
	void setNoRows(int newNoRows) {
		if (newNoRows > 0) {
			this->noRows = newNoRows;
		}
		else {
			throw std::exception ("Invalid number of rows. Must be greater than 0.");
		}
	}

	int getNoRows() {
		return this->noRows;
	}


	void setSeatsPerRow(int* seatsPerRow) {
		if (seatsPerRow == nullptr) {
			throw std::exception("Invalid number of seats per row.");
		}
		else {
			if (this->seatsPerRow != nullptr) {
				delete[] this->seatsPerRow;
				this->seatsPerRow = nullptr;
			}
			this->seatsPerRow = new int[this->noRows];
			for (int i = 0; i < this->noRows; ++i) {
				this->seatsPerRow[i] = seatsPerRow[i];
			}
		}
	}

	int* getSeatsPerRow() {
		if (this->seatsPerRow == nullptr || this->noRows == 0) {
			throw std::exception("Can't provide number of seats per row because their is missing data");
		}
		else {
			int* copy = new int[this->noRows];
			memcpy(copy, this->seatsPerRow, noRows);
			return copy;
		}
	}


	void setAddress(const char* newAddress) {
		if (newAddress == nullptr) {
			throw std::exception("You didn't provide an adrress");
		}
		else {
			if (this->address != nullptr) {
				delete[] this->address;
				this->address = nullptr;
			}
			this->address = new char[strlen(newAddress) + 1];
			strcpy_s(this->address, strlen(newAddress) + 1, newAddress);
		}
	}

	char* getAddress() {
		if (this->address == nullptr) {
			throw std::exception("There is no address yet");
		}
		else {
			char* copy = new char[strlen(this->address) + 1];
			strcpy_s(copy, strlen(this->address) + 1, this->address);
		}
	}


	void setMaxNoSeats(int newMaxNoSeats) {
		if (newMaxNoSeats > 0) {
			this->maxNoSeats = newMaxNoSeats;
		}
		else {
			throw std::exception("Invalid number of max seats. Must be greater than 0.");
		}
	}

	int getMaxNoSeats() {
		return this->maxNoSeats;
	}

	int static getNoLocations() {
		return Location::noLocations;
	}

	Location(){
		this->noLocations++;
	}

	Location(int noRows, int* seatsPerRow, const char* address, int maxNoSeats) {
		this->noLocations++;
		setNoRows(noRows);
		setSeatsPerRow(seatsPerRow);
		setAddress(address);
		setMaxNoSeats(maxNoSeats);
	}

	Location(int noRows, int* seatsPerRow, const char* address) {
		this->noLocations++;
		setNoRows(noRows);
		setSeatsPerRow(seatsPerRow);
		setAddress(address);
		for (int i = 0; i < this->noRows; i++) {
		this->maxNoSeats += this->seatsPerRow[i];
		}
	}

	Location(const Location& source) {
		this->noLocations++;
		setNoRows(source.noRows);
		setSeatsPerRow(source.seatsPerRow);
		setAddress(source.address);
		setMaxNoSeats(source.maxNoSeats);
	}

	~Location() {
		this->noLocations--;
		delete[] this->address;
		delete[] this->seatsPerRow;
	}


	void operator=(const Location& source) {
		setNoRows(source.noRows);
		setSeatsPerRow(source.seatsPerRow);
		setAddress(source.address);
		setMaxNoSeats(source.maxNoSeats);
	}


	friend std::ostream& operator<<(std::ostream& out, const Location& location) {
		if (location.address != nullptr) {
			out << "Location address is: " << location.address << std::endl;
		}
		if (location.seatsPerRow != nullptr) {
			out << "Location has: " << location.noRows << " rows" << std::endl;
			for (int i=0; i < location.noRows; i++) {
				out << "Row " << i + 1 << " has " << location.seatsPerRow[i] << std::endl;
			}
		}
		out << "Location has a maximum seats of: " << location.maxNoSeats;
		return out;
	}


	friend std::istream& operator>>(std::istream& in, Location& location) {
		std::cout << std::endl<< "What is the location Address? Please provide the country, city, street and number of the street:"<<std::endl;
		char temp[100] = "";
		in.getline(temp, sizeof(temp));
		if (strlen(temp) < 15) {
			throw std::exception("The address is too short. Please provide more information.");
		}
		else {
			if (location.address != nullptr) {
				delete[] location.address;
				location.address = nullptr;
			}
			
			location.address = new char[strlen(temp) + 1];
			strcpy_s(location.address, strlen(temp) + 1, temp);
		}
		std::cout << "Enter the number of rows: ";
		int noRows2 = 0;
		in >> noRows2;
		location.setNoRows(noRows2);
		int* seatsPerRow2 = new int[noRows2];
		for (int i = 0; i < noRows2; i++) {
			std::cout << "Please provide the number of seats for row[" << i+1 << "]=";
			in >> seatsPerRow2[i];
		}
		location.setSeatsPerRow(seatsPerRow2);
		std::cout << "Enter the maxim number of seats for this location: ";
		in >> location.maxNoSeats;
		return in;
	}
};

int Location::noLocations = 0;

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
	std :: cout << location1 << std::endl;

	Location location2(5, new int[5] {1, 2, 4, 5, 6}, "piata resita", 2024);
	std::cout << location2;

	Location location3;
	//std::cin >> location2;
	//std::cout << std::endl << location2;
	std::cout << std:: endl<<Location::getNoLocations();
	//end of testing

}