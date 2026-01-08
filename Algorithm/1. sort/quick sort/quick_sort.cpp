/*
퀵 정렬(Quick Sort)

*/
#include <iostream>
#include <random>
#define MAX 10

std::random_device rd;
std::mt19937 mt(rd());

void QuickSort(int _array[], int _left, int _right)
{
    if (_left >= _right)
        return;
    
    std::uniform_int_distribution<int> random_value(_left, _right);
    std::swap(_array[_left], _array[random_value(mt)]);
    int left_arrow = _left + 1;
    int right_arrow = _right;
    int pivot = _left;
    bool focused_on_right = true;
    do
    {
        if (focused_on_right)
        {
            if (_array[pivot] >= _array[right_arrow])
            {
                std::swap(_array[pivot], _array[right_arrow]);
                pivot = right_arrow;
                focused_on_right = !focused_on_right;
            }
            right_arrow--;
        }
        else
        {
            if (_array[pivot] <= _array[left_arrow])
            {
                std::swap(_array[pivot], _array[left_arrow]);
                pivot = left_arrow;
                focused_on_right = !focused_on_right;
            }
            left_arrow++;
        }
    } while (left_arrow <= right_arrow);

    QuickSort(_array, _left, pivot - 1);
    QuickSort(_array, pivot + 1, _right);
}

int main()
{
int arr[MAX] = { 7, 4, 6, 3, 8, 0, 9, 2, 5, 1 };
        
    for (auto& a : arr) { std::cout << a << " "; }
    std::cout << std::endl;
    
    QuickSort(arr, 0, MAX - 1);
    for (auto& a : arr) { std::cout << a << " "; }
    std::cout << std::endl;

    return 0;
}