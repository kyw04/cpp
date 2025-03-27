/*
벨만 포드 알고리즘(Bellman-Ford)
*/
#include "../Graph.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define UNKNOWN __INT_MAX__

std::vector<int> BellmanFord(const Graph<int>& g, int src)
{
    unsigned v = g.GetVertices();
    std::vector<int> distnace(v, UNKNOWN);
    distnace[src] = 0;

    for (unsigned i = 0; i < v - 1; i++)
    {
        for (auto& e : g.GetEdges())
        {
            if (distnace[e.src] == UNKNOWN) { continue; }

            distnace[e.dst] = std::min(distnace[e.dst], distnace[e.src] + e.weight);
        }
    }

    return distnace;
}

int main()
{
    unsigned V = 5;
    Graph<int> G(V + 1);
    std::vector<Edge<int>> edge_map
    {
        { 1, 2, 3 },
        { 2, 3, 5 },
        { 2, 4, 10 },
        { 4, 3, -7 },
        { 3, 5, 2 }
    };

    for (auto& e : edge_map)
    {
        std::printf("%u, %u, %d\n", e.src, e.dst, e.weight);
        G.AddEdge(Edge<int>{ e.src, e.dst, e.weight });
    }

    int src = 1;
    std::vector<int> result = BellmanFord(G, src);

    std::cout << "[" << src << "번 정점으로부터 최소 거리]" << std::endl;
    for (int i = 1; i <= V; i++)
    {
        std::cout << i << "번 정점: ";
        
        if (result[i] != UNKNOWN)
            std::cout << result[i] << std::endl;
        else
            std::cout << "방문하지 않음." << std::endl;
    }

    return 0;
}