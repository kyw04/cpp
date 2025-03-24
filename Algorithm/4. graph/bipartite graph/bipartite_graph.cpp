/*
이분 그래프(Bipartite Graph)
    이분 그래프는 정점을 두 개의 집합으로 나눌 수 있는 그래프이며,
    이때 그래프의 모든 간선은 서로 다른 집합에 속한 정점끼리 연결 되어 있는 그래프를 뜻합니다.
*/
#include "../Graph.hpp"
#include <iostream>
#include <queue>
#include <map>
#define RED 1
#define BLACK -1

template <typename T>
bool IsBipartiteGraph(Graph<T> G)
{
    static const int color[] = { BLACK, RED };
    int current_color_index = 1;
    std::queue<unsigned> q;
    std::map<unsigned, int> visited_color;
    
    q.push(1);
    while (!q.empty())
    {
        unsigned current_vertex = q.front();
        q.pop();

        const auto& visited_color_iter = visited_color.find(current_vertex);
        if (visited_color_iter == visited_color.end())
        {
            visited_color.insert({ current_vertex, color[current_color_index] });
            current_color_index = (current_color_index + 1) % 2;

            for (auto& e : G.GetEdges(current_vertex))
            {
                if (visited_color.find(e.dst) == visited_color.end())
                {
                    q.push(e.dst);
                }
            }
        }
        else if (visited_color_iter->second != color[current_color_index])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    Graph<unsigned> g = GetReferenceGraph<unsigned>(GraphType::Bipartite);

    std::cout << std::boolalpha;
    std::cout << IsBipartiteGraph(g) << std::endl;

    return 0;
}