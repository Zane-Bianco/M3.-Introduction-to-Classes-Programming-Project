//Number Array Class Program.cpp - Test Program for numArray class



#include <iostream>
#include "numArray.h"
#include <random>
using namespace std;

int main() {

	//Tests the default constructor
	numArray a;
	cout << "Test default constructor" << endl;
	a.printArray();
	cout << endl;
	
	//Tests constructor with parameters
	numArray b(15);
	cout << "Test constructor with parameter" << endl;
	b.printArray();
	cout << endl;

	//populates b's array with random double values from 0 - 100
	//then prints the array
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dist(0.0, 100.0);
	cout << "Array filled with random doubles" << endl;
	for (int i = 0; i < b.getsize(); i++) {
		b.setNumber(i, dist(gen));
	}
	b.printArray();	
	cout << endl;
	
	//Test for out of bound index
	cout << "Test for setting an invalid index" << endl;
	b.setNumber(20, 2);
	cout << endl;

	//Test for retrieving value at index 5
	cout << "Test for retrieving value at an index" << endl;
	b.getNumber(5);
	cout << endl;

	//Test for retrieving out of bound index 
	cout << "Test for retrieving invalid index" << endl;
	b.getNumber(20);
	cout << endl;

	//Test for getting the minumum value within the array
	b.getMinimum();
	cout << endl;

	//Test for getting the maximum value within the array
	b.getMaximum();
	cout << endl;

	//Test for retrieving the average of the values within the array
	b.getAverage();
	
	



}