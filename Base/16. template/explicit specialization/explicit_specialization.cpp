/*
명시적 특수화(explicit specialization)
    특정 타입에 대한 명시적 특수화를 제공하여, 해당 타입에 대해 특별한 동작을 정의할 수 있게 해줍니다.
*/
#include <iostream>

template<typename T>
void Swap(T& _a, T& _b)
{
    T temp = _a;
    _a = _b;
    _b = temp;
}

template<> void Swap<std::string>(std::string& _a, std::string& _b) // 명시적 특수화 선언
{
    std::string temp = _a;
    _a = _b;
    _b = temp;
    
    _a += _b;
    _b.clear();
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
    
    std::string str1 = "World!" , str2 = "Hello ";
    std::cout << "str1: " << str1 << " str2: " << str2 << std::endl;
    Swap(str1, str2);
    std::cout << "str1: " << str1 << " str2: " << str2 << std::endl << std::endl;
    
    return 0;
}