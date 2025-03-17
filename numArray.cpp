//numArray.cpp - numArray class implementation

#include <iostream>
#include "numArray.h"
#include <cmath>
#include <iomanip>

using namespace std;

// Constructor with size = max_Size, max_Size defaulted to 10
// If size >= 20 or size < 1 size is set to te default size otherwise 
// it makes a pointer to a double array of that size
numArray::numArray(int size) {
	cout << "Constructor: Memory Allocated" << endl;
	if (size >= 20 || size < 1) {
		this ->size = max_Size;
		cerr << "Array size invalid setting default." << endl;
	}
	else {
		this ->size = size;
	}
	arr = new double[this->size]();
}


//Function to assign a value to an index within the array (mutator)
//Sets the specified index to the given value, verifies that the index is within the array
//If index is out of bounds output error and don't store value otherwise set the index to value
void numArray::setNumber(int index, double value) {
	if (index >= size || index < 0) {
		cerr << "Invalid index, number not stored" << endl;

	}
	else {
		arr[index] = round(value*10.0)/10.0;
	}
}

//Function to retrieve the value from the array (accessor)
//Gets the value stored at index after validation by returning it (prints statement for testing)
//If given index fails validation it outputs an error and returns the default value of 0.0
double numArray::getNumber(int index) {
	if (index >= size || index < 0) {
		cerr << "Invalid index, returning default value: 0.0" << endl;
			return 0.0;
	}
	else {
		cout << "The value at index "<< index << " is: " << arr[index] << endl;
		return arr[index];
	}
}

//Function to retrieve the minimum value within the array (accessor)
//Gets the minimum value within the array
//Assigns first element of array to the min variable then compares it to the other elements
//if it finds one that is smaller, it is assigned to the min variable 
//finally returns min value (prints statement for testing)
double numArray::getMinimum() {
	double min = arr[0];
	for (int i = 1; i < size; i++) {
			if (arr[i] < min) {
				min = arr[i];	
			}	
		}
	cout << "The smallest value in the array is: " << min << endl;
	return min;	
	}
	

//Function to retrieve the maximum value within the array (accessor)
//Gets the maxiumum value within the array
//Assigns first element of array to the max variable then compares it to the other elements
//if it finds one that is larger, it is assigned to the min variable 
//finally returns max value (prints statement for testing)
double numArray::getMaximum() {
	double max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << "The largest value in the array is: " << max << endl;
	return max;
}


//Function to calculate the average value within the array (accessor)
//Gets the average of the values within the array. sum variable is set to the first element
//iterates through array adding each index's value to the sum variable 
//returns the sum / the size of the array (prints statement for testing)
double numArray::getAverage() {
	double sum = arr[0];
	for (int i = 1; i < size; i++) {
		(sum += arr[i]);
		}	
	cout << "The average value in the array is: " << sum/size << endl;
	return sum / size;
}
	

//Function to output the values within the array (accessor)
//Print the array by iterating through array one by one and outputting them with a set precision of 1 
//this displays all of the values up to their first decimal place
void numArray::printArray() {
	for (int i = 0; i < size; i++) {
		cout << "{" << fixed << setprecision(1) << arr[i] << "}";
	}
	cout << endl;
}
// Destructor
// Deallocates memory created for the array
numArray::~numArray() {
	delete[] arr;
	cout << "\nDestructor is running" << endl;
}