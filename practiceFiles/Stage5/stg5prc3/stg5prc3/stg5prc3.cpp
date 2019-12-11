#include <iostream>

using namespace std;

class Animal {
private:
	string name;
public:
	Animal() {//constructor
		cout << "Animal created." << endl;
	}
	Animal(const Animal &other):name(other.name) {//copy constructor
		//this->name = other.name;
		other.speak(); //can use only when this function is const
		cout << "Animal created by copying." << endl;
	}
	~Animal() {//destructor
		cout << "Animal deleted." << endl;
	}
	void setName(string name) {//function
		this->name = name;
		name = this->name + "25";
		this->name = name;//joker's trap
	}
	void speak() const {
		cout << "My name is: " << name << endl;
	}
};

Animal *createAnimal() {//function that return an object
	Animal *pAnimal = new Animal;
	pAnimal->setName("Bertie");
	return pAnimal;
}

int main() {

	/*int value = 7;
	const double PI = 3.1415;

	cout << value << endl;
	cout << PI << endl;

	Animal korowa;
	korowa.setName("Furri");
	korowa.speak();

	//const int * const pValue = &value;
	int *pValue = &value;

	cout << *pValue << endl;

	int number = 11;

	pValue = &number; //Error with this: int * const pValue = &value;

	*pValue = 12; //Error with this: const int *pValue = &value;

	cout << *pValue << endl;

	Animal dog;

	dog.setName("Petuh");

	Animal cat = dog;

	dog.speak();
	cat.speak();

	cat.setName("Ne petuh");

	cat.speak();

	Animal chicken(cat);

	chicken.speak();*/

	Animal* pCat = new Animal();

	(*pCat).setName("Loopy");
	pCat->speak();

	//cout << sizeof(pCat) << endl;

	Animal *pFrog = createAnimal();

	pFrog->speak();

	Animal* pAnimal = new Animal[10];

	int a = 5;
	pAnimal[a].setName("kek");
	pAnimal[a].speak();

	delete[] pAnimal;

	char* pMem = new char[100];
	delete[] pMem;

	char c = 'l';
	c++; //up number in ASCII table
	string name(5, c);
	cout << name << endl;


	delete pFrog;
	delete pCat; //unlock the memory

	//Animal* pCat2 = NULL;

	return 0;
}