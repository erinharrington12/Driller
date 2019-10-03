#include "DrillingRecord.h"
using namespace std;
DrillingRecord::DrillingRecord() {

	for (int i = 0; i < MAX_NUMS; ++i) {
		nums[i] = 0.0;
	}
	for (int k = 0; k < MAX_STRINGS; ++k) {
		strings[k] = "";
	}
}

void DrillingRecord::addNum(double num) {
	try {
		if (numCtr > MAX_NUMS) {
			throw new ExceptionIndexOutOfRange;
		}
		nums[numCtr] = num;
		++numCtr;
		
	}
	catch (ExceptionIndexOutOfRange exception)
	{
		cout << "Index out of Range" << endl;
	}

}

void DrillingRecord::addString(std::string string) {
	try {
		if (strCtr > MAX_STRINGS) {
			throw new ExceptionIndexOutOfRange;
		}
		strings[strCtr] = string;
		++strCtr;
	}
	catch (ExceptionIndexOutOfRange exception) {
		cout << "Index out of Range" << endl;
	}
	
}

double DrillingRecord::getNum(unsigned int index) const {
	double number;
	try {
		if (index > MAX_NUMS) {
			throw new ExceptionIndexOutOfRange;
		}
		
		number = nums[index];
		
	}
	catch (ExceptionIndexOutOfRange exception) {
		cout << "Index out of Range" << endl;
	}
	return number;
}

string DrillingRecord::getString(unsigned int index) const {
	string stringCopy;
	try {
		if (index > MAX_STRINGS) {
			throw new ExceptionIndexOutOfRange;
		}
		stringCopy = strings[index];
	}
	catch (ExceptionIndexOutOfRange exception) {
		cout << "Index out of Range" << endl;
	}
	return stringCopy;
}


void DrillingRecord::setNum(double num, unsigned int index) {
	try {
		if (index > MAX_NUMS) {
			throw new ExceptionIndexOutOfRange;
		}
		nums[index] = num;
	}
	catch (ExceptionIndexOutOfRange) {
		cout << "Index out of Range" << endl;
	}
}

void DrillingRecord::setString(std::string string, unsigned int index) {
	try {
		if (index > MAX_STRINGS) {
			throw new ExceptionIndexOutOfRange;
		}
		strings[index] = string;
	}
	catch (ExceptionIndexOutOfRange exception) {
		cout << "Index out of Range" << endl;
	}
}