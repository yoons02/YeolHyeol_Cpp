#include <iostream>

inline int SQURE(int x){
    return x*x;
}

int main(){
    std::cout << "Result: " << SQURE(5) << std::endl;

    return 0;
}