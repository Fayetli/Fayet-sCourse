#ifndef CAT_H
#define CAT_H


class Cat {
public:
	Cat(bool h);
	~Cat();
	void doHappy(bool i);
	void speak();
	void jump();
private:
	bool happy;

};


#endif

