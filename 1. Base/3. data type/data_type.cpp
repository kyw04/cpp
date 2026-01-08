/*
기본적으로 컴퓨터는 0과 1로만 데이터를 판단할 수 있기 때문에 내부 시스템은 2진수(binary)로 구성되있습니다.
bit는 0 혹은 1을 나타내는 하나의 칸을 의미합니다.
byte는 bit들이 8개가 모여있는 그룹을 의미합니다. 

자료형(types)
    기본 자료형과 상용자 정의 자료형으로 나눌 수 있습니다.

기본 자료형
    bool (boolean, 1 byte)
        참(true) 또는 거짓(false)을 저장할 수 있는 자료형입니다.
        c++ 조건문에서 0이 아니라면 모두 참입니다.
        (<=, >, < ...)비교 연산자의 반환값은 모두 bool 값입니다.
    
    char (character, 1 byte)
        문자를 저장할 수 있는 자료형입니다.
        1byte 수치 자료이지만 ASCII 코드에 대응되는 문자 정보로 표현할 수 있습니다.

    wchar_t (wide character, 4 byte)
        문자를 저장할 수 있는 자료형입니다.    
        UTF-8을 지원하며 국제화 문자를 다룰 수 있습니다.
        하나의 문자를 저장하는데 4 byte를 사용합니다.

    int (integer, 4 byte)
        정수를 저장할 수 있는 자료형입니다.
        2의 보수(two's complement)를 이용해 음수 값을 표현합니다.
        정수 자료형의 최상위 bit이 부호(sign)이지만,
        unsigned를 함께 사용하면 자연수(natural numbers)만 사용할 수 있는 정수형 변수를 만들 수 있습니다.

    long (32 bit system: 4 byte, 64 bit system: 8 byte) / long long (8 byte)
        정수를 저장할 수 있는 자료형입니다.
        int 자료형보다 더 큰 값을 저장할 수 있는 자료형입니다.
        
    float (floating point, 4byte)
        실수를 저장할 수 있는 자료형입니다.
        부동소수점 방식을 사용하는 자료형입니다.
        부동소수점 방식은  소수점이 떠다닌다는 의미로 자료형 처리에 있어 소수점 위치가 바뀐다는 것입니다.
        유효숫자를 나타내는 가수부와 소수점의 위치를 풀이하는 지수부로 나누어 표현합니다.

    double (double precision floating point, 8 byte)
        실수를 저장할 수 있는 자료형입니다.
        부동소수점 방식을 사용하는 자료형입니다.
        float 보다 정밀도가 높다는 장점이 있습니다. 하지만 float의 2배의 공간을 사용합니다.

    void
        타입이 없음을 의미합니다.
*/
#include <iostream>

int main()
{
// wcout을 다양한 환경에서 사용하기 위한 전처리 과정.
#ifdef linux
    setlocale(LC_ALL, "ko_KR.utf8");
#elif WIN32
    std::locale::global(std::locale("kor"));
#else
	setlocale(LC_ALL, "");
#endif

    bool b = true;
    char c = 65;
    wchar_t wc = L'가'; // linux + gcc 3.4 이전 버전은 제대로 지원하지 못함.
    int i = 10;
    long l = 100l;
    long long ll = 1000l;
    float f = 3.15f;
    double d = 3.1415926535;

    std::cout << "boolean: " << b << std::endl;
    std::cout << "character: " << c << std::endl;
    std::wcout << L"wid character: " << wc << std::endl; // wcout과 cout을 혼합하여 사용하면 정의되지 않은 동작이 발생할 수 있음.
    std::cout << "integer: " << i << std::endl;
    std::cout << "long: " << l << std::endl;
    std::cout << "long long: " << ll << std::endl;
    std::cout << "floating point: " << f << std::endl;
    std::cout << "double precision floating point: " << d << std::endl;

    return 0;
}