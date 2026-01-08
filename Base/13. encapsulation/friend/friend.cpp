/*
프랜드(friend)
    객체의 private 맴버에 접근해야할 경우 friend 키워드를 이용해
    "모든" 멤버에 접근할 수 있는 권한을 부여해 줍니다.
    friend 키워드는 전역 함수, 클래스, 멤버 함수의 세 가지 형태로 사용할 수 있습니다.
    friend 키워드는 함수의 원형에서만 사용해야 하며, 함수의 정의에서는 사용하지 않습니다.
    friend의 선언부는 클래스 내부 어디에든 선언할 수 있으며, 위치에 따른 차이는 없습니다.
*/
#include <iostream>

class Position
{
private:
    double x;
    double y;
public:
    Position(double, double);
    void ShowPosition();
    Position operator*(double) const;
    friend Position operator*(double, const Position&);
};

int main()
{
    Position pos(6, 8);
    Position pos1 = pos * 5; // operator* 함수 호출
    Position pos2 = 10 * pos; // friend operator* 함수 호출
    
    std::cout << "pos1 ";
    pos1.ShowPosition();

    std::cout << "pos2 ";
    pos2.ShowPosition();
    
    return 0;
}

Position::Position(double _x, double _y) : x(_x), y(_y) { }
void Position::ShowPosition() { std::cout << "x: " << this->x << ", y: " << this->y << std::endl; }
Position Position::operator*(double _mul) const { return Position(x * _mul, y * _mul); }
Position operator*(double _mul, const Position& _origin) { return _origin * _mul; }