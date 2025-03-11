#pragma once
#ifndef date_h
#define date_h
//Date class specification file - define members of the date class and the function defintions

class Date {
private:
	int day, month, year;
public:
	void setDate(int d, int m, int y);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	bool isLeapYear();
	bool isLeapYear(int year);
	int lastDay();
	int lastDay(int month, int year);
	Date(int m = 1, int d = 1, int y = 1990);
};

#endif
