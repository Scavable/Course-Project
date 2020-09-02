#include "WF.h"
#include<iostream>
#include<fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;



//Writes the bids vector to file and creates the file if it does not exist
void WF::WFWriteApp(vector<string> bids)
{
	fstream file("bids.txt");
	ofstream myFile;

	if (file) {

		cout << "File Exist" << endl;

		myFile.open("bids.txt", ios_base::app);

		if (myFile.is_open()) {

			for (unsigned int i = 0; i < bids.size(); i++)
			{
				myFile << bids[i] << endl;
			}
			myFile.close();
		}
		else {
			cout << "Unable to write to file" << endl;
		}
	}
	else {
		cout << "Creating File" << endl;

		myFile.open("bids.txt", ios_base::app);

		if (myFile.is_open()) {

			for (unsigned i = 0; i < bids.size(); i++)
			{
				myFile << bids[i] << endl;
			}
			myFile.close();
		}
		else {
			cout << "Unable to write to file" << endl;
		}
	}
	system("pause");

}

void WF::WFWrite(vector<string> bids)
{
	fstream file("bids.txt");
	ofstream myFile;

	if (file) {

		cout << "File Exist" << endl;

		myFile.open("bids.txt");

		if (myFile.is_open()) {

			for (unsigned int i = 0; i < bids.size(); i++)
			{
				myFile << bids[i] << endl;
			}
			myFile.close();
		}
		else {
			cout << "Unable to write to file" << endl;
		}
	}
	else {
		cout << "File does not exist" << endl;
	}
	system("pause");

}