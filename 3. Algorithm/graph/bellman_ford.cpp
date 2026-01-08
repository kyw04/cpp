/*
벨만 포드 알고리즘(Bellman-Ford)
*/
#include "bellman_ford.hpp"
#include <iostream>

int main()
{
    unsigned V = 6;
    Graph<int> G(V);
    std::vector<Edge<int>> edge_map
    { // 가중치 싸이클이 있는 그래프
        { 1, 2, 3 },
        { 2, 4, -8 },
        { 3, 2, 3 },
        { 3, 6, 5 },
        { 4, 3, 3 },
        { 3, 5, 2 },
        { 5, 6, -1 },
        { 6, 2, 8 }
    };
    // { // 가중치 싸이클이 없는 그래프
    //     { 1, 2, 3 },
    //     { 2, 3, 5 },
    //     { 2, 4, 10 },
    //     { 4, 3, -7 },
    //     { 3, 5, 2 }
    // };

    for (auto& e : edge_map)
    {
        G.AddEdge(Edge<int>{ e.src, e.dst, e.weight });
    }

    std::size_t src = 1;
    std::vector<int> result = BellmanFord(G, src);

    if (!result.empty())
        std::cout << "[" << src << "번 정점으로부터 최소 거리]" << std::endl;
    for (std::size_t i = 1; i < V; i++)
    {
        std::cout << i << "번 정점: ";
        
        if (result[i] != UNKNOWN)
            std::cout << result[i] << std::endl;
        else
            std::cout << "방문하지 않음." << std::endl;
    }



    return 0;
}