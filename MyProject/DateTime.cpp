#include "DateTime.h"
#include <iostream>

//set Day of event
void DateTime::setDay(int day) {
	if (day >= 1 && day <= 31) {
		this->day = day;
	}
	else {
		throw std::exception("Invalid day");
	}
}
//get Day of event
int DateTime::getDay()  const {
	if (this->day) {
		return this->day;
	}
	else {
		throw std::exception("The exact date was not decided yet. Date and time will be announced soon!");
	}
		
}

//set Month of event
void DateTime::setMonth(int month) {
	if (month >= 1 && month <= 12) {
		this->month = month;
	}
	else {
		throw std::exception("Invalid month");
	}
};
//get Month of event
int DateTime::getMonth()  const {
	if (this->month) {
		return this->month;
	}
	else {
		throw std::exception("The exact date was not decided yet. Date and time will be announced soon!");
	}
};

//set Year of event
void DateTime::setYear(int year) {
	if (year >= 2023 && year <= 2033) {
		this->year = year;
	}
	else {
		throw std::exception("Event should be placed with maximum 10 years in the future from the current year");
	}
};
//get Year of event
int DateTime::getYear()  const {
	if (this->year) {
		return this->year;
	}
	else {
		throw std::exception("The exact date was not decided yet. Date and time will be announced soon!");
	}
};

//set Hour of event
void DateTime::setHour(int hour) {
	if (hour >= 10 && hour <= 24) {
		this->hour = hour;
	}
	else {
		throw std::exception("Invalid hour. Should be between 10:00am and 0:00pm");
	}
};
//get Hour of event
int DateTime::getHour()  const {
	if (this->hour) {
		return this->hour;
	}
	else {
		throw std::exception("The exact date was not decided yet. Date and time will be announced soon!");
	}
};

//set Minute of event
void DateTime::setMinute(int minute) {
	if (minute >= 0 && minute <= 59) {
		this->minute = minute;
	}
	else {
		throw std::exception("Invalid minute. Should be between :0 and :59");
	}
};
//get Minute of event
int DateTime::getMinute()  const {
	if (this->minute>=0) {
		return this->minute;
	}
	else {
		throw std::exception("The exact time was not decided yet");
	}
};


DateTime::DateTime() {

}

DateTime::DateTime(int day, int month, int year, int hour, int minute) {
	setDay(day);
	setMonth(month);
	setYear(year);
	setHour(hour);
	setMinute(minute);
}

DateTime::DateTime(const DateTime& dt) {
	setDay(dt.day);
	setMonth(dt.month);
	setYear(dt.year);
	setHour(dt.hour);
	setMinute(dt.minute);
}

DateTime& DateTime::operator=(const DateTime& dt) {
	setDay(dt.day);
	setMonth(dt.month);
	setYear(dt.year);
	setHour(dt.hour);
	setMinute(dt.minute);
	return *this;
}

std::ostream& operator<<(std::ostream& out, const DateTime& dt) {
	if (dt.getDay() > 0 && dt.getMonth() > 0 && dt.getYear() > 0) {
		out << std::endl << "Date(dd/mm/yyyy): " << dt.getDay() << "/";
		if (dt.getMonth() < 10) {
			out << "0" << dt.getMonth() << "/";
		}
		else {
			out << dt.getMonth() << "/";
		}
		out << dt.getYear();
	}
	if (dt.getMinute() >= 0 && dt.getHour() > 0) {
		out << std::endl << "Time: " << dt.getHour();
		if (dt.getMinute() < 10) {
			out << ":0" << dt.getMinute();
		}
		else {
			out << ":" << dt.getMinute();
		}
	}
	return out;
}

std::istream& operator>>(std::istream& in, DateTime& dt) {
	int temp;
	std::cout << std::endl << "Enter day:"; in >> temp;
	dt.setDay(temp);
	std::cout << std::endl << "Enter month:"; in >> temp;
	dt.setMonth(temp);
	std::cout << std::endl << "Enter year:"; in >> temp;
	dt.setYear(temp);
	std::cout << std::endl << "Enter hour:"; in >> temp;
	dt.setHour(temp);
	std::cout << std::endl << "Enter minutes:"; in >> temp;
	dt.setMinute(temp);
	return in;
}

int DateTime::operator-(int value) {
	if (value <= 12) {
		return this->day - value;
	}
	else {
		throw std::exception("value is too big");
	}
}

bool DateTime::operator!() {
	return this->day > 0;
}

bool DateTime::operator>(const DateTime& dt) {
	return this->getYear() > dt.getYear();
}

bool DateTime::operator==(const DateTime& dt) {
	return this->getMonth() == dt.getMonth();
}

DateTime DateTime::operator++() {
	++this->hour;
	if (this->hour >= 24) {
		++this->day;
	}
	return *this;
}

DateTime DateTime::operator++(int) {
	DateTime copy = *this;
	if (this->year + 1 <= 2034) {
		this->year++;
	}
	else {
		throw std::exception("Value is too big");
	}
	return copy;
}


