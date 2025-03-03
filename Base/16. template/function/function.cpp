/*
템플릿(template)
    매개변수의 타입에 따라 함수나 클래스를 생성하는 메커니즘을 의미합니다.
    타입마다 별도의 함수나 클래스를 만들지 않고, 여러 타입에서 동작할 수 있는 단 하나의 함수나 클래스를 작성하는 것이 가능합니다.
*/
#include <iostream>

template<typename T> // 템플릿 선언
void Swap(T& _a, T& _b)
{
    T temp = _a;
    _a = _b;
    _b = temp;
}

int main()
{
    int num1 = 10, num2 = 31;
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
    Swap(num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl << std::endl;
    
    float f1 = 3.1f, f2 = 8.15f;
    std::cout << "f1: " << f1 << " f2: " << f2 << std::endl;
    Swap(f1, f2);
    std::cout << "f1: " << f1 << " f2: " << f2 << std::endl << std::endl;

    char ch1 = 'A', ch2 = 'F';
    std::cout << "ch1: " << ch1 << " ch2: " << ch2 << std::endl;
    Swap(ch1, ch2);
    std::cout << "ch1: " << ch1 << " ch2: " << ch2 << std::endl << std::endl;
    
    std::string str1 = "World!" , str2 = "Hello";
    std::cout << "str1: " << str1 << " str2: " << str2 << std::endl;
    Swap(str1, str2);
    std::cout << "str1: " << str1 << " str2: " << str2 << std::endl << std::endl;
    
    return 0;
}