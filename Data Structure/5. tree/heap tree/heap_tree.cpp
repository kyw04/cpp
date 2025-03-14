/*
힙 트리(Heap Tree)
    힙 트리는 완전 이진 트리 형태를 띄어야 하고,
    모든 부모의 값이 자식의 값 보다 크거나(최대 힙[max heap]) 작은(최소 힙[min heap]) 자료구조입니다.
    루트 노드에는 항상 데이터들 중 가장 큰 값(혹은 가장 작은 값)이 저장되어 있기 때문에,
    최댓값(혹은 최솟값)을 O(1) 안에 찾을 수 있습니다.

    추가 (최소 힙 기준)
        1. 힙 트리 가장 끝 자리에 노드를 삽입합니다.
        2. 부모 노드와 비교합니다.
        3. 부모 노드가 삽입한 노드보다 클 경우 비교한 노드들을 교환합니다.
        4. 규칙에 맞을 때까지 2, 3번 과정을 반복합니다.

    삭제 (최소 힙 기준)
        * 루트 노드만 제거할 수 있습니다. *
        1. 루트 노드를 제거합니다.
        2. 가장 끝에 있는 노드를 루트 노드를 삽입합니다.
        3. 올라간 노드와 자식 노드들을 비교합니다.
        4. 올라간 노드보다 자식 노드가 작을 경우 비교한 노드들을 교환합니다.
           (자식 노드 두개 모두 올라간 노드보다 작을 경우 자식 노드 중 더 작은 값과 교환합니다.)
        5. 규칙에 맞을 때까지 3, 4번 과정을 반복합니다.

    시간 복잡도
    추가: O(log N)
    삭제: O(log N)
    접근: O(1)
    검색: O(log N)

            3
        5      15
      10   7 20   0
*/
#include <iostream>
#include <queue>

struct Node
{
    int data;
    Node* parent;
    Node* left;
    Node* right;

    Node(int _data) : data(_data), parent(nullptr), left(nullptr), right(nullptr) { }
};

class HeapTree
{
private:
    Node* root;

public:
    HeapTree(Node* _data = nullptr) : root(_data) { }    

    void Insert(int _data)
    {
        Node* new_data = new Node(_data);

        if (root == nullptr)
        {
            root = new_data;
            return;
        }

        std::queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            Node* current_node = q.front();
            q.pop();

            if (!current_node->left)
            {
                new_data->parent = current_node; 
                current_node->left = new_data;
                break;
            }
            q.push(current_node->left);

            if (!current_node->right)
            {
                new_data->parent = current_node; 
                current_node->right = new_data;
                break;
            }
            q.push(current_node->right);
        }

        while (new_data->parent && new_data->parent->data > new_data->data)
        {
            int temp = new_data->data;
            new_data->data = new_data->parent->data;
            new_data->parent->data = temp;

            new_data = new_data->parent;
        }
    }

    void Pop() // 작업중
    {
        Node* lsat_node = nullptr;
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            
        }
    }

    int Front()
    {
        return root->data;
    }
};

int main()
{
    HeapTree heap;
    heap.Insert(10);
    heap.Insert(5);
    heap.Insert(20);
    heap.Insert(3);
    heap.Insert(7);
    heap.Insert(15);

    std::cout << heap.Front() << std::endl;
    return 0;
}