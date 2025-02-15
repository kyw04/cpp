/*
네임스페이스(namespace)
    프로그램이 복잡해지고 여러 라이브러리가 포함될수록 내부 식별자 간에 충돌할 가능성도 그만큼 커집니다.
    이러한 이름 충돌 문제를 C++에서는 네임스페이스(namespace)를 통해 해결하고 있습니다.
*/

#include <iostream>
#include "namespace.hpp"

using namespace second; // 명시한 네임스페이스의 모든 이름을 사용할 수 있게 해줍니다.
using first::first_ch; // 단 하나의 이름만을 범위 지정 연산자를 사용하지 않고도 사용할 수 있게 해줍니다.

int main()
{
    first::count = 10;
    std::cout << "first count: " << first::count << std::endl;
    std::cout << "second count: " << count << std::endl;

    std::cout << "first pi: " << first::pi() << std::endl;
    std::cout << "second pi: " << pi << std::endl;
    
    first_ch = 'A'; // "first::" 생략 가능
    second_ch = 'a'; 
    std::cout << "first ch: " << first_ch << std::endl;
    std::cout << "second ch: " << second_ch << std::endl;

    return 0;
}