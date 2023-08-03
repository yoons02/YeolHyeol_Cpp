#include <iostream>
using namespace std;

// IS-A relation

class Computer {
private:
    char* owner;
public:
    Computer(char* name){
        owner = new char[strlen(name)+1];
        strcpy(owner, name);
    }

    ~Computer(){
        delete[] owner;
    }

    void Calculate(){
        cout << "Processing" << endl;
    }
};

class Laptop : public Computer{
private:
    int battery;
public:
    Laptop(char* name, int btr) : Computer(name), battery(btr) {

    }

    int GetBattery(){
        return battery;
    }

    void Charging(){
        battery += 5;
    }

    void UseBattery(){
        battery -= 1;
    }

    void MovingCal(){
        if (GetBattery() <= 5){
            cout << "Please Charging." << endl;
            return;
        }
        cout << "Moving and ";
        Calculate();
        UseBattery();
    }
};

class Tablet : public Laptop {
private:
    char* penName;
public:
    Tablet(char* name, int tabletBattery, char* pName) : Laptop(name, tabletBattery){
        penName = new char[strlen(pName)+1];
        strcpy(penName, pName);
    }

    ~Tablet(){
        delete[] penName;
    }

    void write(char* pName){
        if (GetBattery() <= 5){
            cout << "Please Charging." << endl;
            return;
        }
        if (strcmp(penName, pName)!=0){
            cout << "This pen is not registered." << endl;
            return;
        }
        cout << "Write and ";
        Calculate();
        UseBattery();
    }
};

int main(){
    cout << "Laptop................." << endl;
    Laptop lp("yoons", 2);
    lp.MovingCal();
    cout << endl;

    cout << "Tablet................." << endl;
    Tablet tb("chans",10, "abc");
    tb.write("ab");

    return 0;
}