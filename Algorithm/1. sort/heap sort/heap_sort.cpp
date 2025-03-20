/*
힙 정렬(Heap Sort)

*/
#include <iostream>
#define MAX 10

class Heap
{
private:
    int data[MAX + 1];
    int size;

public:
    Heap() : size(0) { }
    ~Heap() { }

    bool IsEmpty() { return size; }
    void Push(int _value)
    {
        int i;
        for (i = ++size; i > 1 && _value < data[i / 2]; i /= 2)
        {
            data[i] = data[i / 2];
        }

        data[i] = _value;
    }
    int Pop()
    {
        int temp = data[1];
        int last = data[size--];
        int i = 2;
        while (i <= size)
        {
            if (i < size && data[i] > data[i + 1]) { i++; }
            if (last <= data[i]) { break; }

            data[i / 2] = data[i];
            i *= 2;
        }

        data[i / 2] = last;
        return temp;
    }
};

void HeapSort(int _array[], int _len)
{
    Heap h;
    for (int i = 0; i < _len; i++)
    {
        h.Push(_array[i]);
    }

    for (int i = 0; i < _len; i++)
    {
        _array[i] = h.Pop();
    }
}

int main()
{
    int arr[MAX] = { 7, 4, 6, 3, 8, 0, 9, 2, 5, 1 };
        
    for (auto& a : arr) { std::cout << a << " "; }
    std::cout << std::endl;
    
    HeapSort(arr, MAX);
    for (auto& a : arr) { std::cout << a << " "; }
    std::cout << std::endl;

    return 0;
}