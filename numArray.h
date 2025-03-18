// numArray class specification file - define members and functions of the class
#pragma once
#ifndef numArray_h
#define numArray_h

using namespace std;

class numArray {
	private:
		double* arr;
		int arr_Size; 
		static const int max_Size = 10; //Default array size
	public:
		numArray(int size = max_Size); // Constructor
		void setNumber(int index, double value); //Function to assign a value to an index within the array (mutator)
		double getNumber(int index); //Function to retrieve the value from the array (accessor)
		double getMinimum(); //Function to retrieve the minimum value within the array (accessor)
		double getMaximum(); //Function to retrieve the maximum value within the array (accessor)
		double getAverage(); //Function to calculate the average value within the array (accessor)
		void printArray(); //Function to output the values within the array (accessor)
		inline int getsize() { return arr_Size; }; //Function to return size (accessor)
		~numArray(); // Destructor

};






#endif