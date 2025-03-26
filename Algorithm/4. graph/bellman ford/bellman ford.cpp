/*
벨만 포드 알고리즘(Bellman-Ford)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define UNKNOWN __INT_MAX__

struct Edge
{
    int src;
    int dst;
    int weight;
};

std::vector<int> BellmanFord(const std::vector<Edge>& edges, int v, int src)
{
    std::vector<int> distnace(v, UNKNOWN);
    distnace[src] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        for (auto& e : edges)
        {
            if (distnace[e.src] == UNKNOWN) { continue; }

            distnace[e.dst] = std::min(distnace[e.dst], distnace[e.src] + e.weight);
        }
    }

    return distnace;
}

int main()
{
    int V = 5;
    std::vector<Edge> edges;
    std::vector<std::vector<int>> edge_map
    {
        { 0, 1, 3 },
        { 1, 2, 5 },
        { 2, 1, 5 },
        { 1, 3, 10 },
        { 3, 2, -7 },
        { 2, 4, 2 }
    };

    for (auto& e : edge_map)
    {
        edges.emplace_back(Edge{ e[0], e[1], e[2] });
    }

    int src = 0;
    std::vector<int> result = BellmanFord(edges, V, src);

    std::cout << "[" << src << "번 정점으로부터 최소 거리]" << std::endl;
    for (int i = 0; i < V; i++)
    {
        std::cout << i << "번 정점: ";
        
        if (result[i] != UNKNOWN)
            std::cout << result[i] << std::endl;
        else
            std::cout << "방문하지 않음." << std::endl;
    }

    return 0;
}