#include <iostream>
using namespace std;

char* MakeM(int len){
    char* str = new char[len];
    return str;
}

int main(){
    char* str = MakeM(20);
    strcpy(str, "hello I'm yoons!!");
    cout << str << endl;

    delete[] str;

    return 0;
}