#include <iostream>
#include "utilit.h"

using namespace std;

void textHello() {
	cout << "Hello World!" << endl;
	cout << "How are you?" << endl;
}
void showMenu() {
	cout << "1.Show detail" << endl;
	cout << "2.Plus a number" << endl;
	cout << "3.Minus a number" << endl;
}

int main() {
	int choice = 0;
	int a = 0;

	textHello();

	while (1) {
		showMenu();
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Your number: " << a << endl;
			break;
		case 2:
			addNumber(&a);
			break;
		case 3:
			minusNumber(&a);
			break;
		default:
			cout << "Bad choice." << endl;
		}
	}

}

void addNumber(int* a) {
	*a += 2;

}
void minusNumber(int* a) {
	*a -= 2;
}