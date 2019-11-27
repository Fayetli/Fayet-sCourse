#include <iostream>
#include <limits> //to see a type limits
#include <iomanip>//to manipulate with float type

using namespace std;

int main()
{
	//int type
	int intValue = 228;
	cout << intValue << endl;
	cout << "Max int value: " << INT_MAX << endl;
	cout << "Min int value: " << INT_MIN << endl;

	long int intLongValue = 372573543;
	cout << intLongValue << endl;

	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of short int: " << sizeof(short int) << endl;
	cout << "Max unsigned int:" << UINT_MAX << endl;
	cout << "Max unsigned long int:" << ULONG_MAX << endl;//proc limit???

	//float and double types
	float floatValue = 22.8;
	cout << setprecision(10) << fixed << floatValue << endl;
	cout << scientific << floatValue << endl;
	cout << "Size of float: " << sizeof(float) << endl;

	double dValue = 22.8;
	cout << setprecision(20) << fixed << dValue << endl;
	cout << "Size of double: " << sizeof(dValue); //???

	long double ldValue = 22.81337419420123456789;
	cout << setprecision(20) << fixed << ldValue << endl;
	cout << "Size of long double: " << sizeof(long double) << endl;

	//other Types
	bool bValue = false;//=0
	bool bValue1 = true;//=1
	bValue = 1;
	cout << bValue << endl;

	char cValue = 55;//7, but char(no number)
	cout << cValue << endl;
	char cValue1 = '7';//also 7, and also char
	cout << (int)cValue << endl;//55(number in ASCII)
	cout << "Size of char: " << sizeof(cValue) << endl;//1

	wchar_t wValue = 'i';
	cout << wValue << endl;//105
	cout << (char)wValue << endl;//i

	//end
	return 0;
}