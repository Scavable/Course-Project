#pragma once
#include <vector>
#include <string>

using namespace std;

class PackageBid
{
public:
	void MultipleBis(vector<char> wireTypes, vector<float> wireFoots, vector<float> laborFoots, vector<float> wireLengths, vector<float> bidCosts);
	string SingleBid(char wireType, float wireFoot, float laborFoot, float wireLength, float bidCost);
};