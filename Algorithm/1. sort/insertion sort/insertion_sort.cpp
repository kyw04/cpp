/*
삽입 정렬(Insertion Sort)
    k 번째 원소를 첫 번째 원소부터 k - 1 번째까지 확인해서
    적절한 위치에 k 번째 원소를 삽입하는 방식으로 정렬해 나가는 알고리즘입니다.

    배열이 작으면 작을 수록 효율적인 알고리즘입니다.
    일반적으로 빠르다고 알려진 알고리즘들도 배열이 작을 경우 삽입 정렬보다 느립니다.

*/
#include <iostream>

void InsertionSort(int _array[], int _len)
{
    for (int i = 0; i < _len; i++)
    {
        for (int j = i + 1; j > 0 && _array[j] < _array[j - 1]; j--)
        {
            std::swap(_array[j], _array[j - 1]);
        }
    }
}

int main()
{
    int arr[10] = { 7, 4, 6, 3, 8, 0, 9, 2, 5, 1 };
        
    for (auto& a : arr) { std::cout << a << " "; }
    std::cout << std::endl;
    
    InsertionSort(arr, 10);
    for (auto& a : arr) { std::cout << a << " "; }
    std::cout << std::endl;

    return 0;
}