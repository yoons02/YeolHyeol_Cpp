#include <iostream>
using namespace std;
// overiding 할 때는 parameter의 종류와 개수는 물론 자료형, const 선언도 모두 같아야 한다..!!

class Employee{
private:
    char* name;
public:
    Employee(char* eName){
        name = new char[strlen(eName)+1];
        strcpy(name, eName);
    }

    virtual ~Employee(){ // Employee는 추상 클래스이므로 가상 소멸자 정의
        delete[] name;
    }

    void ShowYourName() const {
        cout << "name: " << name << endl;
    }

    // virtual int GetPay() const { return 0; }
    virtual int GetPay() const = 0; // 순수 가상함수 

    virtual int GetRisk() const = 0;

    // virtual void ShowSalaryInfo() const { }
    virtual void ShowSalaryInfo() const = 0;

    // 클래스가 순수가상함수를 가졌다는 것은 클래스가 완전하지 않다는 의미이고, 완전하지 않은 클래스 객체는 생성되지 않는다 (컴파일에러)
};

class PermanentWorker : public Employee {
private:
    int salary; // 월급
public:
    PermanentWorker(char* name, int money) : Employee(name), salary(money) {
        
    }

    int GetPay() const {
        return salary;
    }

    void ShowSalaryInfo() const{
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }

    virtual int GetRisk() const {
        return 0;
    };
};

class SalesWorker : public PermanentWorker {
private:
    int salesResult;
    double bonusRatio;
public:
    SalesWorker(char* name, int money, double ratio) 
    : PermanentWorker(name, money), bonusRatio(ratio), salesResult(0) {

    }

    void AddSalesResult(int value){
        salesResult += value;
    }

    int GetPay() const {
        return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
    }

    void ShowSalaryInfo() const{
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }

    virtual int GetRisk() const {
        return 0;
    }
};

namespace RISK_LEVEL{
    enum{
        RISK_A = 30,
        RISK_B = 20,
        RISK_C = 10
    };
}

class ForeignSalesWorker : public SalesWorker{
private:
    const int riskLevel;
public:
    ForeignSalesWorker(char* name, int money, double ratio, int risk)
    : SalesWorker(name, money, ratio), riskLevel(risk)
    { };

    int GetRisk() const {
        return SalesWorker::GetPay() * ((double)riskLevel)/100.0;
    }

    void ShowSalaryInfo() const{
        ShowYourName();
        cout << "salary: " << SalesWorker::GetPay() << endl;
        cout << "risk pay: " << GetRisk() << endl;
        cout << "sum: " << SalesWorker::GetPay() + GetRisk() << endl << endl;
    }
};

class TemporaryWorker : public Employee{
private:
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(char* name, int pay) : Employee(name), payPerHour(pay), workTime(0) {

    }

    void AddWorkTime(int time){
        workTime += time;
    }

    int GetPay() const {
        return workTime*payPerHour;
    }

    void ShowSalaryInfo() const{
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }

    virtual int GetRisk() const {
        return 0;
    }
};

class EmployeeHandler{
private:
    Employee* elist[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0){

    }

    void AddEmployee(Employee* emp){
        elist[empNum++] = emp;
    }

    void ShowAllSalaryInfo() const{
        for (int i = 0; i < empNum; i++){
            elist[i]->ShowSalaryInfo();
        }
    }

    void ShowTotalSalary() const{
        int sum = 0;
        for (int i = 0; i < empNum; i++){
            sum += elist[i]->GetPay();
            sum += elist[i]->GetRisk();
        }
        cout << "salary sum: " << sum << endl;
    }

    ~EmployeeHandler(){
        for (int i = 0; i < empNum; i++){
            delete elist[i];
        }
    }
};

int main(){
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM", 1500));
    handler.AddEmployee(new PermanentWorker("LEE", 1000));

    TemporaryWorker* alba = new TemporaryWorker("JUNG", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    SalesWorker* seller = new SalesWorker("HONG", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    ForeignSalesWorker* fsw1 = new ForeignSalesWorker("PARK", 1000, 0.1, RISK_LEVEL::RISK_A);
    fsw1->AddSalesResult(7000);
    handler.AddEmployee(fsw1);

    ForeignSalesWorker* fsw2 = new ForeignSalesWorker("YOON", 1000, 0.1, RISK_LEVEL::RISK_B);
    fsw2->AddSalesResult(7000);
    handler.AddEmployee(fsw2);

    ForeignSalesWorker* fsw3 = new ForeignSalesWorker("CHOI", 1000, 0.1, RISK_LEVEL::RISK_C);
    fsw3->AddSalesResult(7000);
    handler.AddEmployee(fsw3);

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();

    return 0;
}