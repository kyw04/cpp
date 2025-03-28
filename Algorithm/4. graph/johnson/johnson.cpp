/*
존슨 알고리즘(Johnson's Algorithm)
    다익스트라 알고리즘과 벨만-포드 알고리즘을 활용하여 모든 정점 사이의 최단 경로를 구하는 알고리즘입니다.
    이 알고리즘은 음수 가중치를 갖는 그래프에서도 올바른 결과을 반환합니다.
*/
#include "../Graph.hpp"
#include "../dijkstra/dijkstra.hpp"
#include "../bellman ford/bellman_ford.hpp"

template <typename T>
std::vector<T> Johnson(Graph<T> g)
{
    std::size_t src = 1;
    std::vector<T> h = BellmanFord(g, src);

    if (h.empty())
        return { };

    for (auto& e : g.GetEdges())
    {
        e.weight += h[e.src] - h[e.dst];
    }

    std::size_t v = g.GetVertices();
    std::vector<Graph<T>> shortest(v);
    for (std::size_t i = 0; i < v; i++)
    {
        shortest[i] = Dijkstra(g, 1, i + 1);
    }

    for (std::size_t i = 0; i < v; i++)
    {
        std::cout << i << ":\n";
        for (std::size_t j = 0; j < v; i++)
        {
            if (shortest[i][j] != UNKNOWN)
            {
                shortest[i][j] += h[j] - h[i];

                std::cout << "\t" << j << ": " << shortest[i][j] << std::endl;
            }
        }
    }
}

int main()
{
    Graph<int> G(6);

    std::vector<Edge<int>> edge_map
    {
        { 1, 2, -7 },
        { 2, 3, -2 },
        { 3, 1, 10 },
        { 1, 4, -5 },
        { 1, 5, 2 },
        { 4, 5, 4 }
    };

    for (auto& e : edge_map)
    {
        G.AddEdge(Edge<int>{ e.src, e.dst, e.weight });
    }

    Johnson(G);

    return 0;
}