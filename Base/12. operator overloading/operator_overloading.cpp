/*
연산자 오버로딩(operator overloading)
    같은 일을 처리하는 함수를 매개변수의 형식을 조금씩 달리하여,
    하나의 이름으로 작성 할 수 있게 해주는 것입니다.

연산자 함수(operator function)
    연산자를 오버로딩하기 위해서 사용하는 함수를 말합니다.
    operator오버로딩할연산자(매개변수목록)

*/
#include <iostream>

struct Position
{
    int x;
    int y;

    Position(int, int);
    Position operator-(const Position&);
};

Position::Position(int _x, int _y) : x(_x), y(_y) { }
Position Position::operator-(const Position& _other)
{
    return Position((x + _other.x)/2, (y + _other.y)/2);
}

//연산자 함수의 정의 방법
// x와 y가 private 멤버인 경우, friend 키워드를 사용하여 접근해야합니다.
Position operator-(const Position& _pos1, const Position& _pos2)
{
    return Position((_pos1.x + _pos2.x)/2, (_pos1.y + _pos2.y)/2);
}

int main()
{
    Position pos1(10, 15);
    Position pos2(2, 5);
    Position result = pos1 - pos2;

    std::cout << "pos1 - pos2 => x: " << result.x << ", y: " << result.y << std::endl;

    return 0;
}