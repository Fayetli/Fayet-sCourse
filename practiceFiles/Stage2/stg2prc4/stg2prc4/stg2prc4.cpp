#include <iostream>

using namespace std;

int main()
{
	int kka = 0;
	//while + break + continue
	while (1) {//(true)
		kka++;
		if (kka == 3) continue;
		cout << "kek" << kka << endl;
		if (kka == 5) break;
	}

	while (kka--) cout << "lol" << kka << endl;
			//5-4-3-2-1			//4-3-2-1-0
	
	//do -while
	const string password = "pizza";
	string myPassword;

	do {
		cout << "Enter password: " << flush;
		cin >> myPassword;

	} while (myPassword != password);
	cout << "Password accepted!" << endl;

	//for + continue
	for (int i = 0; i < 25; i++) {
		if (i % 5) continue;
		cout << i << "\t" << flush;
	}

	int j = 5;
	for (j; j >= 0; j--) {
		if (j == 2) break;
		cout << j << "\t" << flush;
	}

	//end
	return 0;
}
