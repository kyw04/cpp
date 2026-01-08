/*

디폴트 인수(default argument)
    기본값이 미리 정의되어 있는 인수를 의미합니다.
    함수를 호출할 때 인수를 전달하지 않으면, 함수는 자동으로 미리 정의되어 있는 디폴트 인수값을 사용하게 됩니다.
    물론 인수를 전달하여 함수를 호출하면, 디폴트 인수값이 아닌 전달된 인수를 가지고 함수를 호출하게 됩니다.

    1. 디폴트 인수는 함수의 원형에만 지정할 수 있습니다.
    2. 디폴트 인수는 가장 오른쪽부터 시작하여 순서대로만 지정할 수 있습니다.
    3. 가운데 인수들만 별도로 디폴트 인수를 지정할 수는 없습니다.

*/
#include <iostream>

// void Display(int x, int y, char ch, int z = 4);       // 가능함.
void Display(int x, int y, char ch = 'a', int z = 4); // 가능함.
// void Display(int x, int y = 2, char ch, int z = 4);   // 오류
// void Display(int x = 1, int y = 2, char ch, int z);   // 오류

int main()
{
    // 디폴트 인수가 설정된 함수를 호출할 때에는 인수의 전달을 건너뛸 수 없습니다.
    Display(1, 2);         // 가능함 -> display(1, 2, 'a', 4)와 같음.
    Display(3, 4, 'b');    // 가능함 -> display(3, 4, 'b', 4)와 같음.
    Display(5, 6, 'c', 9); // 가능함 -> display(5, 6, 'c', 8)와 같음.
    // Display(7, 8, , 9);    // 오류 : 인수 전달은 건너뛸 수 없음.
    
    return 0;
}