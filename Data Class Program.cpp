//Date Class Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"
#include <string>
using namespace std;

int main()
{
    Date date;
    date.printMonthDayYear();
    
    Date date1(2, 28, 2009);
    date1.printMonthDayYear();
    
    Date date2(45, 2, 2009);
    date2.printMonthDayYear();

    Date date3(2, 29, 2009);
    date3.printMonthDayYear();

    Date date4(13);
    date4.printMonthDayYear();

    Date date5(4, 31, 2009);
    date5.printMonthDayYear();

    Date date6(2, 29, 2009);
    date6.printMonthDayYear();

    Date date7(2, 29, 2008);
    date7.printMonthDayYear();

    date7.printMonthNameDayYear();
    date7.printDayMonthNameYear();
}
