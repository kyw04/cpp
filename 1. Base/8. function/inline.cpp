/*
인라인 함수(inline function)
    C++에서 함수의 호출은 꽤 복잡한 과정을 거치므로, 약간의 시간이 걸리게 됩니다.
    함수의 실행 시간이 매우 짧다면, 함수 호출에 걸리는 시간도 부담이 될 수 있습니다.
    인라인 함수는 호출될 때 일반적인 함수의 호출 과정을 거치지 않고, 함수의 모든 코드를 
    호출된 자리에 바로 삽입하는 방식의 함수이므로 함수 호출에 걸리는 시간을 절약할 수 있습니다.
    하지만 함수 호출 과정으로 생기는 여러 이점을 포기하게 됩니다.

    inline 함수의원형
    inline 함수의정의

*/

#include <iostream>

inline int Sub(int x, int y) { return x - y; }

int main()
{
    int result;
    result = Sub(10, 20);

    std::cout << result;

    return 0;
}
/*
실제 실행 되는 코드
int main()
{
    int result;
    {
        int x = 10, y = 20;
        result = x - y;
    }

    std::cout << result;

    return 0;
}

*/
