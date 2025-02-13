/*

공용체(union)
    공용체(union)는 union 키워드를 사용하여 선언하며, 모든 면에서 구조체와 같습니다.
    하지만 모든 멤버 변수가 하나의 메모리 공간을 공유한다는 점만이 다릅니다.
    모든 멤버 변수가 같은 메모리를 공유하기 때문에 공용체는 한 번에 하나의 멤버 변수밖에 사용할 수 없습니다.
    크기가 가장 큰 멤버 변수의 크기로 메모리를 할당받습니다.

*/
#include <iostream>

union UnionData
{
    int num;
    float fl;
    char ch;
};

int main()
{
    UnionData data;
    data.num = 65;
    
    // 사용하는 변수에 따라 해석이 달라집니다.
    std::cout << data.num << std::endl;
    std::cout << data.fl << std::endl;
    std::cout << data.ch << std::endl;

    return 0;
}