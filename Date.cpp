//Date.cpp - Date class implementation
#include <iostream>
#include "Date.h"


Date::Date(int m, int d, int y) {
	setDate(m, d, y);
}

void Date::setDate(int m, int d, int y) {
	
	if (m < 1 || m > 12) {
		std::cerr << "Month Invalid";
			day = 1;
			month = 1;
			year = 1990;
		if (y < 1) {
			std::cerr << "Year Invalid\n";
			day = 1;
			month = 1;
			year = 1990;

	}
	}
	if (d > lastDay() || d < 28) {
		std::cerr << "Invalid day. Setting default date: 1/1/1990\n";
		day = 1;
		month = 1;
		year = 1990;
	}
	else {
		day = d;
		month = m;
		year = y;
	}
};

int Date::lastDay() {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	}
	return 31;
};

int Date::lastDay(int month, int year) {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	}
	return 31; 
};

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

bool Date::isLeapYear() {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

