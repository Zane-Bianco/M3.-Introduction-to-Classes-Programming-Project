//Number Array Class Program.cpp - Test Program for numArray class



#include <iostream>
#include "numArray.h"
using namespace std;

int main() {

	numArray a(3);

	a.setNumber(0, 2);

	a.setNumber(1, 15);
	a.setNumber(2, 13.1);
	
	a.getNumber(0);
	
	a.getNumber(1);
	
	a.getNumber(2);
	
	a.getMinimum();

	a.getMaximum();

	a.getAverage();

	a.printArray();



}