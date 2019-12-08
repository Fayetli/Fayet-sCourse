#include <iostream>

using namespace std;

int main() {

	char text[] = "hello";

	for (int i = 0; i < sizeof(text) - 1; i++)
		cout << i + 1 << ": " << text[i] << endl;

	int k = 0;

	while (true) {

		if (text[k] == 0)
			break;

		cout << text[k] << flush;

		k++;
	}
	cout << endl;

	for (int i = 0; text[i] != 0; i++)
		cout << text[i] << flush;

	cout << endl;

	int nChars = sizeof(text) - 1;

	char* pStart = text;
	char* pEnd = text + nChars - 1;

	while (pStart < pEnd) {

		char save = *pStart;
		*pStart = *pEnd;
		*pEnd = save;

		pStart++;
		pEnd--;

	}

	cout << text << endl;





}