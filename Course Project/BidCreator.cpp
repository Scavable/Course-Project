#include "BidCreator.h"
#include "PackageBid.h"

#include <iostream>

using namespace std;

const __int64 max = max;

PackageBid pb;

//cin, cin.clear(), and cin.ignore() are used to prevent infinite loops on invalid input
void BidCreator::output()
{

	//--------Setup-------------
	system("CLS");

	string questions[4] = { "Wire type for this project (C = copper, A = aluminum): ",
	"Cost per foot: ",
	"Labor per foot: ",
	"Wire length: " };

	int bids;
	char wireType;
	float wireFoot, laborFoot, wireLength;
	bool verify = false;


	vector<char> wireTypes;
	vector<float> wireFoots, laborFoots, wireLengths, bidCosts;

	int arrSize = sizeof(questions) / sizeof(questions[0]);

	//---------------------------

	while (!verify) {
		cout << "How many bids are you entering: ";
		cin >> bids;
		//If input is valid resize vectors to bids size
		if (cin && bids > 0) {
			wireTypes.resize(bids);
			wireFoots.resize(bids);
			laborFoots.resize(bids);
			wireLengths.resize(bids);
			bidCosts.resize(bids);
			//allBids.resize(bids);
			verify = true;
		}
		else {
			cin.clear();
			cin.ignore(max, '\n');
		}

	}

	//Loops based on input
	for (int i = 0; i < bids; i++)
	{
		//Loops based on the amount of questions in array
		for (int j = 0; j < arrSize; j++)
		{
			verify = false;
			while (!verify) {
				//Questions and answers
				switch (j)
				{
				case 0:
					//Wire Type
					cout << questions[j];
					cin >> wireType;

					wireType = toupper(wireType);
					if (cin && wireType == 'C' || wireType == 'A') {
						wireTypes[i] = wireType;
						verify = true;
					}
					else {
						cin.clear();
						cin.ignore(max, '\n');
					}

					break;

				case 1:
					//Wire cost per foot
					cout << questions[j];
					cin >> wireFoot;
					if (cin && wireFoot >= 0.00f) {
						wireFoots[i] = wireFoot;
						verify = true;
					}
					else {
						cin.clear();
						cin.ignore(max, '\n');
					}
					break;

				case 2:
					//Labor cost per foot
					cout << questions[j];
					cin >> laborFoot;
					if (cin && laborFoot >= 0.00f) {
						laborFoots[i] = laborFoot;
						verify = true;
					}
					else {
						cin.clear();
						cin.ignore(max, '\n');
					}
					break;

				case 3:
					//Wire length
					cout << questions[j];
					cin >> wireLength;
					if (cin && wireLength >= 0.00f) {
						wireLengths[i] = wireLength;
						verify = true;
					}
					else {
						cin.clear();
						cin.ignore(max, '\n');
					}
					break;
				}

			}
		}
	}



	for (int i = 0; i < bids; i++)
	{
		bidCosts[i] = (wireFoots[i] * wireLengths[i]) + (wireLengths[i] * laborFoots[i]);

		//Shows the currently inputed bids for the user
		cout << wireTypes[i] << "\t" << wireFoots[i] << "\t" << laborFoots[i] << "\t" << wireLengths[i] << "\t" << bidCosts[i] << endl;

		SetWireTypes(wireTypes);
		SetWireFoots(wireFoots);
		SetLaborFoots(laborFoots);
		SetWireLengths(wireLengths);
		SetBidCost(bidCosts);

	}
	system("pause");
	pb.MultipleBis(wireTypes, wireFoots, laborFoots, wireLengths, bidCosts);
}