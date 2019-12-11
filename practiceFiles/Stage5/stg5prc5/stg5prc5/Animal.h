#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;
namespace jwp {

	const string CATNAME = "Daddy";

	class Cat
	{
	public:
		Cat();
		virtual ~Cat();
		void speak();
	};

}

#endif