/*
버블 정렬(Bubble Sort)
    서로 인접한 두 원소를 검사하여 정렬하는 알고리즘입니다.
    1번째와 2번째 원소를 비교하여 정렬하고, 2번째와 3번째, ..., n-1번째와 n번째를 정렬한 뒤 다시 처음으로 돌아가 이번에는 n-2번째와 n-1번째까지 정렬하는 알고리즘입니다.

    거의 모든 상황에서 최악의 성능을 가집니다.
    최악의 경우 O(n^2)의 시간이 소요됩니다.
    이미 정렬된 자료의 경우 O(n)의 시간이 소요됩니다.
*/
#include <iostream>

void BubbleSrot(int _array[], int _len)
{
    for (int i = 0; i < _len - 1; i++)
    {
        for (int j = 0; j < _len - i - 1; j++)
        {
            if (_array[j] > _array[j + 1])
            {
                int temp = _array[j];
                _array[j] = _array[j + 1];
                _array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = { 7, 4, 6, 3, 8, 0, 9, 2, 5, 1 };
        
    for (auto& a : arr) { std::cout << a << " "; }
    std::cout << std::endl;
    
    BubbleSrot(arr, 10);
    for (auto& a : arr) { std::cout << a << " "; }
    std::cout << std::endl;

    return 0;
}