#include "carClass.h"

int main(){
    Car car;
    int num;

    while(true){
        cout << "----------Option----------" << endl;
        cout << "1. Naming." << endl;
        cout << "2. Show my car state." << endl;
        cout << "3. Accel" << endl;
        cout << "4. Break" << endl;
        cout << "5. Charge" << endl;
        cout << "6. Exit" << endl;
        cout << "--------------------------" << endl;
        cout << "Choose number: ";
        cin >> num;

        switch(num){
            case 1:
                car.naming();
                break;
            case 2:
                car.showState();
                break;
            case 3: 
                car.Accel();
                break;
            case 4:
                car.Break();
                break;
            case 5:
                car.Charge();
                break;
            case 6:
                exit(1);
            default:
                break;
        }
    }

    return 0;
}