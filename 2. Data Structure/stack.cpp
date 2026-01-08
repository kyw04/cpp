/*
스택(stack)
    가장 마지막에 들어온 자료가 가장 먼저 나가는 자료구조입니다.
    후입 선출, LIFO(Last-In, First-Out)라고 합니다.
    스택에 자료를 추가할 때를 push, 빼낼 때를 pop이라고 합니다.

    스택은 배구니 안에 책들이 쌓여있는 상황을 생각해 보면 쉽게 이해할 수 있습니다.
    가장 마지막에 넣은 책을 가장 먼저 빼내야 다음 책을 꺼낼 수 있는 것 처럼 동작합니다.

    시간 복잡도
    추가: O(1)
    삭제: O(1)
    접근: O(1)
    검색: O(n)
*/
#include <iostream>

class Stack
{
private:
    int* data;
    int top;
    int max_size;

public: 
    Stack(int _max_size)
    {
        data = new int[_max_size];
        top = 0;
        max_size = _max_size;
    }
    ~Stack() { delete[] data; }

    bool IsEmpty() { return top <= 0; }
    bool IsFull() { return top >= max_size; }
    void Push(int _value)
    {
        if (!IsFull())
            data[top++] = _value;
        else
            std::cout << "스택이 가득 찼습니다." << std::endl;
    }
    int Pop()
    {
        if (!IsEmpty())
            return data[--top];
        
        std::cout << "스택이 비어있습니다." << std::endl;
        return -1;
    }
    int Top()
    {
        if (!IsEmpty())
            return data[top - 1];
    
        std::cout << "스택이 비어있습니다." << std::endl;
        return -1;
    }
};

int main()
{
    Stack s(5);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Push(6); // 스택이 가득 찼기 때문에 들어가지 않음

    std::cout << s.Pop() << std::endl;
    std::cout << s.Pop() << std::endl;
    std::cout << s.Pop() << std::endl;
    std::cout << s.Pop() << std::endl;
    std::cout << s.Pop() << std::endl;
    std::cout << s.Pop() << std::endl;

    return 0;
}