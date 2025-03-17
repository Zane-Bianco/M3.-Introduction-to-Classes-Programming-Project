//numArray.cpp - numArray class implementation

#include <iostream>
#include "numArray.h"

using namespace std;

// Constructor with size = max_Size, max_Size defaulted to 10 
numArray::numArray(int size) {
	cout << "Constructor: Memory Allocated" << endl;
	if (size > 20 || size < 1) {
		this ->size = max_Size;
		cerr << "Array size invalid setting default." << endl;
	}
	else {
		this ->size = size;
	}
	arr = new double[this->size]();
}


//Function to assign a value to an index within the array (mutator)
void numArray::setNumber(int index, double value) {
	if (index > size || index < 0) {
		cerr << "Invalid index";

	}
	else {
		arr[index] = value;
	}
}

//Function to retrieve the value from the array (accessor)
double numArray::getNumber(int index) {
	if (index >= size || index < 0) {
		cerr << "Invalid index";
			return 0.0;
	}
	else {
		return arr[index];
	}
}

//Function to retrieve the minimum value within the array (accessor)
double numArray::getMinimum() {
	double min = arr[0];
	for (int i = 1; i < size; i++) {
			if (arr[i] < min) {
				min = arr[i];	
			}	
		}
	return min;	
	}
	

//Function to retrieve the maximum value within the array (accessor)
double numArray::getMaximum() {
	double max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}


//Function to calculate the average value within the array (accessor)
double numArray::getAverage() {
	double sum = arr[0];
	for (int i = 1; i < size; i++) {
		(sum += arr[i]);
		}	
	return sum / size;
}
	

//Function to output the values within the array (accessor)
void numArray::printArray() {
	for (int i = 0; i < size; i++) {
		cout << "{" << arr[i] << "}";
	}
}
// Destructor
numArray::~numArray() {
	delete[] arr;
	cout << "\nDestructor: Memory Deallocated" << endl;
}