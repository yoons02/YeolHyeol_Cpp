#include <iostream>
using namespace std;

class SelfRef{
private:
    int num;
public:
    SelfRef(int n);
    ~SelfRef();
    SelfRef& Adder(int n);
    SelfRef& ShowNum();
};

SelfRef::SelfRef(int n) : num(n){
    cout << "obj create" << endl;
}

SelfRef::~SelfRef(){
    cout << "obj destroy" << endl;
}

SelfRef& SelfRef::Adder(int n){
    num += n;
    return *this;
}

SelfRef& SelfRef::ShowNum(){
    cout << num << endl;
    return *this;
}

int main(){
    SelfRef obj(3);
    SelfRef& ref = obj.Adder(2);

    obj.ShowNum();
    ref.ShowNum();

    ref.Adder(1).ShowNum().Adder(3).ShowNum();

    return 0;
}