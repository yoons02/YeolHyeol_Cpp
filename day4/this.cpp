#include <iostream>
using namespace std;

class SoSimple{
private:
    int num;
public:
    SoSimple(int n);
    ~SoSimple();
    void ShowSimpleData();
    SoSimple* GetThisPointer();
};

SoSimple::SoSimple(int n) : num(n) {
    cout << "num: " << num << ", " << "address: " << this << endl;
}

SoSimple::~SoSimple(){
    cout << "Destroyed" << endl;
}

void SoSimple::ShowSimpleData(){
    cout << num << endl;
}

SoSimple* SoSimple::GetThisPointer(){
    return this;
}

int main(){
    SoSimple sim1(100);
    SoSimple* ptr1 = sim1.GetThisPointer();
    cout << ptr1 << ", ";
    ptr1->ShowSimpleData();

    SoSimple sim2(200);
    SoSimple* ptr2 = sim2.GetThisPointer();
    cout << ptr2 << ", ";
    ptr2->ShowSimpleData();

    return 0; 
}
