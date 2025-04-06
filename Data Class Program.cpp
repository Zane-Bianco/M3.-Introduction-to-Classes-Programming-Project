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
    
    cout << "Use a Date object to test setDate()function and display using the third format:" << "\n";
    date.setDate(4, 2, 2004); //Using date object and setting it to 4/2/2004
    date.printDayMonthNameYear(); // Updated date object now being displayed (2,April,2004)

    cout << "Test setDate() with 13/45/2018" << "\n";
    date.setDate(13, 45, 2018);//Using date object and setting it to 13/45/2018
    date.printDayMonthNameYear(); //Displays default since given an invalid date

    cout << "Test setDate() with 4/31/2000" << "\n";
    date.setDate(4, 31, 2000);//Using date object and setting it to 4/31/2000
    date.printDayMonthNameYear(); //Displays default since given an invalid date

    cout << "Test setDate() with 2/29/2009" << "\n";
    date.setDate(2, 29, 2009);//Using date object and setting it to 2/29/2009
    date.printDayMonthNameYear(); //Displays default since given an invalid date

    cout << "Test operator- with two date objects returning the difference in days" << "\n";
    date.setDate(4, 10, 2014); //Date object 1 
    date1.setDate(4, 18, 2014);//Date object 2
    int difference = date - date1; //calls operator-
    cout << "The difference in days is: " << difference << "\n" << "\n"; //displays absolute value of difference in days

    cout << "Test operator- with two date objects returning the difference in days"<<"\n";
    date.setDate(2, 2, 2006);//Date object 1
    date1.setDate(11, 10, 2003);//Date object 2
    int difference2 = date - date1;//calls operator-
    cout << "The difference in days is: " << difference2 << "\n" << "\n";//displays absolute value of difference in days
    
    cout<<"Test pre-increment operator (starting date 2/29/2008)" << "\n";  /////Verify that the dates are correct in #9 & #10 in instructions, assuming vice-versa
    date.setDate(2, 29, 2008); //set Date to 2/29/2008
    ++date;//pre-increment is called 
    date.printMonthDayYear(); //display the pre-decremented date

    cout<<"Test pre-decrement operator" << "\n";
    --date;//pre-decrement is called
    date.printMonthDayYear(); //display the pre-incremented date
   
    cout << "Test post-increment operator (starting date 2/29/2008) and show initial date before change" << "\n";
    date.setDate(2, 29, 2008); //set Date to 2/29/2008
    Date oldDate = date++; //post-increment is called
    oldDate.printMonthDayYear();//displays the old date before it is postincremented
    date.printMonthDayYear();//display the post-incremented date
    
    cout << "Test post-decrement operator" << "\n";
    date--;//post-decrement is called
    date.printMonthDayYear(); //display the post-decremented date

    cout << "Test year overlap with post-increment operator(12/31/2024)" << "\n";
    date.setDate(12, 31, 2024);//set Date to 12/31/2024
    date++; //post-increment is called
    date.printMonthDayYear();//display the post-incremented date to verify that its 1/1/2025
    
    cout << "Test year overlap with post-decrement operator(1/1/2025)" << "\n";
    date--;
    date.printMonthDayYear();//display the post-decremented date to verify that its 12/31/2024

    cout << "Test year overlap with pre-increment operator(12/31/2024)" << "\n";
    date.setDate(12, 31, 2024);//set Date to 12/31/2024
    ++date; //pre-increment is called
    date.printMonthDayYear();//display the pre-incremented date to verify that its 1/1/2025
    
    cout << "Test year overlap with pre-decrement operator(1/1/2025)" << "\n";
    --date;
    date.printMonthDayYear();//display the pre-decremented date to verify that its 12/31/2024
    
    cout << "Test the cin and the >> operator aswell as the cout and << operator" << "\n";
    Date date11; //Create Date object
    cout << "\nEnter the details for new date" << endl; //Display message to user
    cin>>date11; //operator>> is called 
    cout << date11; //operator<< is called
}
