//Date Class Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    cout << "Test default constructor:" << "\n";
    Date date;
    date.printMonthDayYear();
    
    cout << "Test constructor with valid date (2/28/2009):" << "\n";
    Date date1(2, 28, 2009);
    date1.printMonthDayYear();
    
    cout << "Test constructor with invalid month (45/2/2009):" << "\n";
    Date date2(45, 2, 2009);
    date2.printMonthDayYear();
    
    cout << "Test constructor with invalid day (2/29/2009):" << "\n";
    Date date3(2, 29, 2009);
    date3.printMonthDayYear();

    cout << "Test setDate with bad month (13):" << "\n";
    date.setDate(13,0,0);
    date.printMonthDayYear();

    cout << "Test setDate with bad day (4,31,2009):" << "\n";
    date.setDate(4, 31, 2009);
    date.printMonthDayYear();

    cout << "Test for leap year with bad date (2/29/2009):" << "\n";
    Date date6(2, 29, 2009);
    date6.printMonthDayYear();

    cout << "Test for leap year with good date (2/29/2008):" << "\n";
    Date date7(2, 29, 2008);
    date7.printMonthDayYear();

    cout<< "Test constructor for invalid year (2/22/0):" << "\n";
    Date date8(2, 22, 0);
    date8.printMonthDayYear();

    cout << "Test other print formats" << "\n";
    date7.printMonthNameDayYear();
    date7.printDayMonthNameYear();

}
