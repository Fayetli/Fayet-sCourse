#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person {
private:
	string name;

public:
	int age;

	Person();
	Person(string nm, int ag) :name(nm), age(ag) {}
	Person(string name);

	string toString();

	void printName();

	void setName(string nm);

	string getName();


};






#endif // !PERSON_H
