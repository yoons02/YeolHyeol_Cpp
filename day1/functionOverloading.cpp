#include <iostream>

void Myfunc(void){
    std::cout << "Myfunc activate" << std::endl;
}

void Myfunc(int a){
    std::cout << "Myfunc print " << a << std::endl;
}

void Myfunc(int a, int b){
    std::cout << "Myfunc print " << a << ", " << b << std::endl;
}

int main(){
    Myfunc();
    Myfunc(3);
    Myfunc(5, 7);

    return 0;
}