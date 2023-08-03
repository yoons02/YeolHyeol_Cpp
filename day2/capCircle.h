#include <iostream>
using namespace std;

class Circle{
private:
    int xpos;
    int ypos;
    int radius;
public:
    void Init(int x, int y, int r);
    void Show() const;
    int GetX() const;
    int GetY() const;
    int GetRadius() const;
};

class Ring{
private:
    Circle c1;
    Circle c2;
public:
    void Init(int x1, int y1, int r1, int x2, int y2, int r2);
    void Show() const;
};

void Circle::Init(int x, int y, int r){
    xpos = x;
    ypos = y;
    radius = r;
}

int Circle::GetX() const{
    return xpos;
}

int Circle::GetY() const{
    return ypos;
}

int Circle::GetRadius() const{
    return radius;
}

void Circle::Show() const{
    cout << "Position: (" << GetX() << ", " << GetY() << "), Radius:" << GetRadius() << endl;
}

void Ring::Init(int x1, int y1, int r1, int x2, int y2, int r2){
    if (r1 < r2){
        c1.Init(x1, y1, r1);
        c2.Init(x2, y2, r2);
    }
    else {
        c2.Init(x1, y1, r1);
        c1.Init(x2, y2, r2);
    }

}

void Ring::Show() const{
    cout << "Inner Circle: (" << c1.GetX() << ", " << c1.GetY() << ") r: " << c1.GetRadius() << endl;
    cout << "Outer CIrcle: (" << c2.GetX() << ", " << c2.GetY() << ") r: " << c2.GetRadius() << endl;
}