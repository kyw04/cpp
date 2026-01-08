/*

함수(function)란
    하나의 특별한 목적의 작업을 수행하기 위해 독립적으로 설계된 코드의 집합입니다.

*/
#include <iostream>

// 함수 선언방법 1
int Sum(int a, int b) // 반환타입 함수명(매개변수)
{ // 함수의 시작
    int result = a + b;
    return result; // 반환
} // 함수의 끝

// 함수 선언방법 2
int Min(int, int); // 반환타입 함수명(매개변수);

int main()
{
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;

    std::cout << Sum(num1, num2) << std::endl;
    std::cout << Sum(num2, num3) << std::endl;
    std::cout << Sum(num1, Sum(num2, num3)) << std::endl;
    std::cout << std::endl;
    std::cout << Min(num1, num2) << std::endl;
    std::cout << Min(num2, num3) << std::endl;
    std::cout << Min(num1, Min(num2, num3)) << std::endl;

    return 0;
}

// 함수 선언방법 2
int Min(int a, int b) // 위에서 선언한 함수 구현
{
    return a < b ? a : b;
}