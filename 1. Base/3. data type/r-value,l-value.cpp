/*
r-value
    r-value는 상수(읽기만 가능한 값)를 뜻합니다.
    이러한 특성 때문에 read only value 또는 right value(우측 값)라고 불립니다.
    아래 코드에서 확인할 수 있는 r-value는 5, 10, 1, 0이 있습니다.

l-value
    l-value는 변수(읽기와 쓰기 모두 가능한 값)를 뜻합니다.
    l-value는 r-value와 달리 왼쪽에도 위치할 수 있기에 left value(좌측 값)라고 불립니다.
    아래 코드에서 확인할 수 있는 r-value는 first, second가 있습니다.
*/

#include <iostream>

int main()
{
    int first = 5;
    int second = 10;
    first = second;
    second = 1;

    // 10 = 5; // 오류

    return 0;
}