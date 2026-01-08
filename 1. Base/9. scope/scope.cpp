/*
유효 범위(scope)
    하나의 변환 단위(translation unit) 내에서 해당 변수가 사용될 수 있는 범위를 나타냅니다.
    기본적으로 함수 내에서 선언된 변수는 함수 내에서만 사용할 수 있습니다.
    
연결(linkage)
    변수를 사용할 수 있는 파일의 접근 가능 여부를 나타냅니다.
    외부 연결(external linkage)을 가지는 변수는 여러 파일에서 사용할 수 있습니다.
    내부 연결(internal linkage)을 가지는 변수는 하나의 파일에서만 사용할 수 있습니다.
    함수 내에서 선언된 변수는 연결을 가지지 않습니다.

1. 자동 변수(automatic variable)
    가장 많이 사용하는 변수로 블록 내에서만 유효성을 가지며, 블록이 종료되면 메모리에서 사라집니다.
    자동 변수는 메모리상의 스택(stack) 영역에 저장되며, 초기화하지 않으면 의미 없는 값(쓰레깃값)으로 초기화됩니다.
    자동 변수는 지역 변수(local variable)와 같은 의미로 사용됩니다.
    함수의 매개변수도 여기에 포함됩니다.

2. 정적 변수(static variable)
    프로그램이 실행되는 내내 유지되는 변수를 의미합니다.
    정적 변수는 메모리상의 데이터(data) 영역에 저장되며, 초기화하지 않으면 0으로 자동 초기화됩니다.

    1) 연결을 가지지 않는 정적 변수
        연결을 가지지 않는 정적 변수는 블록 내부에서 "static" 키워드를 사용하여 정의합니다.
        이러한 연결을 가지지 않는 정적 변수는 지역 변수와 전역 변수의 특징을 모두 가지게 됩니다.
        이 변수는 전역 변수처럼 단 한 번만 초기화되며, 프로그램이 종료되어야 메모리상에서 사라집니다.
        또한 지역 변수처럼 해당 블록 내에서만 접근할 수 있습니다.

    2) 내부 연결을 가지는 정적 변수
        유효 범위를 변환 단위로 가지는 변수에 "static" 키워드를 사용하여 정의합니다.
        이 변수는 해당 변수를 포함하고 있는 변환 단위, 즉 현재 파일에서만 사용할 수 있습니다.
        또한 파일 내의 모든 블록에서 접근 및 사용할 수 있습니다.
    
    3) 외부 연결을 가지는 정적 변수
        유효 범위를 변환 단위로 가지는 변수를 의미합니다.
        이러한 외부 연결을 가지는 정적 변수를 전역 변수(global variable) 또는 외부 변수(extern variable)라고 합니다.
        이 변수는 해당 파일뿐만 아니라 외부 파일에서도 사용할 수 있는 변수입니다.
        이러한 외부 변수는 해당 변수를 사용하는 모든 파일에서 각각 extern 키워드를 사용하여 재선언되어야 사용할 수 있습니다.
*/
// Base/9. scope/extern/extern.cpp 파일에서 실행 가능
#include <iostream>
int extern_var; // 외부 변수 정의
static int var; // 내부 연결을 가지는 정적 변수
void externFunc();

int Function()
{
    int num = 1; // 자동 변수 
    std::cout << "Function 함수 안 num: " << num << std::endl;
    num++;
    var++;
}
int StaticVar()
{
    static int num = 1; // 정적 변수
    std::cout << "StaticVar 함수 안 num: " << num << std::endl;
    num++;
    var++;
}

int main()
{
    
    int num = 0; // 자동 변수 
    std::cout << "main 함수 안 num: " << num << std::endl;
    {
        int var = 10;
        int num = 2; // 자동 변수 
        std::cout << "괄호 안 num: " << num << std::endl;
        std::cout << "괄호 안 var: " << var << std::endl;
    }

    for (int i = 0; i < 3; i++)
    {
        Function();
        StaticVar();
    }
    std::cout << "내부 연결을 가지는 정적 변수 var: " << var << std::endl;
    // std::cout << "외부 연결을 가지는 정적 변수 extern_var: " << extern_var << std::endl;
    externFunc();
}

