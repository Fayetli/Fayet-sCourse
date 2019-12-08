#include <iostream>

using namespace std;

void manip(int a) {
	a *= 2;
}

void manip(int* a) {
	*a = *a * 2;
}


int main()
{
	int k = 5;
	cout << "number: " << k << endl;

	manip(k);
	cout << "number: " << k << endl;

	manip(&k);
	cout << "number: " << k << endl;

	int* pk = &k;
	cout << "number: " << *pk << endl;

	cout << "pointer: " << pk << endl;

	string texts[] = { "first", "second", "third" };

	string *pTexts = texts;

	cout << *pTexts << " " << *(pTexts + 1) << " " << *(pTexts + 2) << endl;

	string* endTexts = &texts[2];
	string* startTexts = &texts[0];

	while(true) {
		cout << *startTexts << endl;
		if (startTexts == endTexts)
			break;
		startTexts++;
	}
	cout << "End!" << endl;

}
