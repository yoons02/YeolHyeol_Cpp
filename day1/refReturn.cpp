#include <iostream>
using namespace std;

int&  RefRetFuncOne(int& ref){
    ref++;
    return ref;
    // num1의 주소에서 +1을 함
}

int main(){
    int num1 = 1;
    int& num2 = RefRetFuncOne(num1);
    // num1과 num2는 주소를 공유한다..

    cout << num1 << endl;
    cout << num2 << endl;

    num1++;
    num2++;
    // num2는 num1의 주소값을 가져와서 연산 즉, num1과 num2는 같은 숫자
    cout << num1 << endl;
    cout << num2 << endl;

    return 0;
}