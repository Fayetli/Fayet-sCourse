#include <iostream>

using namespace std;

short int *pn = new short int;


class bts {
public:
    bts() {}
    bts(string name, short int age, short int rating):name(name),age(age),rating(rating) {}
    string name;
    short int age;
    short int rating;
    /*short int skillRate;
    short int length;
    string hairColor;*/
};

void menu() {
    cout << "1. Create a new person." << endl
        << "2. Edit a person." << endl
        << "3. Delete a person." << endl
        << "4. Print all persons." << endl;
}

short int checkChoose() {
    short int choose = 0;
        cout << "Enter a number: " << flush;
        cin >> choose;
    return choose;
}

int main()
{
    short int choose1 = 0, choose2 = 0;
    *pn = -1;
    bts* pbts = new bts[7];

    pbts[0].name = "Taemin";
    pbts[0].age = 27;
    pbts[0].rating = 10;

    pbts[1].name = "lol";
    pbts[1].age = 25;
    pbts[1].rating = 9;

    pbts[2].name = "kek";
    pbts[2].age = 23;
    pbts[2].rating = 8;
    *pn = 2;

    while (true) {
        menu();
        switch (checkChoose()) {
            case 1:
                if (*pn == 6) {
                    cout << "You create all persons!";
                    break;
                }
                *pn = *pn + 1;
                cout << "Person's number: " << *pn + 1 << endl;
                cout << "Enter name: " << flush;
                cin >> pbts[*pn].name;
                cout << "Enter age: " << flush;
                cin >> pbts[*pn].age;
                cout << "Enter rating: " << flush;
                cin >> pbts[*pn].rating;
                break;
            case 2:
                cout << "num | name | age | rating" << endl;
                for (short int i = 0; i <= *pn; i++) {
                    cout << i + 1 << " | " << pbts[i].name << " | " << pbts[i].age << " | " << pbts[i].rating << endl;
                }
                cout << "Enter the number of person: " << flush;
                cin >> choose1;
                choose1--;
                while (choose2 != 4) {
                    cout << "1. Name" << endl
                        << "2. Age" << endl
                        << "3. Rating" << endl
                        << "4. Nothing" << endl;
                    cout << "What you want to edit: ";
                    cin >> choose2;
                    switch (choose2) {
                    case 1:
                        cout << "Enter name: " << flush;
                        cin >> pbts[choose1].name;
                        break;
                    case 2:
                        cout << "Enter age: " << flush;
                        cin >> pbts[choose1].age;
                        break;
                    case 3:
                        cout << "Enter rating: " << flush;
                        cin >> pbts[*pn].rating;
                        break;
                    }
                }
                break;
            case 3:
                if (*pn == -1) {
                    cout << "You don't have any person." << endl;
                    break;
                }
                cout << "num | name | age | rating" << endl;
                for (short int i = 0; i <= *pn; i++) {
                    cout << i + 1 << " | " << pbts[i].name << " | " << pbts[i].age << " | " << pbts[i].rating << endl;
                }
                cout << "Enter a number of person: " << flush;
                cin >> choose1;
                for (int i = *pn; i > choose1 - 1; i--) {
                    pbts[i - 1].name = pbts[i].name;
                    pbts[i - 1].age = pbts[i].age;
                    pbts[i - 1].rating = pbts[i].rating;
                }
                *pn = *pn - 1;
                cout << "num | name | age | rating" << endl;
                for (short int i = 0; i <= *pn; i++) {
                    cout << i + 1 << " | " << pbts[i].name << " | " << pbts[i].age << " | " << pbts[i].rating << endl;
                }
                break;
            case 4:
                cout << "num | name | age | rating" << endl;
                for (short int i = 0; i <= *pn; i++) {
                    cout << i + 1 << " | " << pbts[i].name << " | " << pbts[i].age << " | " << pbts[i].rating << endl;
                }
                break;
               






        }




    }
    

}