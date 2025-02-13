/*

참조에 의한 전달(call by reference)
    참조에 의한 전달 방법은 인수로 전달된 변수의 값을 복사하는 것이 아닌, 원본 데이터를 직접 전달하는 것입니다.
    참조 연산자를 이용하여 인수를 전달할 수 있습니다.

*/

#include <iostream>

void Add(int& a)
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