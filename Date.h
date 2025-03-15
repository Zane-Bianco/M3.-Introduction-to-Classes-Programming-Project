#pragma once
#ifndef date_h
#define date_h
#include <string>

using namespace std;


//Date class specification file - define members of the date class and the function defintions
class Date {
private:
	int day, month, year;
public:
	void setDate(int m, int d, int y);
	inline int getDay() const { return day; };
	inline int getMonth() const { return month; };
	inline int getYear() const { return year; };
	bool isLeapYear()const;
	bool isLeapYear(int year)const;
	int lastDay()const;
	int lastDay(int month, int year) const;
	Date(int m = 1, int d = 1, int y = 1900);
	string getMonthName(int month) const;
	void printMonthDayYear() const; //// 12/25/2021
	void printMonthNameDayYear() const; //// December 12, 2021
	void printDayMonthNameYear() const; //// 12 December, 2021
};

#endif
