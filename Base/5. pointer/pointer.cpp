/*

포인터(pointer)란
    변수의 주소를 저장하는 변수입니다.
    *를 이용해 포인터 변수를 선언할 수 있습니다.

주소 연산자(&)
    주소 연산자는 변수의 이름 앞에 사용하여, 해당 변수의 주소값을 반환합니다.
    '&'기호는 앰퍼샌드(ampersand)라고 읽으며, 번지 연산자라고도 불립니다.

참조 연산자(*)
    참조 연산자는 포인터의 이름이나 주소 앞에 사용하여, 포인터에 저장된 주소에 저장되어 있는 값을 반환합니다.
    '*'기호는 역참조 연산자로 에스크리터(asterisk operator)라고도 불립니다.

*/
#include <iostream>

int main()
{
    int num = 10; // 정수형 변수 선언 및 초기화
    int* ptr = &num; // 정수형 포인터 변수 선언 및 초기화
    int **ptr2 = &ptr; // 포인터 변수의 참조

    std::cout << "num의 값: " << num << std::endl;
    std::cout << "ptr의 값: " << ptr << std::endl; // 포인터 변수는 변수의 주소를 값으로 가지므로 num 변수의 주소를 출력합니다.
    std::cout << "ptr2의 값: " << ptr2 << std::endl << std::endl; // ptr 변수의 주소를 출력합니다.

    std::cout << "num의 값: num(" << num << ") *ptr(" << *ptr << ") **ptr2(" << **ptr2 << ")" << std::endl;
    std::cout << "num의 주소: &num(" << &num << ") ptr(" << ptr << ") *ptr2(" << *ptr2 << ")" << std::endl;
    std::cout << "ptr의 주소: &ptr(" << &ptr << ") &(*ptr2)(" << &(*ptr2) << ")" << std::endl;

    return 0;
}