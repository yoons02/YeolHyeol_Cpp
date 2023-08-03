#include <iostream>
using namespace std;

void ShowMenu();
void MakeAccount();
void Deposit();
void WithDraw();
void PrintAccInfo();

class Account{
private:
    int accID;
    int balance;
    char* accName;
public:
    Account(int ID, int money, char* name);
    ~Account();
    int GetID();
    void DepositMoney(int money);
    void WithDrawMoney(int money);
    void PrintInfo();
};

int accNum = 0;
Account* accArr[10];

Account::Account(int ID, int money, char* name) : accID(ID), balance(money){
    int LenName = strlen(name);
    accName = new char[LenName];
    strcpy(accName, name);
    cout << "Welcome " << accName << "!" << endl;
}

Account::~Account(){
    cout << "See later " << accName << endl; 
    delete[] accName;
}

int Account::GetID(){
    return accID;
}

void Account::DepositMoney(int money){
    balance += money;
    cout << "Deposit Complete." << endl;
}

void Account::WithDrawMoney(int money){
    if (balance - money >= 0){
        balance -= money;
        cout << "WithDraw Complete." << endl;
    }
    else{
        cout << "Lack of balance." << endl;
    }
}

void Account::PrintInfo(){
    cout << "------------" << accName << "------------" << endl;
    cout << "Account ID: " << accID << endl;
    cout << "Balance: " << balance << endl;
}

void ShowMenu(){
    cout << "-------------Menu-------------" << endl;
    cout << "1. MakeAccount." << endl;
    cout << "2. Deposit." << endl;
    cout << "3. WithDraw." << endl;
    cout << "4. PrintAccInfo." << endl;
    cout << "5. Exit." << endl;
}

void MakeAccount(){
    int ID;
    int money;
    char name[10];
    cout << "Account ID: "; cin >> ID;
    cout << "Money: "; cin >> money;
    cout << "Account Name: "; cin >> name;

    accArr[accNum++] = new Account(ID, money, name);
}

void Deposit(){
    int depositID;
    int depositMoney;
    bool found = false;

    cout << "Deposit Account ID: "; cin >> depositID;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetID() == depositID){
            found = true;
            cout << "Deposit Money: "; cin >> depositMoney;
            accArr[i]->DepositMoney(depositMoney);
        }
    }

    if (!found){
        cout << "No member." << endl;
    }
}

void WithDraw(){
    int withDrawID;
    int withDrawMoney;
    bool found = false;

    cout << "WithDraw Account ID: "; cin >> withDrawID;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetID() == withDrawID){
            found = true;
            cout << "WithDraw Money: "; cin >> withDrawMoney;
            accArr[i]->WithDrawMoney(withDrawMoney);
        }
    }

    if (!found){
        cout << "No member." << endl;
    }
}

void PrintAccInfo(){
    int accID;
    bool found = false;

    cout << "Account ID: "; cin >> accID;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetID() == accID){
            found = true;
            accArr[i]->PrintInfo();
        }
    }

    if (!found){
        cout << "No member." << endl;
    }
}