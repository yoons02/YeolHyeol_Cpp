#include <iostream>
using namespace std;

class Girl;

class Boy{
private:
    int height;
    friend class Girl;
public:
    Boy(int len);
    void ShowFriendInfo(Girl& frn);
};


class Girl{
private:
    char phNum[20];
public:
    Girl(char* num);
    void ShowFriendInfo(Boy& frn);
    friend class Boy;
};

Boy::Boy(int len) : height(len) {

}

void Boy::ShowFriendInfo(Girl& frn){
    cout << "Phone num: " << frn.phNum << endl;
}

Girl::Girl(char* num){
    strcpy(phNum, num);
}

void Girl::ShowFriendInfo(Boy& frn){
    cout << "Height: " << frn.height << endl;
}

int main(){
    Boy boy(183);
    Girl girl("010-0000-0000");
    boy.ShowFriendInfo(girl);
    girl.ShowFriendInfo(boy);

    return 0;
}