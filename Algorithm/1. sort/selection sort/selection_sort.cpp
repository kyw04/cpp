/*
선택 정렬(Selection Sort)
    선택 정렬은 첫 번째부터 마지막 값 중 가장 작은 값을 찾아 첫 번째 자리에 넣고
    두 번째부터 마지막 값 중 가장 작은 값을 찾아 두 번째 자리에 넣는 식으로 진행 되는 알고리즘입니다.

    어떻게 정렬되어 있든 O(n^2)의 시간이 소요 됩니다.
    버블 정렬보다 두 배 정도 빠릅니다.
*/
#include <iostream>

void SelectionSort(int _array[], int _len)
{
    int min_index = 0;
    for (int i = 0; i < _len - 1; i++)
    {
        for (int j = i + 1; j < _len; j++)
        {
            if (_array[min_index] > _array[j])
            {
                min_index = j;
            }
        }

        int temp = _array[i];
        _array[i] = _array[min_index];
        _array[min_index] = temp;
    }
}

int main()
{
int arr[] = { 7, 4, 6, 3, 8, 0, 9, 2, 5, 1 };
        
    for (auto& a : arr) { std::cout << a << " "; }
    std::cout << std::endl;
    
    SelectionSort(arr, 10);
    for (auto& a : arr) { std::cout << a << " "; }
    std::cout << std::endl;

    return 0;
}