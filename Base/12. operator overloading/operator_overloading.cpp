/*
연산자 오버로딩(operator overloading)
    같은 일을 처리하는 함수를 매개변수의 형식을 조금씩 달리하여,
    하나의 이름으로 작성 할 수 있게 해주는 것입니다.

    제약사항
        1. 전혀 새로운 연산자를 정의할 수 없습니다.
        2. 오버로딩 된 연산자의 피연산자 중 하나는 사용자 정의 타입이어야 합니다.
        3. 기본 타입을 다루는 경우에 적용되는 피연산자의 수, 우선순위 및 구룹화를 준수해야 합니다.
        4. 오버로딩된 연산자는 디폴트 인수를 사용할 수 없습니다.

    오버로딩할 수 없는 연산자
        :: 범위 지정 연산자
        . 맴버 연산자
        .*	멤버 포인터 연산자
        ? :	삼항 조건 연산자
        sizeof	크기 연산자
        typeid	타입 인식
        const_cast	상수 타입 변환
        dynamic_cast	동적 타입 변환
        reinterpret_cast	재해석 타입 변환
        static_cast	정적 타입 변환
    
    멤버 함수로만 오버로딩할 수 있는 연산자
        =	대입 연산자
        ()	함수 호출 
        []	배열 인덱스
        ->	멤버 접근 연산자
    
연산자 함수(operator function)
    연산자를 오버로딩하기 위해서 사용하는 함수를 말합니다.
    operator오버로딩할연산자(매개변수목록)

*/
#include <iostream>

struct Position
{
    double x;
    double y;

    Position(double, double);
    Position operator-(const Position&);
};

Position::Position(double _x, double _y) : x(_x), y(_y) { }
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
    Position pos1(10.5, 15);
    Position pos2(22.25, 5);
    Position result = pos1 - pos2;

    std::cout << "두 지점의 중간 지점의 좌표는 x: " << result.x << ", y: " << result.y << "입니다." << std::endl;

    return 0;
}