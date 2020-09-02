#pragma once
#include <vector>

using namespace std;

class BidCreator
{
private:
	vector<char> wireTypes;
	vector<float> wireFoots, laborFoots, wireLengths, bidCosts;

public:
	void output();
	//Setters
	void SetWireTypes(vector<char> temp) {
		wireTypes = temp;
	};
	void SetWireFoots(vector<float> temp) {
		wireFoots = temp;
	};
	void SetLaborFoots(vector<float> temp) {
		laborFoots = temp;
	};
	void SetWireLengths(vector<float> temp) {
		wireLengths = temp;
	};
	void SetBidCost(vector<float> temp) {
		bidCosts = temp;
	};

	//Getters
	vector<char> GetWireTypes() {
		return wireTypes;
	};
	vector<float> GetWireFoots() {
		return wireFoots;
	};
	vector<float> GetLaborFoots() {
		return laborFoots;
	};
	vector<float> GetWireLengths() {
		return wireLengths;
	};

};