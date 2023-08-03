#include <iostream>
using namespace std;

class Seller{
private:
    int money;
    int numOfApple;
    int benefit;
public:
    int applePrice;
    void InitSeller(int money, int applePrice, int numOfApple);
    bool SaleApple(int numOfApple, int Bmoney);
    void ShowSaleResult() const;
};

class Buyer{
private:
    int money;
    int numOfApple;
public:
    void InitBuyer(int money, int numOfApple);
    void BuyApple(Seller& seller, int numOfApple, int money);
    void ShowBuyResult() const;
};

void Seller::InitSeller(int money, int applePrice, int numOfApple){
    this->money = money;
    this->applePrice = applePrice;
    this->numOfApple = numOfApple;
    this->benefit = 0;
}

bool Seller::SaleApple(int numOfApple, int Bmoney){
    int remain;

    if (Bmoney-numOfApple*Seller::applePrice < 0){
        cout << "Lack of Balance." << endl;
        return false;
    }
    else{
        remain = Bmoney - numOfApple*Seller::applePrice;
        Seller::numOfApple -= numOfApple;
        Seller::money += numOfApple*Seller::applePrice;
        Seller::benefit += numOfApple*Seller::applePrice;
        cout << numOfApple << " apples. Remain money is " << remain << "." << endl;
        return true;
    }
}

void Seller::ShowSaleResult() const{
    cout << "----------Seller----------" << endl;
    cout << "Money: " << Seller::money << endl;
    cout << "Num of apples: " << Seller::numOfApple << endl;
    cout << "Benefit: " << Seller::benefit << endl;
    cout << "Apple price: " << Seller::applePrice << endl;
    cout << "--------------------------" << endl;
}

void Buyer::InitBuyer(int money, int numOfApple){
    this->money = money;
    this->numOfApple = numOfApple;
}

void Buyer::BuyApple(Seller& seller, int money, int numOfApple){
    if (seller.SaleApple(numOfApple, money)){
        Buyer::money -= seller.applePrice*numOfApple;
        Buyer::numOfApple += numOfApple;
    }
}


void Buyer::ShowBuyResult() const{
    cout << "----------Buyer----------" << endl;
    cout << "Money: " << Buyer::money << endl;
    cout << "Num of apples: " << Buyer::numOfApple << endl;
    cout << "-------------------------" << endl;
}