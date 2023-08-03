#include <iostream>

void swap(char* a, char* b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp; 
}

void swap(int* num1, int* num2){
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void swap(double* dnum1, double* dnum2){
    double temp;
    temp = *dnum1;
    *dnum1 = *dnum2;
    *dnum2 = temp;
}

int main(){
    char a = 'A';
    char b = 'B';
    std::cout << "Before: " << a << ", " << b << std::endl;
    swap(&a, &b);
    std::cout << "After: " << a << ", " << b << std::endl;

    int num1 = 10;
    int num2 = 20;
    std::cout << "Before: " << num1 << ", " << num2 << std::endl;
    swap(&num1, &num2);
    std::cout << "After: " << num1 << ", " << num2 << std::endl;

    double dnum1 = 12.34;
    double dnum2 = 43.12;
    std::cout << "Before: " << dnum1 << ", " << dnum2 << std::endl;
    swap(&dnum1, &dnum2);
    std::cout << "After: " << dnum1 << ", " << dnum2 << std::endl;
}