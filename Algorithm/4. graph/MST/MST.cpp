/*
최소 신장 트리(MST)

*/
#include "../Graph.hpp"
#include <iostream>
#include <limits>
#include <queue>
#include <set>

template <typename T>
struct Lable
{
    unsigned ID;
    T distance;

    inline bool operator>(const Lable<T> other) const
    {
        return this->distance > other.distance; 
    }
};

template <typename T>
std::vector<unsigned> prim_MST(Graph<T> G, unsigned src)
{
    std::priority_queue<Lable<T>, std::vector<Lable<T>>, std::greater<Lable<T>>> heap;
    std::vector<T> distance(G.GetVertices(), std::numeric_limits<T>::max());

    std::set<unsigned> visited;
    std::vector<unsigned> MST;

    heap.emplace(Lable<T>{ src, 0 });
    while (!heap.empty())
    {
        Lable<T> current_vertex = heap.top();
        heap.pop();

        if (visited.find(current_vertex.ID) == visited.end())
        {
            MST.push_back(current_vertex.ID);
            visited.insert(current_vertex.ID);

            for (auto& e : G.GetEdges(current_vertex.ID))
            {
                auto neighbor = e.dst;
                auto new_distance = e.weight;

                if (new_distance < distance[neighbor])
                {
                    heap.emplace(Lable<T>{ neighbor, new_distance });
                    distance[neighbor] = new_distance;
                }
            }
        }
    }

    return MST;
}

int main()
{
    Graph<unsigned> g = GetReferenceGraph<unsigned>();

    std::vector<unsigned> MST = prim_MST<unsigned>(g, 1);
    
    std::cout << "[최소 신장 트리]" << std::endl;
    for (auto& v : MST)
    {
        std::cout << v << std::endl;
    }
    std::cout << std::endl;

    return 0;
}