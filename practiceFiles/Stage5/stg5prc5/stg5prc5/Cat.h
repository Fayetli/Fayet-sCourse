#ifndef CAT_H
#define CAT_H

#include <iostream>

using namespace std;

namespace cats {

	const string CATNAME = "Freddy";

	class Cat
	{
	public:
		Cat();
		virtual ~Cat();
		void speak();
	private:
	};

}

#endif 