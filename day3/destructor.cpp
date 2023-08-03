#include <iostream>
using namespace std;

class Person{
private:
    int age;
    char* name;
public:
    Person(char* name, int age);
    ~Person();
    void PersonInfo() const;
};

Person::Person(char* name, int age){
    this->age = age;
    int len = strlen(name) +1;
    this->name = new char[len];
    strcpy(this->name, name);
    cout << "Person obj create." << endl;
}

Person::~Person(){
    delete[] name;
    cout << "Destructor activate." << endl;
}

void Person::PersonInfo() const{
    cout << "Age: " << this->age << endl;
    cout << "Name: " << this->name << endl;
}

int main(){
    Person obj1("yoons", 22);
    Person obj2("chans", 21);

    obj1.PersonInfo();
    obj2.PersonInfo();

    return 0;
}