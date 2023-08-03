#include <iostream>
using namespace std;

typedef struct
{
    int accountNum;
    char name[10];
    int balance;
}Account;

Account account[100];
int accNum = 0;

void showMenu(){
    cout << "--------------Menu--------------" << endl;
    cout << "1. Create account." << endl;
    cout << "2. Deposit." << endl;
    cout << "3. Withdrawal." << endl;
    cout << "4. Show entire account." << endl;
    cout << "5. Exit." << endl;
    cout << "--------------------------------" << endl;
}

void newAccount(){
    int accountNum;
    char name[10];
    int balance;

    cout << "Account Num: ";
    cin >> accountNum;
    account[accNum].accountNum = accountNum;

    cout << "Name: ";
    cin >> name;
    strcpy(account[accNum].name, name);

    cout << "Balance: ";
    cin >> balance;
    account[accNum].balance = balance;

    cout << "Welcome " << account[accNum].name << "!" << endl;
    accNum += 1;
}

void deposit(){
    int j;
    int verification = 0;
    int deposit;
    char name[10];

    cout << "Enter your name: ";
    cin >> name;

    for (j = 0; j < accNum; j++){
        cout << account[accNum].name << endl;
        if (!strcmp(account[j].name, name)){
            cout << "Complete member verification." << endl;
            verification = 1;

            cout << "Deposit amount: ";
            cin >> deposit;

            if (deposit > 0){
                cout << "Deposit complete." << endl;
                account[j].balance += deposit;
            }
            else{
                cout << "Deposit amout must be over 0." << endl;
            }
            break;
        }
        else{
            cout << "No member information about " << name <<endl;
            break;
        }
    }
}


void withDrawal(){
    int j;
    int verification = 0;
    int withDrawal;
    char name[10];

    cout << "Enter your name: ";
    cin >> name;

    for (j = 0; j < accNum; j++){
        if (!strcmp(account[j].name, name)){
            cout << "Complete member verification." << endl;
            verification = 1;

            cout << "Withdrawal amount: ";
            cin >> withDrawal;

            if (withDrawal > 0){
                if (account[j].balance - withDrawal > 0){
                    cout << "Withdrawal complete." << endl;
                    account[j].balance -= withDrawal;
                }
                else{
                    cout << "Lack of balance." << endl;
                }
            }
            else{
                cout << "Withdrawal amount must be over 0." << endl;
            }
            break;
        }
        else{
            cout << "No member information about " << name <<endl;
        }
        break;
    }
}

void inquiry(){
    for (int i = 0; i < accNum; i++){
        cout << "Client " << i << endl;
        cout << "Name: " << account[i].name << endl;
        cout << "Account: " << account[i].accountNum << endl;
        cout << "Balance: " << account[i].balance << endl << endl;
    }
}

int main(){
    int num;

    while(true){
        showMenu();
        cout << "Enter the Number: " << endl;
        cin >> num;

        switch (num){
            case 1:
                newAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withDrawal();
                break;
            case 4:
                inquiry();
                break;
            case 5:
                exit(1);
                break;
            default:
                break;
        }
    }
}