/*
큐(Queue)
    가장 먼저 들어온 자료가 가장 먼저 나가는 자료구조입니다.
    선입 선출, FIFO(First-in, First-out)라고 합니다.
    큐에 자료가 들어오는 곳을 front, 나가는 곳을 rear라고 합니다.
    큐에 자료를 추가할 때를 push, 빼낼 때를 pop이라고 합니다.
    
    시간 복잡도
    추가: O(1)
    삭제: O(1)
    접근: O(1)
    검색: O(n)
*/
#include <iostream>

class Queue
{
private:
    int* data;
    int front;
    int rear;
    int max_size;
    int size;

public:
    Queue(int _max_size)
    {
        data = new int[_max_size];
        front = 0;
        rear = 0;
        max_size = _max_size;
        size = 0;
    }
    ~Queue() { delete data; }

    bool IsEmpty() { return size == 0; }
    bool IsFull() { return size == max_size; }
    void Push(int _value)
    {
        if (!IsFull())
        {
            data[rear] = _value;
            rear = (rear + 1) % max_size;
            size++;
        }
        else
            std::cout << "큐가 가득 찼습니다." << std::endl;
    }
    int Pop()
    {
        if (!IsEmpty())
        {
            int result = data[front];
            front = (front + 1) % max_size;
            size--;

            return result;
        }

        std::cout << "큐가 비어있습니다." << std::endl;
        return -1;
    }
};

int main()
{
    Queue q(5);
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    q.Push(5);
    q.Push(6);

    std::cout << q.Pop() << std::endl;
    std::cout << q.Pop() << std::endl;
    std::cout << q.Pop() << std::endl;
    std::cout << q.Pop() << std::endl;
    std::cout << q.Pop() << std::endl;
    std::cout << q.Pop() << std::endl;

    return 0;
}