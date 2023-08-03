#include <iostream>
using namespace std;

class SoSimple{
private: 
    int num;
public:
    SoSimple(int n);
    SoSimple(const SoSimple& copy);
    ~SoSimple();
    SoSimple& AddNum(int n);
    void ShowData();
};

SoSimple SimpleFuncObj(SoSimple ob);

SoSimple::SoSimple(int n) : num(n){
    cout << "Call SoSimple(int n)" << endl;
}

SoSimple::SoSimple(const SoSimple& copy) : num(copy.num) {
    cout << "Call SoSimple(const SoSimple& copy)" << endl;
}

SoSimple::~SoSimple(){
    cout << "Obj destroy" << endl;
}

SoSimple& SoSimple::AddNum(int n){
    num += n;
    return *this;
}

void SoSimple::ShowData(){
    cout << "Num: " << num << endl;
}

SoSimple SimpleFuncObj(SoSimple ob){
    return ob;
}

int main(){
    SoSimple obj1(7);
    SimpleFuncObj(obj1).AddNum(30).ShowData();
    obj1.ShowData();

    return 0;
}