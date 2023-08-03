#include <iostream>
using namespace std;

class AAA{
private:
    int num;
    AAA(int n);
public:
    AAA();
    AAA& CreateObj(int n);
    void ShowNum();
};

AAA::AAA(int n) : num(n){
    cout << "Make obj." << endl;
}

AAA::AAA() : num(0){
    cout << "Make obj." << endl;
}

AAA& AAA::CreateObj(int n){
    AAA* ptr = new AAA(n);
    return *ptr;
}

void AAA::ShowNum(){
    cout << num << endl;
}

int main(){
    AAA base;
    base.ShowNum();

    AAA& obj1 = base.CreateObj(3);
    obj1.ShowNum();

    AAA& obj2 = base.CreateObj(6);
    obj2.ShowNum();

    delete& obj1;
    delete& obj2;

    return 0;
}