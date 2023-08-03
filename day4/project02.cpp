#include "project02.h"

int main(){
    while(true){
        int num;
        ShowMenu();
        cout << "Choose num: " ; cin >> num;

        switch(num){
            case 1:
                MakeAccount();
                break;
            case 2:
                Deposit();
                break;
            case 3:
                WithDraw();
                break;
            case 4:
                PrintAccInfo();
                break;
            case 5:
                exit(1);
            default:
                break;
        }
    }
}