/*
함수 오버로딩(function overloading)
    같은 이름의 함수를 중복으로 정의하는 방법입니다.
    같은 일을 처리하는 함수를 매개변수의 형식을 조금씩 달리하여, 하나의 이름으로 작성할 수 있게 해주는 것입니다.

*/

#include <iostream>

void Display(const char* str, int n);             // 문자열 str을 n번 출력함.
void Display(const char* str1, const char* str2); // 문자열 str1과 str2를 연달아 출력함.
void Display(int x, int y);                       // x * y를 출력함.
void Display(double x, double y);                 // x / y를 출력함.

int main()
{
    Display("C++", 3);              // 1번 Display() 함수 호출 -> "C++C++C++"
    std::cout << std::endl;
    Display("C++", " Programming"); // 2번 Display() 함수 호출 -> "C++ Programming"
    std::cout << std::endl;
    Display(3, 4);                  // 3번 Display() 함수 호출 -> 12
    std::cout << std::endl;
    Display(4.2, 2.1);              // 4번 Display() 함수 호출 -> 2
    std::cout << std::endl;
    // Display(4.2, 3);                // 3번과 4번 모두 호출 가능 -> 컴파일 오류가 발생함.

    return 0;
}

void Display(const char* str, int n)
{
    while(n--) { std::cout << str; }
}
void Display(const char* str1, const char* str2)
{
    std::cout << str1 << str2;
}
void Display(int x, int y)
{
    std::cout << x * y;
}
void Display(double x, double y)
{
    std::cout << x / y;
}