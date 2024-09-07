/*#include <iostream>
 *#include <string>
 *using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n) {
        name = n;
    }

    void printName() {
        cout << name << endl;
    }
};

int main()
{
    Person firstPerson ("bob");
    firstPerson.printName();
    return 0;
}*/

/*#include <iostream>
 *#include <string>
 *using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) {
        name = n;
        age = a;
    }

    void printPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    Person firstPerson ("bob", 25);
    firstPerson.printPerson();
    return 0;
}*/

/*#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a){
        name = n;
        age = a;
    }

    void printPerson() const{
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main(){

    vector<Person> persons;
    string name;
    int age;

    for (int i = 0; i < 3; ++i){
        cout << "Enter name for person " << i + 1 << ": ";
        cin >> name;

        cout << "Enter age for " << name << ": ";
        cin >> age;

        persons.push_back(Person(name, age));
    }

    cout << "\nList of Persons:" << endl;
    for (const Person& p : persons){
        p.printPerson();
    }

    return 0;
}*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public :
    string firstName;
    string lastName;
    int age;

    Person(string fn, string ln, int a) : firstName(fn), lastName(ln), age(a){

    }

    void printPerson() const {
        cout << "Name: " << firstName << lastName << ", Age: " << age << endl;
    }
};

int main()
{
    vector<Person> persons;
    string firstName, lastName;
    int age;

    for (int i = 0; i < 3; ++i){
        cout << "Enter first name for person " << i + 1 << ": ";
        cin >> firstName;

        cout << "Enter last name for " << firstName << ": ";
        cin >> lastName;

        cout << "Enter age for " << firstName << " " << lastName << ": ";
        cin >> age;

        persons.push_back(Person(firstName, lastName, age));
    }

    cout << "\nList of Persons:" << endl;
    for (const Person& p : persons){
        p.printPerson();
    }
}
