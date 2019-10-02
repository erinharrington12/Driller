
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iomanip>
using namespace std;

struct drillingRecord { //Data for each record
	string strings[2]; //Holds the string data, in column order (date,time)
	double nums[16]; //Holds the numeric data, in column order (floating-points)
};

struct drillingArray { //The array of records
	int capacity; // Maximum capacity, in records
	drillingRecord* data = NULL; // Pointer to array of records
};



drillingArray* doubleDrillingArray(drillingArray* currentDrillingArray) {
	int doubledCapacity = currentDrillingArray->capacity * 2;
	drillingArray* newDrillingArray = new drillingArray;
	drillingRecord* doubledRecords = new drillingRecord[doubledCapacity];
	for (int i = 0; i < currentDrillingArray->capacity; i++) {
		doubledRecords[i].strings[0] = currentDrillingArray->data[i].strings[0];
		doubledRecords[i].strings[1] = currentDrillingArray->data[i].strings[1];
		for (int j = 0; j < 16; j++) {
			doubledRecords[i].nums[j] = currentDrillingArray->data[i].nums[j];
		}


	}

	newDrillingArray->capacity = doubledCapacity;
	newDrillingArray->data = doubledRecords;

	delete currentDrillingArray;
	doubledRecords = NULL;



	return newDrillingArray;
}

void dataLoop(bool loopEntered) {


	
}

int main()
{
	string fileName;
	ifstream currentFile;
	bool dataLoop = true;



	//Enters the data input loop

	while (dataLoop == true) {

		cout << "Enter data file name: ";

		cin >> fileName;
		currentFile.open(fileName); //Opens the file

		if (!(currentFile.is_open())) {

			cout << "File is not available" << endl;
			
		}
		else {
			cout << "File opened!" << endl;
			dataLoop = false; //Exits data input loop
		}
	}
	
	
	drillingArray* myArray = new drillingArray;
	myArray->capacity = 10;

	

	myArray->data = new drillingRecord[myArray->capacity]; //Array of DrillingRecord Objects


	//-------------------------------------------------------------------------------------------

	vector <string> timeStamps; //vector for time stamps
	vector <string> dates; //vector for dates
	vector <float> points; //vector for floating points
	int lineNumber = 0;
	int index = 0;
	string time; //Stores the current time
	string values; //Stores the current float point
	string correctDate; //The first time stamp that is compared to all other time stamps
	string input; //Each line is stored in this string
	string date; //Stores the current date
	bool dataManip = true;




	getline(currentFile, input); //Date, time... (ignores this line)

	int size = 0;

	while (dataManip == true) {
		while (dataLoop == true) {

			cout << "Enter data file name: ";

			cin >> fileName;
			currentFile.open(fileName); //Opens the file

			if (!(currentFile.is_open())) {

				cout << "File is not available" << endl;

			}
			else {
				cout << "File opened!" << endl;
				dataLoop = false; //Exits data input loop
				dataManip = true;
			}
		}
		while (getline(currentFile, input)) { //Grabs first line of data // Data manipulation loop
			if (lineNumber == myArray->capacity) {
				myArray = doubleDrillingArray(myArray);

			}


			drillingRecord currentRecord;
			istringstream lineStream(input); //Creates a stream out of input
			getline(lineStream, date, ','); //Gets first date before the first comma
			++lineNumber;
			dates.push_back(date); //Pushes back date into the dates vector
			currentRecord.strings[0] = dates.at(0);
			getline(lineStream, time, ','); //Stores first time stamp in "time"

			//getline(lineStream, values, ','); //Stores the first floating-point value in "values"





			correctDate = dates.at(0); //Sets the correct date to the first value in the dates vector
			if (dates.at(lineNumber - 1).compare(correctDate) != 0) { //Compares the current date to the correct date 
				cout << "Non-matching date stamp " << dates.at(lineNumber -1 ) << " at line " << lineNumber << "." << endl;
				
				
				
			}
			else {
				bool isValid = true;
				index = 0;
				while (getline(lineStream, values, ',')) { //Checks if the current float value is zero or negative

					float floatValues = stof(values);
					points.push_back(floatValues);
					currentRecord.nums[index] = floatValues;
					if (floatValues <= 0) {
						points.clear();
						cout << "Invalid floating-point data at line " << lineNumber << "." << endl;
						isValid = false;
						++index;
						break;
					}
					++index;
				}
				if (isValid) {
					myArray->data[size] = currentRecord;
					++size;
					timeStamps.push_back(time);
					currentRecord.strings[1] = time;
				}
				
			
				//
				////If current date matches the first date
				//if (find(timeStamps.begin(), timeStamps.end(), time) != timeStamps.end()) { //Tries to find a duplicate time stamp in timeStamps vector
				//	cout << "Duplicate timestamp " << time << " at line " << lineNumber << "." << endl;
				//}

				




			}


		}
		

	}
	
	for (int i = size - 1; i >= 0; i--) {
		cout << myArray->data[i].strings[0] << ";";
		cout << myArray->data[i].strings[1] << ";";

		for (int k = 0; k < 15; k++) {
			cout << fixed << setprecision(2) << myArray->data[i].nums[k] << ";";

		}
		cout << fixed << setprecision(2) << myArray->data[i].nums[15];

		cout << fixed << setprecision(2) << myArray->data[i].nums[1] << ";";
		cout << fixed << setprecision(2) << myArray->data[i].nums[2] << ";";
		cout << fixed << setprecision(2) << myArray->data[i].nums[3] << ";";
		cout << fixed << setprecision(2) << myArray->data[i].nums[4] << ";";
		cout << endl;
	}


	


	return 0;
}