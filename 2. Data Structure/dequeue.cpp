/*
덱(Dequeue)
    덱은 삽입과 삭제를 양방향에서 할 수 있는 자료구조입니다.
    스택과 큐를 합친 자료구조라 볼 수 있습니다.

    시간 복잡도
    추가: O(1)
    삭제: O(1)
    접근: O(1)
    검색: O(n)
*/
#include <iostream>

class Dequeue
{
private:
    int* data;
    int front;
    int back;
    int max_size;
    int count;

public:
    Dequeue(int _size)
    {
        _size++;
        data = new int[_size];
        front = _size / 2;
        back = _size / 2;        
        max_size = _size;
    }
    ~Dequeue() { delete[] data; }

    bool IsEmpty() { return front == back; }
    bool IsFull() { return front == (back + 1) % max_size; }
    
    void PushFront(int _value)
    {
        if (IsFull())
        {
            std::cout << "가득 찼습니다." << std::endl;
            return;
        }

        data[front] = _value;
        front = (front - 1 + max_size) % max_size;
    }
    void PushBack(int _value)
    {
        if (IsFull())
        {
            std::cout << "가득 찼습니다." << std::endl;
            return;
        }
        
        back = (back + 1) % max_size;
        data[back] = _value;
    }

    int PopFront()
    {
        if (IsEmpty())
        {
            std::cout << "비어 있습니다." << std::endl;
            return -1;
        }

        front = (front + 1) % max_size;
        return data[front]; 
    }
    int PopBack()
    {
        if (IsEmpty())
        {
            std::cout << "비어 있습니다." << std::endl;
            return -1;
        }

        int result = data[back];
        back = (back - 1 + max_size) % max_size;
        return result;
    }

};

int main()
{
    Dequeue dequeue(5);

    dequeue.PushFront(1);
    dequeue.PushFront(2);
    dequeue.PushFront(3);
    dequeue.PushBack(4);
    dequeue.PushBack(5);
    dequeue.PushBack(6);

    std::cout << dequeue.PopFront() << std::endl;
    std::cout << dequeue.PopFront() << std::endl;
    std::cout << dequeue.PopFront() << std::endl;
    std::cout << dequeue.PopBack() << std::endl;
    std::cout << dequeue.PopBack() << std::endl;
    std::cout << dequeue.PopBack() << std::endl;

    return 0;
}