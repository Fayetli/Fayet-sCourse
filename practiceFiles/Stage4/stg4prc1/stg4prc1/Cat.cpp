#include <iostream>

#include "Cat.h"

using namespace std;

Cat::Cat(bool h):happy(h){
	cout << "Hello, cat!" << endl;
}
Cat::~Cat() {
	cout << "Bye, cat!" << endl;
}
void Cat::speak(){
	if (happy) cout << "Meow-Meow" << endl;
	else cout << "Arrrg" << endl;
}
void Cat::doHappy(bool i) {
	if (i == 1) happy = true;
	else happy = false;
}
void Cat::jump() {
	cout << "Cat jumped up" << endl;
}
