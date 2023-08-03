#include <iostream>
using namespace std;

class Person{
private:
    int pAge;
    char* pName;
public:
    Person(int age, char* name);
    Person(Person& obj);
    ~Person();
    void ShowPersonInfo() const;
};

Person::Person(int age, char* name) : pAge(age) {
    int LenName = strlen(name) + 1;
    pName = new char[LenName];
    strcpy(pName, name);
    cout << "Person obj create." << endl;
}

Person::Person(Person& obj) : pAge(obj.pAge) {
    int LenName = strlen(obj.pName) + 1;
    pName = new char[LenName];
    strcpy(pName, obj.pName);
    cout << "Person obj create." << endl;
}

Person::~Person(){
    delete[] pName;
    cout << "Person obj destroy." << endl;
}
 
void Person::ShowPersonInfo() const{
    cout << "Name: " << pName << endl;
    cout << "Age: " << pAge << endl;
}

int main(){
    Person obj1(22, "yoons");
    Person obj2 = obj1;

    obj1.ShowPersonInfo();
    obj2.ShowPersonInfo();

    return 0;
}