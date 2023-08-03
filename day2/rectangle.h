#include <iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
public:
    bool InitMembers(int xpos, int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
    void show();
};

bool Point::InitMembers(int xpos, int ypos){
    if (xpos<0 || ypos<0){
        cout << "Initial: Wrong range point." << endl;
        x = 0;
        y = 0;
        return false;
    }

    x = xpos;
    y = ypos;

    return true;
}

int Point::GetX() const{
    return x;
}

int Point::GetY() const{
    return y;
}

bool Point::SetX(int xpos){
    if (xpos<0 || xpos>100){
        cout << "Wrong range point" << endl;
        return false;
    }

    x = xpos;
    return true;
}

bool Point::SetY(int ypos){
    if (ypos<0 || ypos>100){
        cout << "Wrong range point" << endl;
        return false;
    }

    y = ypos;
    return true;
}

void Point::show(){
    cout << "x: " << GetX() << endl;
    cout << "y: " << GetY() << endl;
 }