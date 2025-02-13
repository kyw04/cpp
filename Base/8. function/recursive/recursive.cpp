/*

재귀 호출(recursive call)
    함수 내부에서 함수가 자기 자신을 또다시 호출하는 것을 말합니다.
    이러한 재귀 호출은 자기가 자신을 계속해서 호출하므로, 끝없이 반복 되므로 중단하도록 조건이 변경될 명령문을 반드시 포함해야 합니다.
    
*/

#include <iostream>

int Factorial(int a)
{
    if (a <= 1)
        return 1;

    return a * Factorial(a - 1);
}

int main()
{
    int value = 5;
    std::cout << Factorial(value) << std::endl;

    return 0;
}