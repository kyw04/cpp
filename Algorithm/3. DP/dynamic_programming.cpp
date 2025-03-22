/*
다이나믹 프로그래밍(Dynamic Programming)
    특정 범위까지의 값을 구하기 위해서 그것과 다른 범위까지의 값을 이용하여 효율적으로 값을 구하는 알고리즘 설계 기법입니다.

*/
#include <iostream>
#define ULL unsigned long long
ULL memo[94] = {0}; // unsigned long long으로 표현할 수 있는 피보나치 수열의 수는 94가 최대이기 때문
ULL Fibonacci(ULL n) // 예시용 피보나치 수열
{
    if (n <= 1) { return n; }
    if (memo[n]) { return memo[n]; }

    return memo[n] = Fibonacci(n - 1) + Fibonacci(n - 2); 
}

int main()
{
    std::cout << Fibonacci(20) << std::endl;
    return 0;
}