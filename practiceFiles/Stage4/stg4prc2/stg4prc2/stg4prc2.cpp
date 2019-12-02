#include <iostream>
#include "Person.h"
#include <sstream>

using namespace std;

int main() {

	Person pers;

	cout << pers.toString() << endl;

	pers.setName("Valakas");
	pers.printName();
	pers.age = 65;

	cout << pers.toString() << endl;


	{
		Person kek("Glad", 84);
		cout << kek.toString() << endl;
	}
	{
		Person lol("Vasya");
		cout << lol.toString() << endl;
	}





	stringstream kek;

	kek << "lol kek ";
	kek << 18;
	kek << " 4eburek ";
	kek << pers.getName();
		
	string info = kek.str();
	cout << info << endl;






	return 0;
}