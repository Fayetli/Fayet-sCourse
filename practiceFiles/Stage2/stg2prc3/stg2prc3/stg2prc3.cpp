#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//if
	string password = "lolkek";
	
	cout << "Enter you password > " << flush;

	string input;
	cin >> input;

	//cout << "'" <<  input << "'" <<  endl;

	if (input == password) {
		cout << "Done" << endl;
	}
	if (input != password) cout << "Access denied" << endl;

	//if -else
	cout << "Enter command: " << endl;
	cout << "1.\tAdd new record." << endl;
	cout << "2.\tDelete record." << endl;
	cout << "3.\tView record." << endl;
	cout << "4.\tSearch record." << endl;
	cout << "5.\tQuit." << endl;

	int swt = 0;
	cin >> swt;
	if (swt == 1) {
		cout << "Adding a new record..." << endl;

	}
	if (swt > 1 && swt < 5) {
		cout << "You cann`t use this option." << endl;
	}
	if (swt == 5) {
		cout << "Application quitting..." << endl;
	}
	else cout << "False command." << endl;//always cout if swt != 5
	


	//if -else if -else
	int trueNumber = 228, admNumber = 1337;
	int myNumber;

	cout << "Enter the number: " << flush;
	cin >> myNumber;

	if (myNumber == trueNumber)
		cout << "Hello, user." << endl;
	else if (myNumber == admNumber)
		cout << "Hello, admin!" << endl;
	else cout << "Go out!" << endl;

	cout << "Enter command: " << endl;
	cout << "1.\tAdd new record." << endl;
	cout << "2.\tDelete record." << endl;
	cout << "3.\tView record." << endl;
	cout << "4.\tSearch record." << endl;
	cout << "5.\tQuit." << endl;

	int swt1 = 0;
	cin >> swt1;
	if (swt1 == 1) {
		cout << "Adding a new record..." << endl;

	}
	else if (swt1 > 1 && swt1 < 5) {
		cout << "You cann`t use this option." << endl;
	}
	else if (swt1 == 5) {
		cout << "Application quitting..." << endl;
	}
	else cout << "False command." << endl;//cout if swt !=1,2,3,4,5

	//comparing floats
	float fValue1 = 1.1;
	
	if (fValue1 == 1.1f) cout << "equals" << endl;
	else cout << "not equals" << endl;

	cout << setprecision(10) << fValue1 << endl;

	//conditions
	int Value1 = 7;
	int Value2 = 9;
	if (Value1 > 8) cout << "value1 > 8" << endl;
	else if (Value1 == 8) cout << "Value1 = 8" << endl;
	else cout << "Value1 <= 8" << endl;
	if (Value2 > 4 && Value2 < 8) cout << "Value2 e(4;8)." << endl;
	if (Value2 < 4 || Value2 > 8) cout << "Value2 e(-00;4)U(8;+00)." << endl;
	else cout << "Value2 = 4 or 8." << endl;
	if (Value2 != 10) cout << "Value2 != 9" << endl;

	bool cond = (Value2 != 9) && (Value1 > 6);
	cout << cond << endl;
	//end
	return 0;
}
