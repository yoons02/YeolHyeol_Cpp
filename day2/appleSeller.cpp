#include "appleSeller.h"
using namespace std;

int main(){
    Seller seller;
    Buyer buyer;

    seller.InitSeller(5000, 500, 20);
    buyer.InitBuyer(10000, 0);

    buyer.BuyApple(seller, 3000, 5);
    buyer.BuyApple(seller, 2000, 3);
    buyer.BuyApple(seller, 1000, 3);

    seller.ShowSaleResult();
    buyer.ShowBuyResult();

    return 0;
}