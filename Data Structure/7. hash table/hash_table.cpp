/*
해시테이블(HashTable)
    해시테이블은 키(Key)에 대한 해시값(Hash Value)을 계산하여 배열(Array)의 인덱스로 사용하는 자료구조입니다.
    키(Key)를 해시함수(Hash Function)를 통해 해시값(Hash Value)으로 변환한 후, 이 해시값을 배열(Array)의 인덱스로 사용하여 값을 저장하거나 조회합니다.
    해시테이블은 배열(Array)을 사용하기 때문에 배열(Array)의 특성을 그대로 가지고 있습니다.

해시함수(Hash Function)
    임의의 길이의 데이터를 고정된 길이의 데이터로 매핑하는 함수입니다.
    해시함수는 해시테이블에서 키(Key)를 해시값(Hash Value)으로 변환하는 역할을 합니다.
    해시함수는 해시충돌(Hash Collision)을 최소화하고, 해시값(Hash Value)을 균등하게 분포시키는 것이 중요합니다.

해시충돌(Hash Collision)
    서로 다른 키(Key)에 대해 같은 해시값(Hash Value)이 나오는 경우를 말합니다.
    해시충돌이 발생하면 두 개 이상의 키(Key)가 동일한 인덱스에 저장되는데,
    이를 해결하기 위한 방법으로는 개방주소방식(Open Addressing)과 체이닝(Chaining)이 있습니다.

개방주소방식(Open Addressing)
    해시충돌이 발생하면 다른 빈 버킷(Bucket)을 찾아서 저장하는 방식입니다.
    선형조사(Linear Probing), 이차조사(Quadratic Probing), 이중해싱(Double Hashing) 등이 있습니다.

체이닝(Chaining)
    해시충돌이 발생하면 같은 해시값(Hash Value)을 가지는 키(Key)를 연결리스트(Linked List)로 연결하는 방식입니다.
    해시충돌이 발생해도 다른 버킷(Bucket)을 찾을 필요가 없어서 개방주소방식(Open Addressing)보다 간단하고 효율적입니다.
*/
#include <iostream>

class HashTable
{
private:
    static const int SIZE = 10;
    struct Node
    {
        int key;
        int value;
        Node* next;
    };

    Node* table[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = nullptr;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node* current = table[i];
            Node* next = nullptr;
            while (current != nullptr)
            {
                next = current->next;
                delete current;
                current = next;
            }
        }
    }

    int Hash(int _key)
    {
        return _key % SIZE;
    }

    void Insert(int _key, int _value)
    {
        int index = Hash(_key);
        Node* new_node = new Node({ _key, _value, nullptr });

        if (table[index] == nullptr)
        {
            table[index] = new_node;
            return;
        }

        Node* current = table[index];
        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = new_node;
    }

    int Search(int _key)
    {
        int index = Hash(_key);
        Node* current = table[index];
        while (current != nullptr)
        {
            if (current->key == _key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    void Remove(int _key)
    {
        int index = Hash(_key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == _key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
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
};

int main()
{
    HashTable hash_table;
    hash_table.Insert(1, 10);
    hash_table.Insert(2, 20);
    hash_table.Insert(3, 30);
    hash_table.Insert(4, 40);
    hash_table.Insert(5, 50);

    hash_table.Remove(3);

    std::cout << hash_table.Search(1) << std::endl;
    std::cout << hash_table.Search(3) << std::endl;

    return 0;
}