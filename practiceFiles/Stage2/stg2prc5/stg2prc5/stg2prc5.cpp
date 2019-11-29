#include <iostream>

using namespace std;

int main(){

	//arrays
	int arr[3];

	arr[0] = 5;

	cout << arr[0] << endl;

	double num[4] = { 5.4, 6.2, 7.3, 9.4 };

	for (int i = 0; i < 4; i++) {//output
		cout << num[i] << "\t";
	}
	cout << endl;

	string str2[] = { "lol", "kek", "4eburek" };
	for (int i = 0; i < 3; i++) {//output
		cout << str2[i] << "\t";
	}
	cout << endl;

	//multi arrays
	string narco[2][2][3] = { 
		{
			{"geroin", "lsd", "amfetamin"},
			{"mda", "krokodil", "zebra"}
		},
		{
			{"vint", "cocoine", "smooz"},
			{"lol","kek","4eburek"}
		} 
	};
	for (int l = 0; l < 2; l++) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				cout << narco[l][i][j] << "\t" << flush;
			}
			cout << endl;
		}
		cout << endl;
	}

	//sizeof with array
	cout << sizeof(narco) << endl; //array size
	cout << sizeof(string) << endl; //type size
	cout << sizeof(narco) / sizeof(string) << endl; //count

	for (int l = 0; l < sizeof(narco)/sizeof(narco[0]); l++) {
		for (int i = 0; i < sizeof(narco[0])/sizeof(narco[0][0]); i++) {
			for (int j = 0; j < sizeof(narco[0][0])/sizeof(string); j++) {
				cout << narco[l][i][j] << "\t" << flush;
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << sizeof(narco[0]) << endl;
	cout << sizeof(narco[0][0]) << endl;

	//switch
	int value = 5, kek = 0;

	switch (value) {
	case 1:
		kek = 6;
		break;
	case 5:
		kek = 7;
		value++;
		break;
	case 6:
		kek *= 2;
		value = 0;
		break;
	default:
		kek = 1;
		value = 1;
	}
	value *= kek;
	cout << kek << " " << value << " " << kek + value << endl;
	return 0;
}