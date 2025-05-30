#pragma once
#include "../Graph.hpp"
#include <algorithm>
#include <limits>
#include <queue>
#include <set>

template <typename T>
struct Label
{
    unsigned ID;
    T distance;

    inline bool operator>(const Label<T>& other) const
    {
        return this->distance > other.distance;
    }
};

template <typename T>
auto Dijkstra(const Graph<T>& G, unsigned src, unsigned dst)
{
    std::priority_queue<Label<T>, std::vector<Label<T>>, std::greater<Label<T>>> heap;
    std::vector<T> distance(G.GetVertices(), std::numeric_limits<T>::max());
    std::set<unsigned> visited;
    std::vector<unsigned> parent(G.GetVertices());

    heap.emplace(Label<T>{ src, 0 });
    parent[src] = src;
    while (!heap.empty())
    {
        Label<T> current_vertex = heap.top();
        heap.pop();

        if (current_vertex.ID == dst)
        {
            break;
        }

        if (visited.find(current_vertex.ID) == visited.end())
        {
            visited.insert(current_vertex.ID);

            for (auto& e : G.GetEdges(current_vertex.ID))
            {
                auto neighbor = e.dst;
                auto new_distance = current_vertex.distance + e.weight;

                if (new_distance < distance[neighbor])
                {
                    heap.emplace(Label<T>{ neighbor, new_distance });
                    parent[neighbor] = current_vertex.ID;
                    distance[neighbor] = new_distance;
                }
            }
        }
    }

    std::vector<unsigned> shortest_path;
    auto current_vertex = dst;
    while (current_vertex != src)
    {
        shortest_path.push_back(current_vertex);
        current_vertex = parent[current_vertex];
    }
    shortest_path.push_back(src);
    std::reverse(shortest_path.begin(), shortest_path.end());

    return shortest_path;
}