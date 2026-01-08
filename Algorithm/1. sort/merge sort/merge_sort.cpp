/*
병합 정렬(Merge Sort)

*/
#include <iostream>
#define MAX 10

void Merge(int _array[], int _left, int _mid, int _right)
{
    int* sorted = new int[_right + 1];
    int k = _left;
    int i = _left;
    int j = _mid + 1;

    while (i <= _mid && j <= _right) { sorted[k++] = _array[i] < _array[j] ? _array[i++] : _array[j++]; }
    for (int l = i; l <= _mid; l++) { sorted[k++] = _array[l]; }
    for (int l = j; l <= _right; l++) { sorted[k++] = _array[l]; }

    for (int l = _left; l <= _right; l++) { _array[l] = sorted[l]; }

    delete[] sorted;
}
void MergeSort(int _array[], int _left, int _right)
{
    if (_left >= _right)
        return;

    int mid = (_left + _right) / 2;
    MergeSort(_array, _left, mid);
    MergeSort(_array, mid + 1, _right);
    Merge(_array, _left, mid, _right);
}

int main()
{
    int arr[MAX] = { 7, 4, 6, 3, 8, 0, 9, 2, 5, 1 };
        
    for (auto& a : arr) { std::cout << a << " "; }
    std::cout << std::endl;
    
    MergeSort(arr, 0, MAX - 1);
    for (auto& a : arr) { std::cout << a << " "; }
    std::cout << std::endl;

    return 0;
}