//Date.cpp - Date class implementation
#include <iostream>
#include "Date.h"
#include <string>

using namespace std;

Date::Date(int m, int d, int y) {
	setDate(m, d, y);
}

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

int Date::lastDay() const {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	}
	return 31;
}

int Date::lastDay(int month, int year) const {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	}
	return 31; 
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

bool Date::isLeapYear() const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);


}
bool Date::isLeapYear(int year) const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Date::printMonthNameDayYear() const {
	cout << getMonthName(month) << " " << day << ", " << year << "\n";
}

void Date::printDayMonthNameYear() const {
	cout << day << " " << getMonthName(month) << ", " << year << "\n";
}