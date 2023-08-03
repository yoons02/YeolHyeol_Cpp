#include <iostream>
using namespace std;

namespace CAR_CONST{
    enum{
        MAX_SPD=200,
        FUEL_STEP = 2,
        SPD_STEP = 10,
        BRK_STEP = 10,
    };
}

class Car {
private:
    int fuel;
    int speed;
    char name[20];
public:
    Car();
    void naming();
    void showState();
    void Accel();
    void Break();
    void Charge();
};

Car::Car(){
    fuel = 0;
    speed = 0;
    strcpy(name, "None");
}

void Car::naming(){
    char name[20];

    cout << "Enter your name: ";
    cin >> name;

    strcpy(Car::name, name);
    cout << "Welcome " << name << "!" << endl << endl;
}

void Car::showState(){
    cout << "----------CarState----------" << endl;
    cout << "Gamer: " << Car::name << endl;
    cout << "FuelGauge: " << Car::fuel << endl;
    cout << "CarSpeed: " << Car::speed << endl;
    cout << "----------------------------" << endl << endl;
}

void Car::Accel(){

    cout << "----------Accel----------" << endl;
    if (Car::fuel - CAR_CONST::FUEL_STEP >= 0){
        if (Car::speed + CAR_CONST::SPD_STEP <= CAR_CONST::MAX_SPD){
            Car::speed+=CAR_CONST::SPD_STEP;
            cout << "Present speed: " << Car::speed << endl;
        }
        else {
            cout << "Car speed is Maximum." << endl;
        }
    }
    else {
        cout << "Fuel is empty." << endl;
    }

}

void Car::Break(){
    int dspeed;

    cout << "----------Break----------" << endl;
    if (Car::speed - CAR_CONST::BRK_STEP >= 0){
        Car::speed-=CAR_CONST::BRK_STEP;
        cout << "Present speed: " << Car::speed << endl;
    }
    else{
        cout << "Present speed: " << Car::speed << endl;
    }
}

void Car::Charge(){
    int charge;

    cout << "----------Charge----------" << endl;

    while(true){
        cout << "How much?: ";
        cin >> charge;

        if (Car::fuel + charge > 100){
            cout << "Present fuel and charge fuel sum is over 100." << endl;
        }
        else{
            cout << "Complete." << endl;
            Car::fuel += charge;
            break;
        }
    }
}