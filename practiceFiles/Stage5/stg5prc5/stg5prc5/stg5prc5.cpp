#include <iostream>
#include "Cat.h"//cat here
#include "Animal.h"//and cat here

using namespace std;

using namespace jwp;//to use jwp class


//Could declare variables here: string texts[] = {"apple", "orange", "banana"}; //to create a global massive

void show1(const int nElements, string texts[]) {

	cout << sizeof(texts) << endl; //returns size of pointer

	for (int i = 0; i < nElements; i++) {
		cout << texts[i] << endl;
	}
}//equ
void show2(const int nElements, string *texts) {

	cout << sizeof(texts) << endl; //returns size of pointer

	for (int i = 0; i < nElements; i++) {
		cout << texts[i] << endl;
	}
}
void show3(string (&texts)[3]) {

	cout << sizeof(texts) << endl; //returns size of pointer

	for (int i = 0; i < sizeof(texts)/sizeof(string); i++) {
		cout << texts[i] << endl;
	}
}

//string* getArray() {
	//Dont return pointers to local variable!: string texts[] = { "apple", "orange", "banana" };

	//return texts;
//}

char* getMemory() {
	char* pMem = new char[100];

	return pMem;
}

void freeMemory(char* pMem) {
	delete[] pMem;
}
int main()
{
	
	string texts[] = {"apple", "orange", "banana"};

	cout << sizeof(texts) << endl; //returns size of massive

	show3(texts);



	char* pMemory = getMemory();

	freeMemory(pMemory);

	Cat bars;
	bars.speak();

	cats::Cat Vlasik;
	Vlasik.speak();

	cout << cats::CATNAME << endl;
	cout << CATNAME << endl;




	return 0;
}