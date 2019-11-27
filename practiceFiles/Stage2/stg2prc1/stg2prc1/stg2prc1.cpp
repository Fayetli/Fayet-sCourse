#include <iostream>

using namespace std;

int main()
{
	//Variable
	int number4ebureks = 5;
	int numberHotdogs = 7;
	int numberFoods = number4ebureks + numberHotdogs;

	cout << number4ebureks << endl;
	cout << numberFoods << endl;
	
	numberFoods = numberFoods + 1;
	numberFoods += 1;

	cout << numberFoods << endl;

	//Strings
	string myString = "Hello, wigga! How are you?";
	
	cout << myString << endl;

	myString = "Hello, wigga! How are you?\n";

	cout << myString;

	string text1 = "Yooo ";
	string text2 = "Wigga";
	string text3 = text1 + text2;
	cout << text1 << text2 << endl << text3 << endl;

	//UserInput
	cout << "Enter what you want: " << flush;

	string whatWant;

	cin >> whatWant;

	cout << "You want a(an) " << whatWant << endl;

	cout << "Enter a number: " << flush;

	int value;
	cin >> value;

	cout << "You entered: " << value << endl;

	//end
}
