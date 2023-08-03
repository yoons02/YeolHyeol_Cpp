#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define MAX_FUEL 100
#define FUEL_STEP 2

typedef struct 
{
    char gamerID[ID_LEN];
    int fuelGauge = 0;
    int carSpeed = 0;
} Car;

void showCarState(const Car& car){
    cout << "----------CarState----------" << endl;
    cout << "Gamer: " << car.gamerID << endl;
    cout << "FuelGauge: " << car.fuelGauge << endl;
    cout << "CarSpeed: " << car.carSpeed << endl;
    cout << "----------------------------" << endl << endl;
}

void Accel(Car& car){
    int speed;

    cout << "----------Accel----------" << endl;

    while(true){
        cout << "Enter Speed: ";
        cin >> speed;

        if (speed > MAX_SPD){
            cout << "ERROR: Over Max speed." << endl;
        }
        else if (car.fuelGauge - FUEL_STEP <= 0){
            cout << "Fuel is not enough." << endl;
        }
        else {
            car.carSpeed = speed;
            car.fuelGauge -= FUEL_STEP;
            cout << "Complete." << endl;
            break;
        }
    }
}

void Break(Car& car){
    int dspeed;

    cout << "----------Break----------" << endl;
    cout << "Complete." << endl;
    car.carSpeed = 0;
}

void Charge(Car& car){
    int charge;

    cout << "----------Charge----------" << endl;

    while(true){
        cout << "How much?: ";
        cin >> charge;

        if (car.fuelGauge + charge > 100){
            cout << "Present fuel and charge fuel sum is over 100." << endl;
        }
        else{
            cout << "Complete." << endl;
            car.fuelGauge += charge;
            break;
        }
    }
}

int main(){
    Car car;
    char name[20];
    int num;

    cout << "Enter your name: ";
    cin >> name;

    strcpy(car.gamerID, name);
    cout << "Welcome " << car.gamerID << "!" << endl << endl;

    while(true){
        cout << "----------Option----------" << endl;
        cout << "1. Show my car state." << endl;
        cout << "2. Accel" << endl;
        cout << "3. Breack" << endl;
        cout << "4. Charge" << endl;
        cout << "5. Exit" << endl;
        cout << "--------------------------" << endl;
        cout << "Choose number: ";
        cin >> num;

        switch(num){
            case 1:
                showCarState(car);
                break;
            case 2: 
                Accel(car);
                break;
            case 3:
                Break(car);
                break;
            case 4:
                Charge(car);
                break;
            case 5:
                exit(1);
            default:
                break;
        }
}

    return 0;
}