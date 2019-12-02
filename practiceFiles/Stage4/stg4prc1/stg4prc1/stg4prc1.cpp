#include <iostream>

#include "Cat.h"

using namespace std;

int main() {
	cout << "Start" << endl;

	{
		Cat bars(0);
		bars.speak();
		bars.jump();
		bars.doHappy(1);
		bars.speak();
	}

	cout << "End" << endl;

}