#include <iostream>
#include <string>


class Location {
private:
	int noRows = 0;
	int* seatsPerRow = nullptr;
	char* address = nullptr;
	int maxNoSeats = 0;
	//zones?
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
	void setSeatsPerRow(int* seatsPerRow, int noRows) {
		if (seatsPerRow == nullptr) {
			throw std::exception("Invalid number of seats per row.");
		}
		else {
			if (this->seatsPerRow != nullptr) {
				delete[] this->seatsPerRow;
				this->seatsPerRow = nullptr;
			}
			this->seatsPerRow = new int[noRows];
			memcpy(this->seatsPerRow, seatsPerRow, noRows);
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
	Location(){

	}
	Location(int noRows, int* seatsPerRow, const char* address, int maxNoSeats) {
		setNoRows(noRows);
		setSeatsPerRow(seatsPerRow,this->noRows);
		setAddress(address);
		setMaxNoSeats(maxNoSeats);
	}
	Location(int noRows, int* seatsPerRow, const char* address) {
		setNoRows(noRows);
		setSeatsPerRow(seatsPerRow, this->noRows);
		setAddress(address);
		for (int i = 0; i < this->noRows; i++) {
		this->maxNoSeats += this->seatsPerRow[i];
		}
	}
	Location(const Location& source) {
		setNoRows(source.noRows);
		setSeatsPerRow(source.seatsPerRow, source.noRows);
		setAddress(source.address);
		setMaxNoSeats(source.maxNoSeats);
	}
	~Location() {
		delete[] this->address;
		delete[] this->seatsPerRow;
	}
	void operator=(const Location& source) {
		setNoRows(source.noRows);
		setSeatsPerRow(source.seatsPerRow, source.noRows);
		setAddress(source.address);
		setMaxNoSeats(source.maxNoSeats);
	}
	friend std::ostream& operator<<(std::ostream& out, const Location& location) {
		out << "Location address is: " << location.address << std::endl;
		out << "Location has: " << location.noRows << " rows" << std::endl;
		for (int i=0; i < location.noRows; i++) {
			out << "Row " << i + 1 << " has " << location.seatsPerRow[i] << " ";
		}
		out << "Location has a maximum seats of: " << location.maxNoSeats;
	}
	friend std::istream& operator>>(std::istream& in, Location& location) {

	}
};


int main() {
	std::cout << std::endl << "Hello!";

}