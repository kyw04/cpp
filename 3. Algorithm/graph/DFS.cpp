/*
깊이 우선 탐색(DFS, Depth-First Search)
*/
#include "../Graph.hpp"
#include <iostream>
#include <set>
#include <stack>

template <typename T>
std::vector<unsigned> DFS(Graph<T> G, unsigned start)
{
    std::stack<unsigned> s;
    std::set<unsigned> visited;
    std::vector<unsigned> visit_order;
    
    s.push(start);
    while (!s.empty())
    {
        unsigned current_vertex = s.top();
        s.pop();

        if (visited.find(current_vertex) == visited.end())
        {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            for (auto& e : G.GetEdges(current_vertex))
            {
                if (visited.find(e.dst) == visited.end())
                {
                    s.push(e.dst);
                }
            }
        }
    }

    return visit_order;
}


int main()
{
    Graph<unsigned> g = GetReferenceGraph<unsigned>();

    std::vector<unsigned> result = DFS<unsigned>(g, 1);
    for (auto& v : result)
        std::cout << v << std::endl;

    return 0;
}