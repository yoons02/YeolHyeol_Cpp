#include <iostream>
using namespace std;

class Person{
private:
    int age;
    char* name;
public:
    Person(int Iage, char* Iname);
    ~Person();
    char* GetName();
    void WhatYourName() const;
    void HowOldAreYou() const;
};

class UnivStudent : public Person {
private:
    char* major;
public: 
    UnivStudent(int Iage, char* Iname, char* Imajor);
    ~UnivStudent();
    void WhoAreYou() const;
};

Person::Person(int Iage, char* Iname) : age(Iage){
    name = new char[strlen(Iname)+1];
    strcpy(name, Iname);
    cout << "Person: " << name << " create!" << endl;
}

Person::~Person(){
    cout << "Destroy person " << name << endl; 
    delete[] name;
}

char* Person::GetName(){
    return name;
}

void Person::WhatYourName() const{
    cout << "My name is " << name << endl;
}

void Person::HowOldAreYou() const{
    cout << "I'm " << age << " years old." << endl;
}

UnivStudent::UnivStudent(int Iage, char* Iname, char* Imajor) : Person(Iage, Iname){
    major = new char[strlen(Imajor)+1];
    strcpy(major, Imajor);
    cout << "Student: " << GetName() << " create!" << endl;
}

UnivStudent::~UnivStudent(){
    cout << "Destroy student " << GetName() << endl; 
    delete[] major;
}

void UnivStudent::WhoAreYou() const {
    WhatYourName();
    HowOldAreYou();
    cout << "My major is " << major << endl;
}

int main(){
    UnivStudent std1(22, "yoons", "cse");
    std1.WhoAreYou();

    UnivStudent std2(21, "chans", "politic");
    std2.WhoAreYou();
    
    return 0;
}