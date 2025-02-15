#include <iostream>
#include "../scope.cpp"
extern int extern_var;

extern void externFunc()
{
    extern_var = 100;
    std::cout << "외부 연결을 가지는 정적 변수 extern_var: " << extern_var << std::endl;
}