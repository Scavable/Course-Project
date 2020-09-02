#include "RF.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <string>


using namespace std;

vector<string> RF::RFLoad()
{
	vector<string> bids;
	string line;
	fstream file("bids.txt");
	ifstream myFile;

	if (file) {
		myFile.open("bids.txt");

		if (myFile.is_open()) {
			while (getline(myFile, line)) {
				bids.push_back(line);
			}
			myFile.close();
		}
	}
	else {
		cout << "Unable to open file" << endl;
		system("pause");
	}
	return bids;
}