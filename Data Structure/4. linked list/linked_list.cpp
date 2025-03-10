/*
연결 리스트 (Linked list)
    연결 리스트는 데이터들을 명시적으로 연결하는 구조입니다.
    각 데이터를 노드라고 부르며, 노드는 데이터와 다음 노드를 가리키는 포인터로 구성됩니다.
    각 노드들은 메모리 상에 랜덤하게 배치되며, 다음 노드를 가리키는 포인터를 통해 순차적으로 데이터에 접근할 수 있습니다.
    연결 리스트는 배열과 달리 데이터를 순차적으로 저장하지 않기 때문에 데이터의 삽입과 삭제가 용이합니다.
    하지만 데이터에 접근할 때마다 포인터를 통해 다음 노드를 찾아야 하기 때문에 배열에 비해 느립니다.
    
    시간 복잡도
    추가: O(1)
    삭제: O(1)
    접근: O(n)
    검색: O(n)
*/
#include <iostream>

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList()
    {
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void PushBack(int _value)
    {
        Node* new_node = new Node({ _value, nullptr });

        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        
        tail->next = new_node;
        tail = new_node;
    }

    void Insert(int _index, int _value)
    {
        Node* new_node = new Node({ _value, nullptr });

        if (_index == 0)
        {
            new_node->next = head;
            head = new_node;
            return;
        }

        Node* current = head;
        for (int i = 0; i < _index - 1; i++)
        {
            if (current == nullptr)
            {
                return;
            }
            current = current->next;
        }

        if (current == nullptr)
        {
            return;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    void Remove(int _value)
    {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr)
        {
            if (current->data == _value)
            {
                if (prev == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    int operator[](int _index)
    {
        Node* current = head;
        for (int i = 0; i < _index; i++)
        {
            if (current == nullptr)
            {
                return -1;
            }
            current = current->next;
        }
        return current->data;
    }

    int GetSize()
    {
        Node* current = head;
        int size = 0;
        while (current != nullptr)
        {
            size++;
            current = current->next;
        }
        return size;
    }
};

int main()
{
    LinkedList list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);
    list.PushBack(5);

    list.Remove(3);

    list.Insert(2, 6);

    for (int i = 0; i < list.GetSize(); i++)
    {
        std::cout << list[i] << std::endl;
    }

    return 0;
}