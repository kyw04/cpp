/*
트리(Tree)
    트리는 계층적인 구조를 표현하는 자료구조로, 노드(node)와 간선(edge)으로 구성됩니다.
    노드는 데이터를 저장하는 단위로, 간선은 노드와 노드를 연결하는 선입니다.
    트리는 비순환적인 그래프로, 노드와 간선으로 구성되어 있습니다.
    트리는 계층적인 구조로, 노드는 부모-자식 관계로 연결되어 있습니다.
    트리는 하나의 루트 노드를 가지며, 루트 노드에서 다른 노드로 가는 경로가 유일합니다.
    트리의 노드는 0개 이상의 자식 노드를 가질 수 있습니다.
    트리의 노드는 1개 이상의 부모 노드를 가질 수 없습니다.
    트리의 노드는 순환하지 않습니다.

    루트 노드(root node)는 부모가 없는 노드로, 트리의 시작점을 나타냅니다.
    리프 노드(leaf node)는 자식이 없는 노드로, 트리의 끝을 나타냅니다.
    노드의 깊이(depth)는 루트 노드에서 해당 노드까지의 거리를 나타내며, 루트 노드의 깊이는 0입니다.
    노드의 레벨(level)은 깊이에 1을 더한 값입니다.
    노드의 높이(height)는 해당 노드에서 리프 노드까지의 거리 중 가장 긴 것을 나타냅니다.
    노드의 차수(degree)는 해당 노드의 자식 노드의 개수를 나타냅니다.
    트리의 차수는 트리에 있는 노드의 차수 중 가장 큰 값입니다.
    트리의 크기(size)는 트리에 있는 노드의 개수를 나타냅니다.
*/
#include <iostream>
#include <list>
#include <queue>

struct Node
{
    int data;
    Node* parent;
    std::list<Node*> children;
};

class Tree
{
private:
    Node* root;

public:
    Tree()
    {
        root = nullptr;
    }
    ~Tree()
    {
        Delete(root);
    }

    void Push(Node* _parent, int _value)
    {
        Node* new_node = new Node({ _value, _parent, {} });

        if (_parent == nullptr)
        {
            root = new_node;
            return;
        }

        _parent->children.push_back(new_node);
    }

    void Delete(Node* _node)
    {
        if (_node == nullptr || _node->children.empty())
        {
            return;
        }

        for (Node* child : _node->children)
        {
            Delete(child);
        }

        _node->parent->children.remove(_node);
        delete _node;
    }

    Node* GetRoot()
    {
        return root;
    }
    
    void Print()
    {
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* current = q.front();
            q.pop();

            std::cout << current->data << std::endl;

            for (Node* child : current->children)
            {
                q.push(child);
            }
        }
    }
};

int main()
{
    Tree tree;
    tree.Push(nullptr, 1);
    tree.Push(tree.GetRoot(), 2);
    tree.Push(tree.GetRoot(), 3);
 
    auto target = tree.GetRoot()->children.begin();
    tree.Push(*target, 4);
    target++;
    tree.Push(*target, 5);

    tree.Delete(*target);

    tree.Print();

    return 0;
}