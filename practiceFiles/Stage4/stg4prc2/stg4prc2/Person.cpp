#include "Person.h"
#include <iostream>
#include <sstream>

Person::Person() {
	name = "undefined";
	age = 0;
}

Person::Person(string name):age(0){
	this->name = name;
}

void Person::printName() {
	cout << "Person's name is: " + name << endl;
}

void Person::setName(string nm) {
	name = nm;
}

string Person::getName() {
	return name;
}

string Person::toString() {
	stringstream ss;

	ss << "Name: " << name << ";" << endl;
	ss << "Age: " << age << ".";

	return ss.str();
}