#pragma once
#ifndef date_h
#define date_h
//Date class specification file - define members of the date class and the function defintions

class Date {
private:
	int day, month, year;
public:
	Date(int m = 1, int d = 1, int y = 1990) {
		day = d;
		month = m;
		year = y;
	}
	void setDate(int month, int day, int year);

};

#endif
