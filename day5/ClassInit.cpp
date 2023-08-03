#include <iostream>
using namespace std;

class SoSimple{
private:
    int num1;
    int num2;
public:
    SoSimple(int n1, int n2);
    explicit SoSimple(SoSimple& copy);
    ~SoSimple();
    void ShowSimpleData();
};

SoSimple::SoSimple(int n1, int n2) : num1(n1), num2(n2){
    cout << "obj create." << endl;
}

SoSimple::SoSimple(SoSimple& copy) : num1(copy.num1), num2(copy.num2){
    cout << "obj create." << endl;
}

SoSimple::~SoSimple(){
    cout << "obj destroy." << endl;
}

void SoSimple::ShowSimpleData(){
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl << endl;
}

int main(){
    SoSimple obj1(5, 4);
    SoSimple obj2(obj1);

    cout << "obj1: ";
    obj1.ShowSimpleData();
    cout << "obj2: ";
    obj2.ShowSimpleData();
}