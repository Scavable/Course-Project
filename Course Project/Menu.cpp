#include "Menu.h"
#include "Ohm.h"
#include "BidCreator.h"
#include "RF.h"
#include "DeleteFile.h"
#include "BidEditor.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const __int64 max = max;


void Menu::menu()
{

	BidCreator bc;
	Ohm o;
	RF rf;
	BidEditor be;

	//Menu Choices
	string options[] = { "Solve Ohm's law (1)","Create new bids (2)", "Show saved bids (3)", "Show recently inputed bid/s (4)", "Delete file (5)", "Edit saved bids (6)", "Exit (7)" };

	vector<string> bids;

	string input;
	int size, choice = 0;

	//Main part of the program
	//User inputs int and process is determined
	while (true) {

		system("CLS");

		cout << "What would you like to do:" << endl;
		for (string i : options) {
			cout << i << endl;
		}

		getline(cin, input);
		try
		{
			choice = stoi(input);
		}
		catch (const std::exception&)
		{
			cin.clear();
			cin.ignore(max, '\n');
			choice = 0;
		}
		

		
		if (cin && input.size() == 1 && choice > 0 && choice < 8) {
			
			switch (choice) {

			case 1:
				o.Solve();
				break;

			case 2:
				bc.output();
				break;

			case 3:
				cout << endl;
				bids = rf.RFLoad();
				if (!bids.empty()) {
					for (auto i : bids)
					{
						cout << i << endl;
					}
					system("pause");
				}
				break;

			case 4:
				size = bc.GetWireTypes().size();

				if (size > 0) {
					for (int i = 0; i < size; i++) {
						cout << "Wire Type: " << bc.GetWireTypes().at(i) << "   Cost per foot: " << bc.GetWireFoots().at(i) << "   Labor per foot: " << bc.GetLaborFoots().at(i) << "   Wire length: " << bc.GetWireLengths().at(i) << endl;

					}
					system("pause");
				}
				else {
					cout << "No recent bids have been entered." << endl;
					system("pause");
				}
				break;

			case 5:
				DeleteFile();
				break;

			case 6:
				be.EditBids(rf.RFLoad());
				break;
			case 7:
				exit(EXIT_SUCCESS);

			default:
				cout << "Please pick a valid number choice" << endl;
				system("pause");
				break;
			}
		}
		else {
				cout << "Please pick a valid number choice" << endl;
				cin.clear();
				cin.ignore(max, '\n');
				system("pause");

		}
	}
}
