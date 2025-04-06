//Date.cpp - Date class implementation
#include <iostream>
#include "Date.h"
#include <string>
#include <sstream>

using namespace std;

// Constructor with parameters of the month, day, year
// Calls the setDate function for validation
Date::Date(int m, int d, int y) {
	setDate(m, d, y);
}

//Function to set date variables in class after validation. 
//If validation fails sets a default date of 1/1/1900
void Date::setDate(int m, int d, int y) {
	bool isValid = true;
	
	if (m < 1 || m > 12) {
		cout << "Month invalid\n";
		isValid = false;
	}
	else if (y < 1) {
		cout << "Year invalid\n";
		isValid = false;
	}
	if (isValid) {
		int maxDays = lastDay(m,y);
		if (d < 1 || d > maxDays) {
			cout << "Day invalid\n";
			isValid = false;
		}
	}

	if (isValid) {
		month = m;
		day = d;
		year = y;
	}
	else {
		month = 1;
		day = 1;
		year = 1900;
	}
};

//Function to figure out the current object's last day of the month as an integer
//Takes the month and returns the number of days within that month
//If month is 2 also takes the year and calls the isLeapYear function
//If isLeapYear returns true last day is 29, if false it is 28
int Date::lastDay() const {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	}
	return 31;
}

//Function to figure out the last day of an object's month
//Takes the month and returns the number of days within that month
//If month is 2 also takes the year and calls the isLeapYear function
//If isLeapYear returns true last day is 29, if false it is 28
int Date::lastDay(int month, int year) const {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	}
	return 31; 
}

//Function to print the stored date in the following format of 1/2/2010
void Date::printMonthDayYear() const {
	cout << month << "/" << day << "/" << year <<"\n" <<"\n";
}

//Function to get the month name corressponding to the integer value
string Date::getMonthName(int month) const {
	const string monthnames[12]{ "January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December" };
	return monthnames[month - 1];
}

//Function to determine if the object's current state year is a leapyear or not
//needed to figure out the number of days in the month of February
bool Date::isLeapYear() const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);


}
//Function to determine if an object's year is a leap year or not
bool Date::isLeapYear(int year) const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//Function to print in date format: January 2, 1990
void Date::printMonthNameDayYear() const {
	cout << getMonthName(month) << " " << day << ", " << year << "\n" << "\n";
}

//Function to print in date format: January, 2 1990
void Date::printDayMonthNameYear() const {
	cout << day << " " << getMonthName(month) << ", " << year << "\n" << "\n";
}

int Date::dayCount()const {
	int days = 0;
	
	for (int y = 0; y < year;++y) {
		days += isLeapYear(y) ? 366 : 365;
	}

	for (int m = 1; m < month;++m) {
		days += lastDay(m,year);
	}

	days += day;
	return days;
}
int Date::dayCount(int m, int d, int y)const {
	int days = 0;

	for (int y = 0; y < year;++y) {
		days += isLeapYear(y) ? 366 : 365;
	}

	for (int m = 1; m < month;++m) {
		days += lastDay(m, year);
	}

	days += day;
	return days;
}

Date& Date::operator++() {
	++day;
	if (day > lastDay(month, year)) {
		day = 1;
		++month;
		if (month > 12) {
			month = 1;
			++year;
		}
	}
	return *this;
}
Date Date::operator++(int) {
	Date temp = *this;
	++day;
	if (day > lastDay(month, year)) {
		day = 1;
		++month;
		if (month > 12) {
			month = 1;
			++year;
		}
	}
	return temp;
}

Date& Date::operator--(){
	--day;
	if (day < 1) {
		--month;
		if (month < 1) {
			month = 12;
			--year;
		}
		day = lastDay(month, year);
	}
	return *this;
}
Date Date::operator--(int) {
	Date temp = *this;
	--day;
	if (day < 1) {
		--month;
		if (month < 1) {
			month = 12;
			--year;
		}
		day = lastDay(month, year);
	}
	return temp;
}

int Date::operator-(const Date& other) {
	int diff = this->dayCount() - other.dayCount();
	return diff >= 0 ? diff : -diff;
}



istream& operator>>(istream& in, Date& date) {
	string input;
	int m, d, y;
	char slash;
	
	while (true) {
		cout << "Enter Month/Day/Year: ";
		getline(in, input);
		istringstream iss(input);
		if (iss >> m >> slash >> d >> slash >> y && slash == '/') {
			date.setDate(m, d, y);
			break;
		}else{
			cout << "Invalid format! Please use MM/DD/YYYY." << endl;	
			}
	}
	return in;
}

ostream& operator<<(ostream& out, const Date& date) {
	out << date.getMonthName(date.month) << " " << date.day << ", " << date.year << endl;
	return out;
}