/*
너비 우선 탐색(BFS, Breadth-First Search)
*/
#include "../Graph.hpp"
#include <iostream>
#include <queue>
#include <set>

template <typename T>
std::vector<unsigned> BFS(Graph<T> G, unsigned start)
{
    std::queue<unsigned> q;
    std::set<unsigned> visited;
    std::vector<unsigned> visit_order;

    q.push(start);
    while (!q.empty())
    {
        unsigned current_vertex = q.front();
        q.pop();

        if (visited.find(current_vertex) == visited.end())
        {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            for (auto& e : G.GetEdges(current_vertex))
            {
                if (visited.find(e.dst) == visited.end())
                {
                    q.push(e.dst);
                }
            }
        }
    }

    return visit_order;
}

int main()
{
    Graph<unsigned> g = GetReferenceGraph<unsigned>();

    std::vector<unsigned> result = BFS<unsigned>(g, 1);
    for (auto& v : result)
        std::cout << v << std::endl;

    return 0;
}