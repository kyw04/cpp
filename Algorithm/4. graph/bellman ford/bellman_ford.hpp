#pragma once
#include "../Graph.hpp"
#include <algorithm>
#include <vector>
#include <climits>
#define UNKNOWN __INT_MAX__

template <typename T>
std::vector<T> BellmanFord(const Graph<T>& g, std::size_t src)
{
    std::size_t v = g.GetVertices();
    std::vector<int> distance(v, UNKNOWN);
    distance[src] = 0;

    for (std::size_t i = 0; i < v - 1; i++)
    {
        for (auto& e : g.GetEdges())
        {
            if (distance[e.src] == UNKNOWN) { continue; }

            distance[e.dst] = std::min(distance[e.dst], distance[e.src] + e.weight);
        }
    }

    for (auto& e : g.GetEdges())
    {
        if (distance[e.src] == UNKNOWN) { continue; }

        if (distance[e.dst] > distance[e.src] + e.weight)
        {
            std::cout << "[음수 가중치 발견]" << std::endl;
            return {};
        }
    }

    return distance;
}