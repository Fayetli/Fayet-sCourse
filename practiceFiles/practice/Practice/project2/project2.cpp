#include <iostream>
#include <string>

const int thisYear = 2019, thisMonth = 11, thisDay = 20;
using namespace std;



class Birthday {
public:
	Birthday(int d, int m, int y):day(d), month(m), year(y){}
	void getBirthday() {
		cout << day << "." << month << "." << year << endl;
	}
	int getAge() {
		int mYear = thisYear - year;
		if (month > thisMonth) mYear--;
		if (month == thisMonth && day > thisDay) mYear--;
		return mYear;
	}
	Birthday operator-(Birthday& obj) {
		Birthday res;
		res.year = this->year - obj.year;
		return res;
	}
private:
	int day;
	int month;
	int year;
};
class Auto {
public:
	Auto() {

	}
	Auto(string mk, int y, string c):marka(mk), year(y), color(c){}
	void getInfo() {
		cout << "Marka: " << marka << endl;
		cout << "Year: " << year << endl;
		cout << "Color: " << color << endl;
		if(V!=0) cout << "maxV = " << V << endl;
	}
	float V = 0;
	string color;
	string marka;
	int year = 0;
};
class Person {
public:
	void getAllInfo() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Birthday: "; birth.getBirthday();
		if(lenght != 0 ) cout << "Lenght: " << lenght << endl;
		if (setcar == 1) {
			cout << "Car:" << endl;
			car.getInfo();
		}
	}
	Person(string nm, Birthday bd) :name(nm), birth(bd) {
		age = birth.getAge();
	}
	void setCar(Auto cr) {
		car = cr;
		setcar = 1;
	}
	void setLenght(float lg) {
		lenght = lg;
	}
	friend int sov(Person &obj) {
		if (obj.age >= 17) return 0;
		else return 18 - obj.age;
	}
private:
	string name;
	int age;
	Birthday birth;
	Auto car;
	bool setcar = 0;
	float lenght = 0;
};

int main()
{
	Auto akst("Ford Mustang GTX-3 Limited Edition", 2019, "Red");
	akst.V = 500;
	Birthday kbd(20,03,2002);
	Person kst("Kostya", kbd);
	kst.setLenght(182.9);
	kst.setCar(akst);
	kst.getAllInfo();
	Birthday yub(02, 05, 2002);
	Person yu("Yura", yub);
	Auto ayu("Zaporozhec", 1969, "Cherry");
	yu.setCar(ayu);
	yu.getAllInfo();
	cout << sov(yu);
	
}
