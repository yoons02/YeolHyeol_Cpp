#include <iostream>
using namespace std;

class SoSimple{
private:
    int num;
public:
    SoSimple(int n);
    SoSimple(const SoSimple& copy);
    ~SoSimple();
};

SoSimple::SoSimple(int n) : num(n) { 
    cout << "New Object: " << this << endl;
}

SoSimple::SoSimple(const SoSimple& copy){
    cout << "New Copy Object: " << this << endl;
}

SoSimple::~SoSimple(){
    cout << "Destroy Object: " << this << endl;
}

SoSimple SimjpleFuncObj(SoSimple ob){
    cout << "Parm ADR: " << &ob << endl;
    return ob;
}

int main(){
    SoSimple obj(7);
    SimjpleFuncObj(obj);
    cout << endl;

    SoSimple tempRef = SimjpleFuncObj(obj);
    cout << "Return Obj: " << &tempRef << endl;

    return 0;
}