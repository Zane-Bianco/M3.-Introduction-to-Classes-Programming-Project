//Date.cpp - Date class implementation
#include <iostream>
#include "Date.h"
#include <string>

using namespace std;

Date::Date(int m, int d, int y) {
	setDate(m, d, y);
}

void Date::setDate(int m, int d, int y) {
	day = d;
	month = m;
	year = y;

	if (m < 1 || m > 12) {
		cout << "Month Invalid\n";
		day = 1;
		month = 1;
		year = 1900;
	}
	if (y < 1) {
		cout << "Year Invalid\n";
		day = 1;
		month = 1;
		year = 1900;
	}

	if (d > lastDay() || d < 1) {
		cout << "Day Invalid\n";
		day = 1;
		month = 1;
		year = 1900;
	}
};


int Date::lastDay(int month, int year) const {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	}
	return 31; 
};

bool Date::isLeapYear(int year) const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Date::printMonthDayYear() const {
	cout << month << "/" << day << "/" << year <<"\n" <<"\n";
}

string Date::getMonthName(int month) const {
	const string monthnames[12]{ "January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December" };
	return monthnames[month - 1];
}

void Date::printMonthNameDayYear() const {
	cout << getMonthName(month) << " " << day << ", " << year;
}

void Date::printDayMonthNameYear() const {
	cout << day << " " << getMonthName(month) << ", " << year;
}