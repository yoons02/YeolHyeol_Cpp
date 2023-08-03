#include <iostream>
using namespace std;

class Temporary{
private:
    int num;
public:
    Temporary(int n);
    ~Temporary();
    void ShowTempInfo() const;
};

Temporary::Temporary(int n) : num(n) {
    cout << "create obj: " << num << endl;
}

Temporary::~Temporary(){
    cout << "destroy obj: " << num << endl;
}

void Temporary::ShowTempInfo() const {
    cout << "My num is " << num << endl;
}

int main(){
    Temporary(100);
    cout << "*********** after make!!" << endl;

    Temporary(200).ShowTempInfo();
    cout << "*********** after make!!" << endl;

    const Temporary& ref = Temporary(300);
    cout << "*********** end of main!!" << endl;

    return 0;
}