/*

함수 포인터(functino pointer)
    프로그램에서 정의된 함수는 프로그램이 실행될 때 모두 메인 메모리에 올라갑니다.
    이때 함수의 이름은 메모리에 올라간 함수의 시작 주소를 가리키는 포인터 상수(constant pointer)가 됩니다.
    이렇게 함수의 시작 주소를 가리키는 포인터 상수를 함수 포인터(function pointer)라고 부릅니다.

    void Func(int, int); => void (*ptr_func)(int, int);
*/
#include <iostream>

double Add(double a, double b) { return a + b; }
double Sub(double a, double b) { return a - b; }
double Mul(double a, double b) { return a * b; }
double Div(double a, double b) { return a / b; }

int main()
{
    double (*calc)(double, double) = NULL;
    double num1 = 1, num2 = 3;
    char oper;
    std::cin >> oper;

    switch (oper)
    {
        case '+' :
            calc = Add;
            break;
        case '-':
            calc = Sub;
            break;
        case '*':
            calc = Mul;
            break;
        case '/':
            calc = Div;
            break;
        default:
            std::cout << "사칙연산(+, -, *, /)만을 지원합니다.";
            break;
    }

    std::cout << calc(num1, num2) << std::endl;

    return 0;
}