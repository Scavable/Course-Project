#include "PackageBid.h"
#include "WF.h"

#include <string>
#include <iostream>

string temp = "";
vector<string> allBids;
WF wf;
const string s1 = "Cost per foot: ";
const string s2 = "Labor per foot: ";
const string s3 = "Wire length: ";
const string s4 = "Bid cost: ";

void PackageBid::MultipleBis(vector<char> wireTypes, vector<float> wireFoots, vector<float> laborFoots, vector<float> wireLengths, vector<float> bidCosts)
{
	allBids.resize(wireTypes.size());
	for (unsigned i = 0; i < wireTypes.size(); i++) {

		//Have to assign currently, char is tricky to append to string
		temp = temp.assign("Wire Type: ") + wireTypes[i];

		//\t does not give even spacing
		temp.append("   " + s1 + to_string(wireFoots[i]) + "   " + s2 + to_string(laborFoots[i]) + "   " + s3 + to_string(wireLengths[i]) + "   " + s4 + to_string(bidCosts[i]));

		allBids[i] = temp;

	}

	//Gives option to save to file
	if (wireTypes.size() > 0) {
		char a;
		cout << "Would you like to save these bids? (Y/N)" << endl;
		cin >> a;
		if (!cin.fail() && toupper(a) == 'Y')
			wf.WFWriteApp(allBids);
		else
			cout << "Did not save" << endl;
	}
}

string PackageBid::SingleBid(char wireType, float wireFoot, float laborFoot, float wireLength, float bidCost)
{
	//Have to assign currently, char is tricky to append to string
	temp = temp.assign("Wire Type: ") + wireType;

	//\t does not give even spacing
	temp.append("   " + s1 + to_string(wireFoot) + "   " + s2 + to_string(laborFoot) + "   " + s3 + to_string(wireLength) + "   " + s4 + to_string(bidCost));


	return temp;
}