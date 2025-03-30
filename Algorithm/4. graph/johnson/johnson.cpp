/*
존슨 알고리즘(Johnson's Algorithm)
    다익스트라 알고리즘과 벨만-포드 알고리즘을 활용하여 모든 정점 사이의 최단 경로를 구하는 알고리즘입니다.
    이 알고리즘은 음수 가중치를 갖는 그래프에서도 올바른 결과을 반환합니다.
*/
#include "../Graph.hpp"
#include <limits>

template <typename T>
const T UNKNOWN = std::numeric_limits<T>::max();


template <typename T>
bool HasNegativeCycle(std::vector<Edge<T>> edges, std::vector<T> distance)
{
    for (auto& e : edges)
    {
        if (distance[e.src] == UNKNOWN<T>) { continue; }

        if (distance[e.src] + e.weight < distance[e.dst])
            return true;
    }

    return false;
}

template <typename T>
std::vector<T> BellmanFord(std::vector<Edge<T>> edges, std::size_t v)
{
    std::vector<T> distance(v + 1, UNKNOWN<T>);
    unsigned s = v;
    for (std::size_t i = 1; i < v; i++)
    {
        edges.push_back(Edge<T>{ s, i, 0 });
    }
    distance[s] = 0;

    for (std::size_t i = 1; i < v; i++)
    {
        for (auto& e : edges)
        {
            if (distance[e.src] == UNKNOWN<T>) { continue; }

            distance[e.dst] = std::min(distance[e.dst], distance[e.src] + e.weight);
        }
    }
    
    if (HasNegativeCycle(edges, distance))
    {
        std::cout << "[음수 가중치 발견]" << std::endl;
        return { };
    }

    return distance;
}

template <typename T>
std::size_t GetMinDistance(std::vector<T> distance, std::vector<bool> visited)
{
    T min_distance = UNKNOWN<T>;
    std::size_t min_index = 0;

    for (std::size_t i = 0; i < distance.size(); i++)
    {
        if (!visited[i] && distance[i] <= min_distance)
        {
            min_distance = distance[i];
            min_index = i;
        }
    }

    return min_index;
}

template <typename T>
std::vector<T> Dijkstra(Graph<T> g, unsigned src)
{
    std::size_t v = g.GetVertices();
    std::vector<T> distance(v, UNKNOWN<T>);
    std::vector<bool> visited(v, false);
    distance[src] = 0;

    for (std::size_t i = 0; i < v - 1; i++)
    {
        std::size_t current = GetMinDistance(distance, visited);
        visited[current] = true;

        for (auto& e : g.GetEdges())
        {
            if (e.src != current || visited[e.dst]) { continue; }

            if (distance[current] != UNKNOWN<T>)
            {
                distance[e.dst] = std::min(distance[e.dst], distance[current] + e.weight);
            }
        }
    }

    return distance;
}

template <typename T>
std::vector<T> Johnson(Graph<T> g)
{
    std::size_t v = g.GetVertices();
    std::vector<T> h = BellmanFord(g.GetEdges(), v);

    if (h.empty())
        return { };

    Graph<T> plus_g(v);
    for (auto& e : g.GetEdges())
    {
        plus_g.AddEdge(Edge<T>{ e.src, e.dst, e.weight + h[e.src] - h[e.dst] });
    }

    std::vector<std::vector<T>> shortest(v);
    for (std::size_t i = 1; i < v; i++)
    {
        shortest[i] = Dijkstra(plus_g, i);
    }

    for (std::size_t i = 1; i < v; i++)
    {
        std::cout << i << ":\n";
        for (std::size_t j = 1; j < v; j++)
        {
            if (shortest[i][j] != UNKNOWN<T>)
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