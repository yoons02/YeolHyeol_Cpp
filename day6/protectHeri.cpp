#include <iostream>
using namespace std;

class Base{
private:
    int num1;
protected:
    int num2;
public:
    int num3;
};

class Derived : protected Base { // public 변수가 protected로 바뀜
    // num2, num3 접근 가능
};

int main(){
    Derived drv;
    // cout << drv.num3 << endl; // 다 접근 불가

    return 0;
}