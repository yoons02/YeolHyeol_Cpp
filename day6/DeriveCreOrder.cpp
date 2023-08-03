#include <iostream>
using namespace std;

class SoBase{
private: 
    int baseNum;
public:
    SoBase();
    SoBase(int n);
    void ShowBaseData() const;
    ~SoBase();
};

class SoDerived : public SoBase {
private:
    int derivedNum;
public:
    SoDerived();
    SoDerived(int n);
    SoDerived(int n1, int n2);
    void ShowDerivedData() const;
    ~SoDerived();
};

SoBase::SoBase() : baseNum(20){
    cout << "Called SoBase()" << endl;
}

SoBase::SoBase(int n) : baseNum(n) {
    cout << "Called SoBase(int n)" << endl;
}

void SoBase::ShowBaseData() const {
    cout << baseNum << endl;
}

SoBase::~SoBase(){
    cout << "Destroy SoBase" << endl;
}

SoDerived::SoDerived() : derivedNum(30) {
    cout << "Called SoDerived()" << endl;
}

SoDerived::SoDerived(int n) : derivedNum(n) {
    cout << "Called SoDerived(int n)" << endl;
}

SoDerived::SoDerived(int n1, int n2) : SoBase(n1), derivedNum(n2) {
    cout << "Called SoDerived(int n1, int n2)" << endl;
}

void SoDerived::ShowDerivedData() const{
    ShowBaseData();
    cout << derivedNum << endl;
}

SoDerived::~SoDerived(){
    cout << "Destroy SoDerived" << endl;
}

int main(){
    cout << "case1.................." << endl;
    SoDerived dr1;
    dr1.ShowDerivedData();
    
    cout << "case2.................." << endl;
    SoDerived dr2(12);
    dr2.ShowDerivedData();

    cout << "case3.................." << endl;
    SoDerived dr3(24, 45);
    dr3.ShowDerivedData();

    return 0;
}