#include <iostream>

int main()
{
    // 자료형 변수명[행길이][열길이];
    // int arr1[10][10];
    int arr[][3] =
    {
        { 10, 2, 5 },
        { 34, 3, 13 },
        { 1, 2 },
        { 4, 5 }
    };

    unsigned long col = sizeof(arr[0]) / sizeof(arr[0][0]);
    unsigned long low = (sizeof(arr) / col) / sizeof(arr[0][0]);

    std::cout << "열의 길이: " << col << std::endl;
    std::cout << "행의 길이: " << low << std::endl;
    std::cout << arr[2][2] << std::endl;

    return 0;
}