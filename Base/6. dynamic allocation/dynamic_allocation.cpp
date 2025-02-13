/*

메모리의 동적 할당(dynamic allocation)
    데이터 영역과 스택 영역에 할당되는 메모리의 크기는 컴파일 타임(compile time)에 미리 결정됩니다.
    하지만 힙 영역의 크기는 프로그램이 실행되는 도중인 런 타임(run time)에 사용자가 직접 결정하게 됩니다.
    이렇게 런 타임에 메모리를 할당받는 것을 메모리의 동적 할당(dynamic allocation)이라고 합니다.

new 연산자
    C++의 메모리 동적 할당을 하는 연산자입니다.
    new 연산자는 자유 기억 공간(free store)이라고 불리는 메모리 공간(memory pool)에 객체를 위한 메모리를 할당받습니다.
    자료형의 크기만큼 메모리 공간을 할당 받습니다.

delete 연산자
    사용하지 않는 메모리를 다시 메모리 공간에 돌려주는 연산자입니다.

*/
#include <iostream>

int main()
{
    int* new_num = new int(); // 타입* 포인터이름 = new 타입;
    *new_num = 10;
    double* new_double = new double;
    *new_double = 3.141592;

    std::cout << "new_num의 주소: " << new_num << std::endl;
    std::cout << "new_num의 값: " << *new_num << std::endl;
    std::cout << "new_double 주소: " << new_double << std::endl;
    std::cout << "new_double 값: " << *new_double << std::endl;

    delete new_num; // delete 포인터이름;
    delete new_double;
    
    return 0;
}