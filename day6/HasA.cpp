#include <iostream>
using namespace std;

class Gun{
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum) {

    }

    int GetBullets(){
        return bullet;
    }

    void Shot(){
        if (bullet > 0){
            cout << "BBANG!!" << endl;
            bullet--;
        }
        else {
            cout << "PIK..(Shit..NO BULLET)" << endl;
        }
    }
};

class Police{
private:
    int handcuffs;
    Gun* pistol;
public:
    Police(int bnum, int bcuff) : handcuffs(bcuff) {
        if (bnum > 0){
            pistol = new Gun(bnum);
        }
        else {
            pistol = NULL;
        }
    }

    void PutHandcuff(){
        cout << "SNAP!!" << endl;
        handcuffs--;
    }

    void Shot(){
        if (pistol == NULL){
            cout << "Oh my.. (Have not Pistol)" << endl;
        }
        else {
            pistol->Shot();
        }
    }

    void ShowState(){
        cout << "Handcuffs: " << handcuffs << endl;
        if (pistol == NULL){
            cout << "Bullets: No Pistol." << endl;
        }
        else{
            cout << "Bullets: " << pistol->GetBullets() << endl;
        }
    }

    ~Police(){
        if (pistol != NULL){
            delete pistol;
        }
    }
};

int main(){
    Police pman(0, 5);
    pman.PutHandcuff();
    pman.Shot();
    pman.Shot();
    pman.ShowState();

    return 0;
}