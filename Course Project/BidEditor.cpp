#include "BidEditor.h"
#include "Menu.h"
#include <conio.h>
#include "WF.h"
#include "PackageBid.h"

#include <iostream>
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13

using namespace std;

const __int64 max = numeric_limits<streamsize>::max();

string EditValues(string bid);

//Reads in saved bids and allows user to edit the values in each bid
vector<string> BidEditor::EditBids(vector<string> bids)
{
	//If no bids are saved return to menu
	Menu m;
	if (bids.empty()) {
		m.menu();
	}

	int c = 0;
	unsigned i = 0;

	WF wf;

	vector<string> temp = bids;
	temp.push_back("Return to menu");

	int size = temp.size();

	system("CLS");


	//Loop until exit choice
	while (true) {
		system("CLS");

		cout << "(Up and Down Arrows) - Transition through each bid" << endl
			<< "(Enter) - Edit bid" << endl << endl;
		cout << "Which bid(s) would you like to edit?" << endl;
		cout << "( " << (i + 1) << " / " << size << " )" << endl;

		cout << temp[i] << endl;

		//Determines case based on detected input
		switch (c = _getch()) {

			//Cycle upward
		case KEY_UP:
			if (i > 0)
				i--;
			else
				i = temp.size() - 1;
			break;
			//Cycle downward
		case KEY_DOWN:
			if (i < temp.size() - 1)
				i++;
			else
				i = 0;
			break;
			//If choice is "Return to menu" return
			//Else send chosen bid to be edited
		case ENTER:
			if (i == size - 1) {
				m.menu();
			}
			else {
				bids[i] = EditValues(bids[i]);
				temp[i] = bids[i];
				wf.WFWrite(bids);
			}
			break;

		default:
			break;
		}

	}
}

//Pulls out the values from the given bid and allows edits
string EditValues(string bid)
{
	PackageBid pb;

	system("CLS");
	//Repackaging strings
	const string s1 = "Cost per foot: ";
	const string s2 = "Labor per foot: ";
	const string s3 = "Wire length: ";
	const string s4 = "Bid cost: ";

	//Body variables
	char wireType = 'X';
	float wireFoot = 0.0f, laborFoot = 0.0f, wireLength = 0.0f, bidCost = 0.0f;
	float wireFootTemp = 0.0f, laborFootTemp = 0.0f, wireLengthTemp = 0.0f;
	bool verify1 = false, verify2 = false, verify3 = false, verify4 = false;
	string tempS = "";

	//Bid to char array
	int length = bid.length();

	int i = 0;
	int temp = 0;

	char newType;

	string choices[] = { "Wire Type", "Wire Cost Per Foot", "Labor Per Foot", "Wire Length", "Save and Return" };
	int size = (sizeof(choices) / sizeof(choices[0]));

	//Seperating out the values
	while (i < length) {

		if ((int)bid.at(i) == 58) {
			i++;
			if ((int)bid.at(i) == 32) {
				i++;
				if (!verify1) {
					wireType = bid.at(i);
					verify1 = true;
				}
				else if (!verify2) {
					while ((int)bid.at(i) != 32) {
						tempS.push_back(bid.at(i));
						i++;
					}
					wireFoot = stof(tempS);
					tempS.clear();
					verify2 = true;

				}
				else if (!verify3) {
					while ((int)bid.at(i) != 32) {
						tempS.push_back(bid.at(i));
						i++;
					}
					laborFoot = stof(tempS);
					tempS.clear();
					verify3 = true;
				}
				else if (!verify4) {
					while ((int)bid.at(i) != 32) {
						tempS.push_back(bid.at(i));
						i++;
					}
					wireLength = stof(tempS);
					tempS.clear();
					verify4 = true;
				}
			}


		}
		i++;
	}

	i = 0;

	//User choice
	while (true) {
		system("CLS");
		cout << "(Up and Down Arrows) - Transition through each field" << endl
			<< "(Enter) - Edit value" << endl << endl;
		cout << "Which value would you like to change?" << endl;
		cout << "( " << (i + 1) << " / " << size << " )" << endl;
		cout << choices[i] << endl;

		switch (int c = _getch()) {

		case KEY_UP:

			if (i > 0)
				i--;
			else
				i = (size - 1);
			break;

		case KEY_DOWN:

			if (i < size - 1)
				i++;
			else
				i = 0;
			break;

			//Terrible case coding
		case ENTER:
			if (i == 0) {
				system("CLS");
				cout << "This will change the Wire Type from" << endl
					<< "Currently: " << wireType << endl
					<< "New Value: " << (wireType == 'C' ? 'A' : 'C') << endl;
				cout << "Change Type? (Y/N) : ";
				cin >> newType;
				cin.ignore();
				newType = toupper(newType);
				if (newType == 'Y')
					wireType = (wireType == 'C' ? 'A' : 'C');
				else {
					cout << "Change not saved" << endl;
					system("pause");
				}

			}
			else if (i == 1) {
				system("CLS");
				cout << "What would you like to change the Cost Per Foot to?" << endl;
				cout << "Currently: " << wireFoot << endl;
				cout << "Change to: ";
				cin >> wireFootTemp;
				if (cin && wireFootTemp > 0.0f) {
					wireFoot = wireFootTemp;
				}
				else {
					cout << "Change could not be saved / Invalid value" << endl;
					cin.clear();
					cin.ignore(max, '\n');
					system("pause");
				}
			}
			else if (i == 2) {
				system("CLS");
				cout << "What would you like to change the Labor Per Foot to?" << endl;
				cout << "Currently: " << laborFoot << endl;
				cout << "Change to: ";
				cin >> laborFootTemp;
				if (cin && laborFootTemp > 0.0f) {
					laborFoot = laborFootTemp;
				}
				else {
					cout << "Change could not be saved / Invalid value" << endl;
					cin.clear();
					cin.ignore(max, '\n');
					system("pause");
				}
			}
			else if (i == 3) {
				system("CLS");
				cout << "What would you like to change the Wire Length to?" << endl;
				cout << "Currently: " << wireLength << endl;
				cout << "Change to: ";
				cin >> wireLengthTemp;
				if (cin && wireLengthTemp > 0.0f) {
					wireLength = wireLengthTemp;
				}
				else {
					cout << "Change could not be saved / Invalid value" << endl;
					cin.clear();
					cin.ignore(max, '\n');
					system("pause");
				}
			}
			else {

				bidCost = (wireFoot * wireLength) + (wireLength * laborFoot);

				cout << endl;
				cout << "Old Bid" << endl << bid << endl << endl;
				cout << "Edited Bid" << endl << pb.SingleBid(wireType, wireFoot, laborFoot, wireLength, bidCost) << endl;
				system("pause");

				return pb.SingleBid(wireType, wireFoot, laborFoot, wireLength, bidCost);

			}
			break;

		default:
			break;
		}

	}

	system("pause");
}