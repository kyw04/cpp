/*

값에 의한 전달(call by value)
    함수에 전달된 변수의 값만 가져와 복사하는 방식입니다.
    함수 내 매개변수를 수정하여도 함수 밖으로 나가면 인수로 받은 변수의 값은 변하지 않습니다.

*/

#include <iostream>

void Add(int a)
{
    a += 10;
}

int main()
{
    int value = 3;
    std::cout << "함수를 호출하기 전 value 값: " << value << std::endl;
    Add(value);
    std::cout << "함수를 호출한 후 value 값: " << value << std::endl;

    return 0;
}