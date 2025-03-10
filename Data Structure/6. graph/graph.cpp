/*
그래프(Graph)
    그래프는 정점(Vertex)과 간선(Edge)으로 이루어진 자료구조입니다.
    그래프는 노드와 노드 사이의 연결 관계를 표현할 때 사용합니다.
    그래프는 노드와 노드 사이의 관계를 나타내는 방식에 따라 방향 그래프(Directed Graph)와 무방향 그래프(Undirected Graph)로 나뉩니다.

    1. 방향 그래프(Directed Graph)
        - 간선에 방향이 존재하는 그래프
        - 노드 i에서 노드 j로 가는 간선이 존재한다면 노드 i와 노드 j는 연결되어 있다고 표현
        - 노드 i에서 노드 j로 가는 간선이 존재한다고 해서 노드 j에서 노드 i로 가는 간선이 존재하지 않을 수 있음
    2. 무방향 그래프(Undirected Graph)
        - 간선에 방향이 존재하지 않는 그래프
        - 노드 i와 노드 j가 연결되어 있다면 노드 j와 노드 i도 연결되어 있다고 표현
        - 노드 i와 노드 j가 연결되어 있다고 표현하면 노드 j와 노드 i도 연결되어 있다고 표현

    그래프는 두 가지 방식으로 표현할 수 있습니다.
        1. 인접 행렬(Adjacency Matrix)
            - 2차원 배열을 사용하여 노드들 간의 관계를 표현하는 방식
            - 노드 i에서 노드 j로 가는 간선이 존재하면 adj[i][j] = 1, 없으면 adj[i][j] = 0
            - 무방향 그래프의 경우 adj[i][j] = adj[j][i] = 1
            - 장점: 노드 i와 노드 j가 연결되어 있는지 확인하는 시간복잡도가 O(1)
            - 단점: 노드의 개수가 많을 경우 메모리 낭비가 심함
        2. 인접 리스트(Adjacency List)
            - 연결 리스트를 사용하여 노드들 간의 관계를 표현하는 방식
            - 노드 i와 연결된 노드들을 리스트로 관리
            - 무방향 그래프의 경우 노드 i와 연결된 노드 j를 추가할 때 동시에 노드 j와 연결된 노드 i도 추가
            - 장점: 메모리를 효율적으로 사용
            - 단점: 노드 i와 노드 j가 연결되어 있는지 확인하는 시간복잡도가 O(V) (V: 노드의 개수)
*/
#include <iostream>

class Graph // 인접 행렬 방향 그래프
{
private:
    int** adj;
    int size;

public:
    Graph(int _size)
    {
        size = _size;
        adj = new int* [size];
        for (int i = 0; i < size; i++)
        {
            adj[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                adj[i][j] = 0;
            }
        }
    }
    ~Graph()
    {
        for (int i = 0; i < size; i++)
        {
            delete[] adj[i];
        }
        delete[] adj;
    }

    void AddEdge(int _from, int _to)
    {
        adj[_from][_to] = 1;
    }

    void RemoveEdge(int _from, int _to)
    {
        adj[_from][_to] = 0;
    }

    bool IsConnected(int _from, int _to)
    {
        return adj[_from][_to] == 1;
    }
};

int main()
{
    Graph graph(5);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 4);
    graph.AddEdge(3, 4);

    std::cout << std::boolalpha;
    std::cout << graph.IsConnected(0, 1) << std::endl;
    std::cout << graph.IsConnected(0, 3) << std::endl;

    return 0;
}