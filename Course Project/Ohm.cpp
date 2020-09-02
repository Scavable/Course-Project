#include "Ohm.h"

#include <iostream>

using namespace std;

void SolveR();
void SolveI();
void SolveV();

float i, r, v, result;
bool verify = false;
const __int64 max = numeric_limits<streamsize>::max();

//User input determines process
void Ohm::Solve()
{
	//Clearing the consolse screen and cin
	system("CLS");
	

	verify = false;
	char choice;

	while (!verify) {

		cout << "What variable would you like to solve for: R, I, or V?" << endl;
		cin >> choice;

		if (cin) {

			choice = toupper(choice);

			switch (choice) {

			case 'R':
				SolveR();
				verify = true;
				break;

			case 'I':
				SolveI();
				verify = true;
				break;

			case 'V':
				SolveV();
				verify = true;
				break;

			default:
				cout << "Incorrect input" << endl;
				break;
			}
		}

	}

}

//Solve for resistance
void SolveR()
{
	system("CLS");

	verify = false;

	cout << "Solving for R (Resistance): R = V (Voltage) / I (Current)" << endl;

	while (!verify) {

		cout << "Please enter a value for V: ";
		cin >> v;
		if (!cin) {
			cin.clear();
			cin.ignore(max, '\n');
		}
		else {
			cout << "Please enter a value for I: ";
			cin >> i;
			if (!cin) {
				cin.clear();
				cin.ignore(max, '\n');
			}
			else {
				verify = true;
				result = v / i;
				cout << "R (Resistance) is: " << result << endl;
				system("pause");
			}
		}
	}
}
//Solve for current
void SolveI()
{
	system("CLS");

	verify = false;

	while (!verify) {
		cout << "Please enter a value for V (Voltage): ";
		cin >> v;
		if (!cin) {
			cin.clear();
			cin.ignore(max, '\n');
		}
		else {
			cout << "Please enter a value for R (Resistance): ";
			cin >> r;
			if (!cin) {
				cin.clear();
				cin.ignore(max, '\n');
			}
			else {
				verify = true;
				result = v / r;
				cout << "I (Current) is: " << result << endl;
				system("pause");
			}
		}
	}
}

//Solve for voltage
void SolveV()
{
	system("CLS");

	verify = false;

	while (!verify) {
		cout << "Please enter a value for I (Current): ";
		cin >> i;
		if (!cin) {
			cin.clear();
			cin.ignore(max, '\n');
		}
		else {
			cout << "Please enter a value for R (Resistance): ";
			cin >> r;
			if (!cin) {
				cin.clear();
				cin.ignore(max, '\n');
			}
			else {
				verify = true;
				result = i * r;
				cout << "V (Voltage) is: " << result << endl;
				system("pause");
			}

		}

	}

}
