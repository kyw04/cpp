/*
다익스트라(Dijkstra)
    다익스트라 알고리즘은 음수 가중치가 없는 그래프에서 동작하는 최단 경로 알고리즘입니다.

*/
#include "dijkstra.hpp"
#include <iostream>

int main()
{
    Graph<unsigned> g = GetReferenceGraph<unsigned>();
    std::vector<unsigned> result = Dijkstra(g, 1, 6);

    std::cout << "[1번과 6번 정점 사이의 최단 경로]" << std::endl;
    for (auto& v : result)
    {
        std::cout << v << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
