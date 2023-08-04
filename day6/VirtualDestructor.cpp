#include <iostream>
using namespace std;

class First{
private:
    char* strOne;
public:
    First(char* str) {
        strOne = new char[strlen(str)+1];
        strcpy(strOne, str);
    }

    virtual ~First(){
        cout << "~First()" << endl;
        delete[] strOne;
    }
};

class Second : public First{
private:
    char* strTwo;
public:
    Second(char* str1, char* str2) : First(str1) {
        strTwo = new char[strlen(str2)+1];
        strcpy(strTwo, str2);
    }

    ~Second(){
        cout << "~Second()" << endl;
        delete[] strTwo;
    }
};

class Third : public Second{
private:
    char* strThree;
public:
    Third(char* str1, char* str2, char* str3) : Second(str1, str2) {
        strThree = new char[strlen(str3)+1];
        strcpy(strThree, str3);
    }

    ~Third(){
        cout << "~Third()" << endl;
        delete[] strThree;
    }
};

int main(){
    First* ptr = new Third("simple", "complex", "soso");
    delete ptr;

    return 0;
}